add_library(Engine STATIC
    src/Core.cpp
)

target_include_directories(Engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
