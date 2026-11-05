
cmake_minimum_required(VERSION 3.20)

project(Matrix_Calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(matrix_lib src/matrix.cpp)

target_include_directories(matrix_lib PUBLIC include)

add_executable(matrix_calculator src/main.cpp)

target_link_libraries(matrix_calculator PRIVATE matrix_lib)

target_compile_options(matrix_lib PRIVATE -Wall -Wextra -Wpedantic -Werror)
target_compile_options(matrix_calculator PRIVATE -Wall -Wextra -Wpedantic -Werror)

enable_testing()
add_subdirectory(tests)
