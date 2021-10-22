//
// Created by NicolaeMarius.Ghergu on 10/22/2021.
//

#ifndef UTILITYIT_PROFILE_H
#define UTILITYIT_PROFILE_H

#include <iostream>

class Profile: public User {
private:
    User userProfile;
    Post posts[];
    std::string workList[];
    std::string studies[];
    std::string livingPlaces[];
    std::string otherNames;
    std::string relation;
    std::string family[];
    std::string interests[];
    std::string religion;
    std::string policyOrientation;
    std::string visits[];
    std::string games[];
    std::string pagesLiked[];
    User usersFollowed[];
    std::string events;
    long creationDate;
    Group groups[];
    User followers[];

public:

    Profile() {
    }

    long getCreationDate() {
        return this->creationDate;
    }

    void setCreationDate(long date) {
        this->creationDate = date;
    }
};

#endif //UTILITYIT_PROFILE_H
