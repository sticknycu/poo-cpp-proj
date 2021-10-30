//
// Created by nycuro on 10/30/21.
//

#ifndef UTILITYIT_UTILS_H
#define UTILITYIT_UTILS_H

#include <iostream>
#include <vector>

class Utils {

public:

    // constructor default fara parametrii
    Utils();

    // destructor
    ~Utils();

    // constructor de copiere
    Utils(const Utils& copie);

    Utils& operator=(const Utils& copie);

    // Implementarea pentru a face split al unui string.
    static std::vector<std::string> explodeString(std::string &text);

};

#endif //UTILITYIT_UTILS_H
