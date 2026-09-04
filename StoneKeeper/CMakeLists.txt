add_library(StoneKeeper SHARED
    src/Application.cpp
        include/StoneKeeper/Core.h
        src/Core.cpp
        include/StoneKeeper/EntryPoint.h
)

target_include_directories(StoneKeeper PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
