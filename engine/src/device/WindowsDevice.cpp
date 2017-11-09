#include "SDL.h"
#include "device/WindowsDevice.h"
#include "graphics/GraphicLibrarySingleton.h"
#include "graphics/GraphicLibrary.h"

#include <iostream>
#include <string.h>

WindowsDevice::WindowsDevice() {
	gl = GraphicLibrarySingleton::getInstance();
}

WindowsDevice::~WindowsDevice() {

    // Close and destroy the window
    SDL_DestroyWindow(mWindow);
        
    // Clean up
    SDL_Quit();
}

void WindowsDevice::start() {
    initSDL2();
	gl->init();
}

void WindowsDevice::setTitle(const char* title) {
    mTitle = (char*)title;
}

void WindowsDevice::setWidth(int width) {
    mWidth = width;
}

void WindowsDevice::setHeight(int height) {
    mHeight = height;
}

void WindowsDevice::swapBuffers() {
    SDL_GL_SwapWindow(mWindow);

	//Now render the texture target to our screen
	SDL_UpdateTexture(
		mTargetTexture,
		nullptr,
		gl->getBackBuffer(),
		mWidth
	);

	SDL_RenderClear(mRenderer);
	SDL_RenderCopyEx(
		mRenderer, 
		mTargetTexture, 
		NULL, 
		NULL, 
		0, 
		NULL, 
		SDL_FLIP_VERTICAL
	);
	SDL_RenderPresent(mRenderer);
}

bool WindowsDevice::isAvailable() {
    return mNoQuit;
}

void WindowsDevice::pollEvents() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {

        switch(event.type) {
            case SDL_QUIT:
                mNoQuit = false;
                break;
        }
    }    
}

int WindowsDevice::getWidth() {
    return mWidth;
}

int WindowsDevice::getHeight() {
    return mHeight;
}

float WindowsDevice::getAspectRation() {
    return (float)mWidth/(float)mHeight;
}

void WindowsDevice::initSDL2() {
    
    bool sdl2WasInit = SDL_Init(SDL_INIT_EVERYTHING);
    
    SDL_Init(SDL_INIT_EVERYTHING); // Initialize SDL2

    // Create an application window with the following settings:
    mWindow = SDL_CreateWindow(
        mTitle,        // window title
        SDL_WINDOWPOS_UNDEFINED, // initial x position
        SDL_WINDOWPOS_UNDEFINED, // initial y position
        mWidth,                     // width, in pixels
        mHeight,                     // height, in pixels
        SDL_WINDOW_BORDERLESS     // flags - see below
    );
    
    // Check that the window was successfully created
    if (mWindow == NULL)
    {
        // In the case that the window could not be made...
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return;
    }
    
	// Create a renderer to render to texture on window
	mRenderer = SDL_CreateRenderer(
		mWindow, 
		-1, 
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE
	);

	// Make a target texture to render too
	mTargetTexture = SDL_CreateTexture(
		mRenderer, 
		SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, 
		mWidth, 
		mHeight
	);

	//Now render to the texture
	//SDL_SetRenderTarget(mRenderer, mTargetTexture);

    mNoQuit = true;
}