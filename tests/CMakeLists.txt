
include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

add_executable(matrix_tests test_matrix.cpp)

target_link_libraries(matrix_tests PRIVATE
    matrix_lib
    GTest::gtest_main
)

add_test(NAME matrix_tests COMMAND matrix_tests)
