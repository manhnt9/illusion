cmake_minimum_required(VERSION 2.8.11)
project(Illusion)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_PREFIX_PATH "/home/manh/Qt5.7.0/5.7/gcc_64")
find_package(Qt5Core)

include_directories(./)

add_subdirectory(il)
add_subdirectory(service)
#add_subdirectory(connect)
#add_subdirectory(message)

add_custom_target(files SOURCES README.md)

add_executable(illusion main.cpp)
target_link_libraries(illusion Qt5::Core ilservice il)
