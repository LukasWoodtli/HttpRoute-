cmake_minimum_required(VERSION 3.0.1)

project(HttpRoute++)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-W -Wall -Wextra  -Werror)

if(APPLE AND CMAKE_CXX_COMPILER_ID MATCHES Clang)
    add_compile_options(-stdlib=libc++)
    # See https://stackoverflow.com/questions/16655820/clang-mac-os-x-c11-linker-issue/16656234#16656234
    add_definitions("-D'_LIBCPP_EXTERN_TEMPLATE(...)='")
endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS)

enable_testing()
add_subdirectory("tests/")
