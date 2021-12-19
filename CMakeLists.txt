cmake_minimum_required(VERSION 3.0)
project(UtilityIT)

set(CMAKE_CXX_STANDARD 23)

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

        includes/User.h
        includes/Post.h

        includes/Reaction.h
        includes/Comment.h

        includes/Profile.h
        includes/Event.h
        includes/Group.h
        includes/Rule.h

        includes/ReactionEnum.h

        includes/Utils.h
        includes/BaseException.h includes/WrongPasswordException.h src/BaseException.cpp src/WrongPasswordException.cpp)
