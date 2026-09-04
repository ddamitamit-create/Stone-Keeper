add_library(StoneKeeperLib STATIC
    src/Core.cpp
)

target_include_directories(StoneKeeperLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
