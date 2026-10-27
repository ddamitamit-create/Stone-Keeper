add_library(StoneKeeper SHARED
        src/StoneKeeper/Application.cpp
        src/StoneKeeper/Application.h
        src/StoneKeeper/Core.h
        src/StoneKeeper/EntryPoint.h
        src/StoneKeeper.h
)

target_include_directories(StoneKeeper PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(StoneKeeper PUBLIC Logger)
