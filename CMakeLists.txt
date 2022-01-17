cmake_minimum_required(VERSION 3.0)
project(UtilityIT)

set(CMAKE_CXX_STANDARD 17)

add_executable(UtilityIT
        main.cpp

        src/Comment.cpp
        src/Event.cpp
        src/Group.cpp
        src/Post.cpp
        src/Profile.cpp
        src/Reaction.cpp
        src/Rule.cpp
        src/User.cpp
        src/Utils.cpp
        src/ReactionEnum.cpp
        src/BaseException.cpp
        src/WrongPasswordException.cpp
        src/Application.cpp
        Meniu.cpp Meniu.h)
