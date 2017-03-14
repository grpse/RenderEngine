#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "renderer_local_includes.h"
#include "Input.h"

class WindowManager {

public:

    void setSize(int width, int height);
    void setPosition(int x, int y);
    bool Create(const char* title);
    bool Showing();
    void SwapScreen();

private:
    int m_width, m_height;
    bool m_running;
    SDL_Window* m_window;
    SDL_GLContext m_glContext;
    SDL_Event m_event;
    
    void m_setupOpenGLAttributes();
    void m_setupOpenGLColorsAndTests();
    void m_HandleEvents();
    void m_callRenderers();
    void m_cleanUp();
};

#endif /*WINDOWMANAGER_H*/