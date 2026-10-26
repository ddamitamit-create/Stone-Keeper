add_executable(Sandbox
    src/SandboxApp.cpp
        ../LogLibrary.cpp
        ../LogLibrary.h
)

target_link_libraries(Sandbox PRIVATE StoneKeeper)
