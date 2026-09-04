#pragma once

#include "StoneKeeper/Application.h"

int main(int argc, char** argv) {
    Engine::Application* app = Engine::CreateApplication();
    app->Run();
    delete app;
    return 0;
}
