#include "Application.h"
#include <iostream>

namespace Engine {

Application::Application() {}
Application::~Application() {}

void Application::Run() {
    std::cout << "Hello from the Engine!\n";
}

}
