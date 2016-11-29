cmake_minimum_required(VERSION 2.8.11)
project(Illusion)

set(CMAKE_CXX_STANDARD 14)

include_directories(./)

add_subdirectory(il)
add_subdirectory(service)
#add_subdirectory(connect)
#add_subdirectory(message)

add_custom_target(files SOURCES README.md)

add_executable(illusion main.cpp)
target_link_libraries(illusion ilservice il)

