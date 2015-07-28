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
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


BasePhysics * player;

// Set up rendering context
SDL_Window * setupRC(SDL_GLContext &context) {
	SDL_Window * window;
	SDL_Init(SDL_INIT_VIDEO);
	
    // Request an OpenGL 3.0 context.
    // Not able to use SDL to choose profile (yet), should default to core profile on 3.2 or later
	// If you request a context not supported by your drivers, no OpenGL context will be created
	
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE); 

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);  // double buffering on
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4); // Turn on x4 multisampling anti-aliasing (MSAA)
 
    // Create 800x600 window
    window = SDL_CreateWindow("B00256311 - Interactive Physical Modelling Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1500, 1000, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
	
    context = SDL_GL_CreateContext(window); // Create opengl context and attach to window
    SDL_GL_SetSwapInterval(1); // set swap buffers to sync with monitor's vertical refresh rate


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	return window;
}

void init(void) {

	player = new BasePhysics();
}

void draw(SDL_Window * window) {
	// clear the screen
	/* Clear the color and depth buffers. */
	/*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* We don't want to modify the projection matrix. */
	/*glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	// These are deprecated functions. If a core profile has been correctly 
	// created, these commands should compile, but wont render anything
	glColor3f(0.5,1.0,1.0);
	glBegin(GL_TRIANGLES);
		glVertex3f(0.5,0.5,0.0);
		glVertex3f(0.7,0.5,0.0);
		glVertex3f(0.5,0.7,0.0);
	glEnd();

	

    SDL_GL_SwapWindow(window); // swap buffers*/

/*	glClearColor(1.f, 1.f, 1.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glBegin(GL_QUADS);
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0);
	glColor3f(1, 1, 0); glVertex3f(10000, 0, 0);
	glColor3f(1, 0, 1); glVertex3f(10000, 10000, 0);
	glColor3f(1, 1, 1); glVertex3f(0, 10000, 0);
	glEnd();

	player->draw();

	SDL_GL_SwapWindow(window);
	SDL_UpdateWindowSurface(window);*/

	//Clear color buffer
	glClear(GL_COLOR_BUFFER_BIT);

	//Render quad
	//if (true)
	{
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(-0.5f, 0.5f);
		glEnd();
	}
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
		draw(hWindow); // call the draw function
	}

    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(hWindow);
    SDL_Quit();
    return 0;
}