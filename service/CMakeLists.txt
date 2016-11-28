add_library(ilservice ilservice.hpp
                      ilmanager/ilmanager.hpp ilmanager/ilmanager.ipp ilmanager/ilmanager.cpp)

target_include_directories(ilservice PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} 
                                            ${Qt5Core_INCLUDE_DIRS})

