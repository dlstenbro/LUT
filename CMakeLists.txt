cmake_minimum_required(VERSION 2.6.0)

# here we specify that the project is C language only, so the default
# C compiler on the system will be used
project(lut_example)

add_executable(lut_example main.c LUT.h)
