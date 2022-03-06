cmake_minimum_required(VERSION 3.17)
project(Console_App_Snake_Game)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(Console_App_Snake_Game
        src/Apple.cpp
        src/Apple.h
        src/Board.cpp
        src/Board.h
        src/Controller.cpp
        src/Controller.h
        src/GameEngine.cpp
        src/GameEngine.h
        src/main.cpp
        src/Snake.cpp
        src/Snake.h)
