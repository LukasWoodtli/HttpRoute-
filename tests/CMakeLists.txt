cmake_minimum_required(VERSION 3.0.1)


add_executable(endpoint_test endpoint_test.cpp)
add_test(endpoint_test endpoint_test)

add_executable(cast_test cast_test.cpp)
add_test(cast_test cast_test)
