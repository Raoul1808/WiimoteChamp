//
// Created by Mew on 10/15/2022.
//

#include "window.hpp"

#include "glad/glad.h"
#include <stdexcept>

Window::Window()
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    m_window = SDL_CreateWindow("Wiimote Champ Debug GUI", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL);

    m_glContext = SDL_GL_CreateContext(m_window);

    if (!gladLoadGLLoader(SDL_GL_GetProcAddress))
    {
        throw std::runtime_error("Failed to load OpenGL 4.6");
    }

    SDL_GL_SetSwapInterval(1);
}

Window::~Window()
{
    SDL_GL_DeleteContext(m_glContext);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Window::PollEvents()
{
    SDL_Event ev;
    while (SDL_PollEvent(&ev))
    {
        if (ev.type == SDL_QUIT)
        {
            m_running = false;
            return;
        }
    }
}

void Window::PreRender()
{
    glClearColor(0.390625f, 0.58203125f, 0.92578125f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::PostRender()
{
    SDL_GL_SwapWindow(m_window);
}
