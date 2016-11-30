add_library(ilservice ilservice.hpp
                      core/ilcore.cpp core/ilcore.hpp core/ilcore.ipp
                      configuration/ilconfiguration.cpp configuration/ilconfiguration.hpp configuration/ilconfiguration.ipp
                      manager/ilmanager.hpp manager/ilmanager.ipp manager/ilmanager.cpp)

target_include_directories(ilservice PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


