add_library(il ilprint.hpp ilstate.hpp
               iltime.hpp ilsignal.hpp
               operation/iloperation.hpp operation/iloperation_fw.hpp
               operation/iloperation_base.cpp operation/iloperation_base.hpp operation/iloperation_base.ipp 
               operation/iltcpoperation.cpp operation/iltcpoperation.hpp operation/iltcpoperation.ipp operation/iltcpoperation_fw.hpp
               #ilclient.cpp ilclient.hpp ilclient.ipp ilclient_fw.hpp
               modifier/ilmodifier_type.hpp
               modifier/ilmodifier.cpp modifier/ilmodifier.hpp modifier/ilmodifier.ipp modifier/ilmodifier_fw.hpp)

target_include_directories(il PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

