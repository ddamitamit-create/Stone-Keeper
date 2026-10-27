add_library(Logger SHARED LogLibrary.cpp)
target_include_directories(Logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(Logger PUBLIC cxx_std_20)
set_target_properties(Logger PROPERTIES POSITION_INDEPENDENT_CODE ON)