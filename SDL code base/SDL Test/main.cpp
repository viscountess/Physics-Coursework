// Based loosly on the first triangle OpenGL tutorial
// http://www.opengl.org/wiki/Tutorial:_OpenGL_3.1_The_First_Triangle_%28C%2B%2B/Win%29
// This program will render two triangles
// Most of the OpenGL code for dealing with buffer objects, etc has been moved to a 
// utility library, to make creation and display of mesh objects as simple as possible

// Windows specific: Uncomment the following line to open a console window for debug output
#if _DEBUG
#pragma comment(linker, "/subsystem:\"console\" /entry:\"WinMainCRTStartup\"")
#endif

#include "rt3d.h"
#include "BasePhysics.h"

#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


BasePhysics * player;

const int s_windowXSize = 1024;
const int s_windowYSize = 768;

Uint32 lastTime = 0;

// Set up rendering context
SDL_Window * setupRC(SDL_GLContext &context) {
	SDL_Window * window;
	SDL_Init(SDL_INIT_EVERYTHING);
	 
    // Create 800x600 window
    window = SDL_CreateWindow("B00256311 - Interactive Physical Modelling Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		s_windowXSize, s_windowYSize, SDL_WINDOW_OPENGL);
	
    context = SDL_GL_CreateContext(window); // Create opengl context and attach to window
    SDL_GL_SetSwapInterval(1); // set swap buffers to sync with monitor's vertical refresh rate


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	return window;
}

void init(void) {

	player = new BasePhysics();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Initialize Modelview Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Initialize clear color
	glClearColor(0.f, 0.f, 0.f, 1.f);
	gluOrtho2D(0, s_windowXSize, 0, s_windowYSize);

	//Check for error
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		printf("Error initializing OpenGL! %s\n", gluErrorString(error));
	}

	lastTime = SDL_GetTicks();
}

void draw(SDL_Window * window) {
	
	//Clear color buffer
	glClear(GL_COLOR_BUFFER_BIT);

	player->draw();
	//Update screen
	SDL_GL_SwapWindow(window);

}

void update()
{
	Uint32 deltaTime = SDL_GetTicks() - lastTime;
	player->update(deltaTime);
	lastTime = SDL_GetTicks();
}


// Program entry point - SDL manages the actual WinMain entry point for us
int main(int argc, char *argv[]) {
    SDL_Window * hWindow; // window handle
    SDL_GLContext glContext; // OpenGL context handle
    hWindow = setupRC(glContext); // Create window and render context 

	// Required on Windows *only* init GLEW to access OpenGL beyond 1.1
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err) { // glewInit failed, something is seriously wrong
		std::cout << "glewInit failed, aborting." << endl;
		exit (1);
	}
	cout << glGetString(GL_VERSION) << endl;

	init();

	bool running = true; // set running to true
	SDL_Event sdlEvent;  // variable to detect SDL events
	while (running)	{	// the event loop
		while (SDL_PollEvent(&sdlEvent)) {
			if (sdlEvent.type == SDL_QUIT)
				running = false;
		}
		update();
		draw(hWindow); // call the draw function
	}

    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(hWindow);
    SDL_Quit();
    return 0;
}