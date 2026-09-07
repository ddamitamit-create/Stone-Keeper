#include "../../StoneKeeper/src/StoneKeeper.h"

class SandboxApp : public Engine::Application {
public:
    SandboxApp() {}
    ~SandboxApp() {}
};

Engine::Application* Engine::CreateApplication() {
    return new SandboxApp();
}
