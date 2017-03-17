

#ifndef RENDERER_LOCAL_INCLUDES_H
#define RENDERER_LOCAL_INCLUDES_H

#define OPENGL 1 // Use opengl on this project 


#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_opengl.h"
#include <memory>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <functional>
#include <utility>
#include <string>

#if defined(__WIN32__) || defined(__WIN64__)
    #ifndef UNICODE
        #define UNICODE
    #endif

    #include <windows.h>    
    #include <Winuser.h>
    #include <Windowsx.h>

    //#pragma comment (lib, "opengl32.lib")
#else
    //#error "Not implemented yet"
#endif

#endif /*RENDERER_LOCAL_INCLUDES_H*/