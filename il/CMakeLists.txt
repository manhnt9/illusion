add_library(il ilprint.hpp ilstate.hpp
               iloperation.cpp iloperation.hpp iloperation.ipp
               iltcpoperation.cpp iltcpoperation.hpp iltcpoperation.ipp
               ilclient.cpp ilclient.hpp ilclient.ipp)
                   

target_include_directories(il PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} 
                                         ${Qt5Core_INCLUDE_DIRS})

