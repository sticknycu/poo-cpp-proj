//
// Created by Nicolae Marius Ghergu on 19.01.2022.
//

#ifndef UTILITYIT_USERFACTORY_H
#define UTILITYIT_USERFACTORY_H

#include "../includes/User.h"
#include "../includes/Utils.h"

class User;

class Profile;

class Utils;

class UserFactory {
public:
    static User user();

    static Profile profile(User &user_);
};

#endif //UTILITYIT_USERFACTORY_H
