//
// Created by Mew on 10/15/2022.
//

#ifndef WIIMOTECHAMP_WINDOW_HPP
#define WIIMOTECHAMP_WINDOW_HPP

#include "SDL.h"

class Window
{
public:
    Window();
    ~Window();

    void PollEvents();
    void PreRender();
    void PostRender();

    bool IsRunning() const { return m_running; }

private:
    SDL_Window* m_window;
    SDL_GLContext m_glContext;
    bool m_running = true;

};


#endif //WIIMOTECHAMP_WINDOW_HPP
