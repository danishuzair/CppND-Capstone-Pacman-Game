# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run ControllerTest.cpp ControllerTest.h IntersectionTest.cpp IntersectionTest.h StreetTest.cpp StreetTest.h CreateGameEnvironmentTest.cpp CreateGameEnvironmentTest.h FollowMaximumFoodAutomatedControllerTest.cpp FollowMaximumFoodAutomatedControllerTest.h)
target_link_libraries(Google_Tests_run Pacman_lib)
target_link_libraries(Google_Tests_run gtest gtest_main)