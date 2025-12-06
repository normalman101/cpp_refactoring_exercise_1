cmake_minimum_required(VERSION 4.0)
project(university)

set(CMAKE_CXX_STANDARD 20)

add_executable(university main.cpp
        include/Person.h
        include/Date.h
        include/Teacher.h
        include/ProgramErrors.h)

target_include_directories(university PUBLIC ${PROJECT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ./include)