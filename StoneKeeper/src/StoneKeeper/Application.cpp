#include "Application.h"
#include <LogLibrary.h>
namespace Engine {

Application::Application() {}
Application::~Application() {}

void Application::Run() {
    Log::Init();
    ENGINE_LOG(Info, "Hello from the Engine!, we are officially running");
}

}
