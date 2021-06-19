cmake_minimum_required(VERSION 3.5)
project(da_course_01)
add_executable(lzw lzw.cpp)
set_target_properties(lzw PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
