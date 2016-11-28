add_library(il ilprint.hpp ilstate.hpp
               iloperation.hpp iloperation.hpp iloperation.ipp
               iltcpoperation.cpp iltcpoperation.hpp iltcpoperation.ipp)
                   

target_include_directories(il PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} 
                                         ${Qt5Core_INCLUDE_DIRS})

