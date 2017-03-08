#ifndef RENDERER_LOCAL_INCLUDES_H
#define RENDERER_LOCAL_INCLUDES_H

#if defined(__WIN32__) || defined(__WIN64__)
#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <Winuser.h>
#include <Windowsx.h>
#include <stdio.h>
#else
#error "Not implemented yet"
#endif

#endif /*RENDERER_LOCAL_INCLUDES_H*/