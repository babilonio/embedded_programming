
set(BINARY ${CMAKE_PROJECT_NAME})
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -DDEBUG")

add_library(${BINARY}_lib embedded_controller.cpp)
target_include_directories (${BINARY}_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${BINARY}_run main.cpp)
target_link_libraries(${BINARY}_run PUBLIC ${BINARY}_lib)