//
// Created by NicolaeMarius.Ghergu on 10/22/2021.
//

#ifndef UTILITYIT_GROUP_H
#define UTILITYIT_GROUP_H

#include <iostream>

class Group {

private:
    User peopleJoined[];
    User peopleRequestedToJoin[];
    std::string description;
    Rule rules[];
    Post posts[];

public:
    Group() {
    }
};

#endif //UTILITYIT_GROUP_H
