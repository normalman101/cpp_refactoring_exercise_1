cmake_minimum_required(VERSION 4.0)
project(university)

set(CMAKE_CXX_STANDARD 20)

add_executable(university main.cpp
        Person.h
        Date.h
        Teacher.h
        ProgramErrors.h)
