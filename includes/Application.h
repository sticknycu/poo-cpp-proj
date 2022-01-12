//
// Created by Nicolae Marius Ghergu on 12.01.2022.
//

#ifndef UTILITYIT_APPLICATION_H
#define UTILITYIT_APPLICATION_H

#include "User.h"

class User;

class Application {

public:

    // Navigarea pe plaforma
    static void navigatePlatform(User &user);

    static void startApplication();
};


#endif //UTILITYIT_APPLICATION_H
