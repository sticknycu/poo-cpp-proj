//
// Created by Nicolae Marius Ghergu on 19.01.2022.
//

#include "../includes/UserFactory.h"
#include <iostream>
#include <string>


User UserFactory::user() {
    UserBuilder userBuilder;
    std::string text;
    std::cout << "Facem acest lucru deoarece trebuie sa respectam legislatia in vigoare." << std::endl;
    std::cout << "Astfel, spune-ne care este prenumele tau:" << std::endl;
    text = Utils::handleInput(text);
    userBuilder.firstname(text);
    std::cout << "Ne-ar interesa si care este numele tau de familie:" << std::endl;
    text = Utils::handleInput(text);
    userBuilder.lastname(text);
    std::cout << "Spune-ne te rog si CNP-ul tau:" << std::endl;
    std::cin >> text;
    userBuilder.cnp(std::stol(text));
    // TODO: verify age
    std::cout << "Ultimul pas este despre sexul tau, te rog sa ni-l comunici:" << std::endl;
    std::cin >> text;
    userBuilder.sex(std::to_string(std::toupper(text[0])));
    return userBuilder.build();
}

Profile UserFactory::profile(User &user_) {
    ProfileBuilder profileBuilder;
    std::cout
            << "Ne bucuram ca iti doresti sa iti configurezi profilul. De aceea, te rugam sa ne spui urmatoarele informatii:"
            << std::endl;
    profileBuilder.profileId(user_.getCNP());
    std::cout << "Ce studiezi si ce studii ai avut pana acum? Te rugam sa le notezi cu virgula, fara spatii."
              << std::endl;

    std::string valuableString;
    valuableString = Utils::handleInput(valuableString);

    std::vector<std::string> studies = Utils::splitString(valuableString, ',');
    profileBuilder.studies(studies);
    std::cout << "Unde locuiesti si unde ai locuit pana acum? Te rugam sa le notezi cu virgula, fara spatii."
              << std::endl;

    valuableString = Utils::handleInput(valuableString);
    std::vector<std::string> livingPlaces = Utils::splitString(valuableString, ',');
    profileBuilder.livingPlaces(livingPlaces);

    Profile p = profileBuilder.build();
    User::handleProfile(p);

    std::cout << "Ai configurat profilul cu succes!" << std::endl;
    return p;
}