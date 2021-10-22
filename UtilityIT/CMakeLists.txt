cmake_minimum_required(VERSION 3.0)
project(UtilityIT)

set(CMAKE_CXX_STANDARD 23)

add_executable(UtilityIT main.cpp entities/User.h entities/Post.h interactions/Reaction.h utils/Location.h interactions/Comment.h entities/Profile.h entities/Event.h entities/Group.h entities/Rule.h)
