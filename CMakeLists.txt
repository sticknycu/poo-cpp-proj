cmake_minimum_required(VERSION 3.0)
project(UtilityIT)

set(CMAKE_CXX_STANDARD 23)

add_executable(UtilityIT
        main.cpp

        src/Comment.cpp
        src/Event.cpp

        includes/User.h
        includes/Post.h

        includes/Reaction.h
        includes/Comment.h

        includes/Profile.h
        includes/Event.h
        includes/Group.h
        includes/Rule.h

        includes/ReactionEnum.h
        )
