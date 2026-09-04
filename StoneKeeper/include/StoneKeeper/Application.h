#pragma once

#include "StoneKeeper/Core.h"

namespace Engine {

class ENGINE_API Application {
public:
    Application();
    virtual ~Application();

    void Run();
};

// Defined by the client application (e.g. Sandbox)
Application* CreateApplication();

}
