#include "SDL.h"
#include "window.hpp"

int main(int argc, char** argv)
{
    Window window{};

    while (window.IsRunning())
    {
        window.PollEvents();
        window.PreRender();
        window.PostRender();
    }

    return 0;
}
