#include "SDL.h"
#include "window.hpp"
#include "imgui.h"
#include "wiiuse.h"

int main(int argc, char** argv)
{
    Window window{};

    wiimote** remotes;

    remotes = wiiuse_init(1);

    bool remoteFound = false;
    bool wiimoteConnected = false;

    while (window.IsRunning())
    {
        window.PollEvents();

        window.PreRender();
        ImGui::Begin("Wiimote State");
        if (ImGui::Button("Refresh Wiimote"))
        {
            remoteFound = wiiuse_find(remotes, 1, 5);
            if (remoteFound)
            {
                wiimoteConnected = wiiuse_connect(remotes, 1);
            }
        }
        if (remoteFound && wiimoteConnected)
        {
            ImGui::Text("Found a remote!");
        }
        ImGui::End();
        window.PostRender();
    }

    return 0;
}
