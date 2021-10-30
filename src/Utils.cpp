//
// Created by nycuro on 10/30/21.
//

#include "../includes/Utils.h"
#include "../includes/Profile.h"
#include <vector>
#include <iostream>
#include <sstream>

// Implementarea constructorului de initializare
Utils::Utils() {
    std::cout << "[DEBUG] Apelare constructor Utils.h" << std::endl;
}

// Implementarea destructorului
Utils::~Utils() {
    std::cout << "[DEBUG] Apelare destructor Utils.h" << std::endl;
}

// Implementarea constructorului de copiere
Utils::Utils(const Utils &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere Utils.h" << std::endl;
}

// Implementarea operatorului =
Utils &Utils::operator=(const Utils &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere Utils.h" << std::endl;
    return *this;
}

// Implementarea pentru a face split unui string.
std::vector<std::string> Utils::explodeString(std::string &text) {
    std::vector<std::string> words{};
    char delimiter = '|';

    std::istringstream sstream(text);
    std::string word;
    while (std::getline(sstream, word, delimiter)) {
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        words.push_back(word);
    }

    return words;
}

// Implementarea pentru register
User Utils::registerUser() {
    std::string username;
    std::cout << "Deci nu ai un cont. Te rugam sa introduci numele de utilizator dorit." << std::endl;
    std::cin >> username;
    User user;
    user.setUsername(username);
    bool availabilityUser = User::checkUserAvailability(user);
    if (availabilityUser) {
        std::cout << "Se pare ca ai cont, deci putem sa cream alt cont cu acelasi nume de utilizator." << std::endl;
        std::cout << "Te rugam sa revi cu alt nume de utilizator" << std::endl;
    } else {
        std::string password;
        std::cout << "Se pare ca nu exista nici un nume de utilizator ca cel introdus." << std::endl;
        std::cout << "Te rugam sa introduci o parola pentru a putea efectua crearea contului." << std::endl;
        std::cin >> password;
        user.setPassword(password);
        std::cout << "Acum ca totul este in regula, va trebui sa facem niste setari. Te rog spune-ne mai multe despre tine." << std::endl;
        configurateUser(user);
        std::cout << "Felicitari, avem toate informatiile necesare pentru a putea naviga pe platforma noastra" << std::endl;
        std::cout << "Doresti sa ai si un profil sau sa navighezi pe platforma fara profil? Raspunde cu true sau false." << std::endl;
        bool booleanValue;
        std::cin >> booleanValue;
        if (booleanValue) {
            configureProfile(user);
        } else {
            std::cout << "Am inteles, totul este in regula, poti naviga si fara profil. Ce doresti sa faci in momentul de fata?" << std::endl;
        }
    }
    return user;
}

// Implementarea pentru login
void Utils::loginUser() {
    std::string username;
    std::cout << "Deci ai deja un cont. Te rugam sa introduci numele de utilizator:" << std::endl;
    std::cin >> username;
    User user;
    user.setUsername(username);
    bool availabilityUser = User::checkUserAvailability(user);
    if (!availabilityUser) {
        std::cout << "Nu am gasit nici un utilizator cu acest nume. Doresti sa creezi un cont?" << std::endl;
        bool booleanValue;
        std::cin >> booleanValue;
        if (booleanValue) {
            std::cout << "Cum raspunsul tau este pozitiv, te voi transmite catre pasii de inregistrare" << std::endl;
            registerUser();
        } else {
            std::cout
                    << "Din pacate nu poti naviga pe platforma daca nu ai un cont. Vrei sa introduci alt nume de utilizator?"
                    << std::endl;
            std::cin >> booleanValue;
            if (booleanValue) {
                std::cout << "Te voi transmite la pasul de login in cateva momente.." << std::endl;
                loginUser();
            } else {
                std::cout
                        << "Din pacate, pentru a putea folosi platforma ai nevoie de un nume de utilizator. Te rugam sa revi cu unul."
                        << std::endl;
                exit(0);
            }
        }
    } else {
        std::string password;
        std::cout
                << "Se pare ca ai introdus un nume de utilizator ce exista in platforma noastra. Te rugam sa introduci parola:"
                << std::endl;
        std::cin >> password;
        User authedUser = User::getUserInformationFromDatabase(user);
        if (authedUser.getPassword() == password) {
            std::cout << "Ai fost logat cu succes pe platforma. Spune-ne ce doresti sa faci mai departe." << std::endl;
            navigatePlatform(user);
        } else {
            std::cout << "Din pacate, parola nu este buna. Te rugam sa revi." << std::endl;
        }

    }
}

// Implementarea pentru configurarea User-ului
User Utils::configurateUser(User &user) {
    std::string text;
    std::cout << "Facem acest lucru deoarece trebuie sa respectam legislatia in vigoare." << std::endl;
    std::cout << "Astfel, spune-ne care este prenumele tau:" << std::endl;
    std::cin >> text;
    user.setFirstname(text);
    std::cout << "Ne-ar interesa si care este numele tau de familie:" << std::endl;
    std::cin >> text;
    user.setLastname(text);
    std::cout << "Spune-ne te rog si CNP-ul tau:" << std::endl;
    // TODO: verify age
    std::cout << "Ultimul pas este despre sexul tau, te rog sa ni-l comunici:" << std::endl;
    std::cin >> text;
    user.setSex(text);
    return user;
}

Profile Utils::configureProfile(User &user) {
    Profile profile;
    return profile;
}

void Utils::navigatePlatform(User &user) {
    std::cout << "Acum ca doresti sa navighezi pe platforma, ai o multime de posibilitati." << std::endl;
    std::cout << "Poti crea o postare folosind /createPost" << std::endl;
    std::cout << "Poti intra inr-un grup folosind /enterGroup" << std::endl;
    std::cout << "Poti accesa un eveniment folosind /accessEvent" << std::endl;
    std::cout << "Poti sa iti modifici informatiile despre profil folosind /profile" << std::endl;
    std::cout << "Daca doresti sa iesi de pe platforma, foloseste /exit" << std::endl;
    std::cout << "Foloseste comanda respectiva!" << std::endl;
    std::string input;
    std::cin >> input;
    if (input == "/createPost") {
        //TODO : Create post
    } else if (input == "/enterGroup") {
        //TODO: Enter group
    } else if (input == "/accessEvent") {
        //TODO: Access event
    } else if (input == "/profile") {
        configureProfile(user);
    } else if (input == "/exit") {
        std::cout << "Iti multumim ca ai folosit platforma noastra!" << std::endl;
    } else {
        std::cout << "Comanda nu a fost gasita. Te voi trimite inapoi la navigarea pe platforma." << std::endl;
        navigatePlatform(user);
    }
}
