add_executable(iltest iltest.cpp 
                      ilservice_test.cpp
                      iloperation_test.cpp)

target_link_libraries(iltest PRIVATE il ilservice)

target_include_directories(iltest PUBLIC 
                                  ${CATCH_INCLUDE_DIR}
                                  ${IL_SRC_DIR})

