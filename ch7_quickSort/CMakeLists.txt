
cmake_minimum_required(VERSION 3.0)

project(quickSort LANGUAGES C)

set(${CMAKE_C_FLAGS} "-O3 -Wall ${CMAKE_C_FLAGS}")

add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} -lpthread)
