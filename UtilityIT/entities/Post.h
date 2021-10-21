//
// Created by NicolaeMarius.Ghergu on 10/21/2021.
//

#ifndef UTILITYIT_POST_H
#define UTILITYIT_POST_H

#include <iostream>
#include "../interactions/Reaction.h"
#include "../interactions/Comment.h"

class Post {
private:
    long id;
    std::string name;
    std::string description;
    Reaction reactions[];
    Comment comments[];

public:
    long getId() {
        return this->id;
    }

    void setId(long id) {
        this->id = id;
    }

    std::string getName() {
        return this->name;
    }

    void setName(std::string name) {
        this->name = name;
    }

    std::string getDescription() {
        return this->description;
    }

    void setDescription(std::string description) {
        this->description = description;
    }


    // TODO: Add reaction and comment

    Reaction[] getReactions(std::string path) {
        Reaction reaction[] = new Reaction;
        long id = 0;
        for (const auto &entry: std::filesystem::directory_iterator(path)) {
            reaction->setId(id);
            reaction->setLocation(entry.path());
            reaction->setName(entry.path().filename());
            id++;
        }
        return reaction;
    }

    Comment[] getComments(std::string path) {
        Comment comment[] = new Comment;
        long id = 0;
        for (const auto & entry : std::filesystem::directory_iterator(path)) {
            comment->setId(id);
            comment->setLocation(entry.path());
            comment->setName(entry.path().filename());
            id++;
        }
        return comment;
    }
};


#endif //UTILITYIT_POST_H
