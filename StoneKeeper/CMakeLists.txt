add_library(StoneKeeper STATIC
    src/Core.cpp
)

target_include_directories(StoneKeeper PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
