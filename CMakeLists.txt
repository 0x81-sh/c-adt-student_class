cmake_minimum_required(VERSION 3.17)
project(student_class C)

set(CMAKE_C_STANDARD 99)

add_executable(student_class main.c class.c class.h student.c student.h)