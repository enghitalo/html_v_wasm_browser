cmake_minimum_required(VERSION 3.10)

project(my_app)
# Fetch Sokol (if not already present)
# git submodule add https://github.com/floooh/sokol external_lib

add_executable(my_app sokol_sapp.c)

target_include_directories(my_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/external_lib/sokol)

target_link_libraries(my_app PRIVATE external_lib)