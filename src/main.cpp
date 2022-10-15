#include "SDL.h"
#include "window.hpp"
#include "imgui.h"

int main(int argc, char** argv)
{
    Window window{};

    while (window.IsRunning())
    {
        window.PollEvents();
        window.PreRender();
        ImGui::ShowDemoWindow();
        window.PostRender();
    }

    return 0;
}
