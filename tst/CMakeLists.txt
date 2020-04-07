set(BINARY ${CMAKE_PROJECT_NAME}_tst)

add_executable(${BINARY} embedded_controller_test.cpp)

add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)