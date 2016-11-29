add_library(il ilprint.hpp ilstate.hpp
               iloperation.cpp iloperation.hpp iloperation.ipp
               iltcpoperation.cpp iltcpoperation.hpp iltcpoperation.ipp
               ilclient.cpp ilclient.hpp ilclient.ipp
               ilmodifier.cpp ilmodifier.hpp ilmodifier.ipp)
                   

target_include_directories(il PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

