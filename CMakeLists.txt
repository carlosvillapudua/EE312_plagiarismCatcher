cmake_minimum_required(VERSION 3.12)
project(plagiarismCatcher__new)

set(CMAKE_CXX_STANDARD 14)

add_executable(plagiarismCatcher__new main.cpp directory.cpp directory.h file.cpp file.h hashTable.cpp hashTable.h)