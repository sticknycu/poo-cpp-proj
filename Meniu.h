//
// Created by Nicolae Marius Ghergu on 15.01.2022.
//

#ifndef UTILITYIT_MENIU_H
#define UTILITYIT_MENIU_H

#include <iostream>

class Meniu {
private:
    Meniu() = default;

public:

    Meniu(const Meniu &copie) = delete;

    ~Meniu() = default;

    Meniu &operator=(const Meniu &copie) = delete;

    static Meniu &getInstance();

    static void startApp();
};


#endif //UTILITYIT_MENIU_H
