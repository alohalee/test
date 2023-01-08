cmake_minimum_required(VERSION 3.24)
project(simple_ATM_controller)

set(CMAKE_CXX_STANDARD 17)

add_executable(simple_ATM_controller main.cpp Bank.cpp Bank.h Controller.cpp Controller.h)
