#include "Application.h"
#include <LogLibrary.h>

#include "Events/ApplicationEvent.h"

namespace Engine {

    Application::Application() = default;
    Application::~Application() = default;

    void Application::Run() {
        ENGINE_LOG(Info, "Hello from the Engine!, we are officially running");
        StoneKeeper::WindowResizedEvent e(1280, 720);
        ENGINE_LOG(Trace, "{}" ,e.ToString());
        while (true) {

        }
    }
}
