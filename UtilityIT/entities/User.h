//
// Created by NicolaeMarius.Ghergu on 10/21/2021.
//

#ifndef UTILITYIT_USER_H
#define UTILITYIT_USER_H


class User {
private:
    std::string firstName;
    std::string lastName;
    int cnp;
    long creationDate;
    Post posts[];
};


#endif //UTILITYIT_USER_H
