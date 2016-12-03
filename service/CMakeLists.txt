add_library(ilservice ilservice.hpp
                      core/ilcore.cpp core/ilcore.hpp core/ilcore.ipp
                      configuration/ilconfiguration.cpp configuration/ilconfiguration.hpp configuration/ilconfiguration.ipp)

target_include_directories(ilservice PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

