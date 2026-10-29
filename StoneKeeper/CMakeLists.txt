add_library(StoneKeeper SHARED
        Application.cpp
        Application.h
        Core.h
        EntryPoint.h
        StoneKeeper.h
        Events/ApplicationEvent.h
        Events/Event.h
        Events/KeyEvent.h
        Events/MouseEvent.h
)

target_include_directories(StoneKeeper PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/..
)
target_link_libraries(StoneKeeper PUBLIC Logger)
