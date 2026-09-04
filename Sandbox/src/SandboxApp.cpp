#include "StoneKeeper/Application.h"
#include "StoneKeeper/EntryPoint.h"

class SandboxApp : public Engine::Application {
public:
    SandboxApp() {}
    ~SandboxApp() {}
};

Engine::Application* Engine::CreateApplication() {
    return new SandboxApp();
}
