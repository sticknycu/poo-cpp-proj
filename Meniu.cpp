//
// Created by Nicolae Marius Ghergu on 15.01.2022.
//

#include "Meniu.h"
#include <iostream>
#include "includes/User.h"

class User;

void Meniu::startApp() {
    std::cout << "Salut! Bine ai venit pe platforma de socializare UtilityIT" << std::endl;
    std::cout << "Pentru o a putea accesa ai nevoie de un cont." << std::endl;
    std::cout << "Pentru a te putea inregistra, foloseste /register" << std::endl;
    std::cout << "In cazul in care ai deja un cont, foloseste /login" << std::endl;

    std::string message;

    std::cin >> message;
    if (message == "/register") {
        User::registerUser();
    } else if (message == "/login") {
        User::loginUser();
    } else {
        std::cout << "Din pacate nu am putut identifica aceasta comanda. Te rugam sa folosesti /register sau /login." << std::endl;
    }

}

Meniu *Meniu::getInstance() {
    if (instance == nullptr) {
        instance = new Meniu();
    }
    return instance;
}
