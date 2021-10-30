//
// Created by nycuro on 10/30/21.
//

#include "../includes/Utils.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

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
std::vector<std::string> Utils::explodeString(std::string &text, char delimiter) {
    std::vector<std::string> words{};

    std::istringstream sstream(text);
    std::string word;
    while (std::getline(sstream, word, delimiter)) {
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        words.push_back(word);
    }

    return words;
}

// Functia pentru a salva datele in fisier
void Utils::handleRegister(User &user) {
    std::ofstream file;
    std::string empty;

    std::string username = user.getUsername();
    std::string password = user.getPassword();
    std::string firstname = user.getFirstname();
    std::string lastname = user.getLastname();
    std::string cnp = std::to_string(user.getCNP());
    std::string sex = user.getSex();

    std::string data = username
            .append("|").append(password)
            .append("|").append(firstname)
            .append("|").append(lastname)
            .append("|").append(cnp)
            .append("|").append(sex);

    file.open("accounts.txt", std::ios::out | std::ios::app);

    file << std::endl << data;

    file.close();
}


// Implementarea pentru register
void Utils::registerUser() {
    std::string username;
    std::cout << "Deci nu ai un cont. Te rugam sa introduci numele de utilizator dorit." << std::endl;
    std::cin >> username;
    User user;
    user.setUsername(username);
    bool availabilityUser = User::checkUserAvailability(user);
    if (availabilityUser) {
        std::cout << "Se pare ca ai cont, deci nu putem sa cream alt cont cu acelasi nume de utilizator." << std::endl;
        std::cout << "Te rugam sa revi cu alt nume de utilizator" << std::endl;
    } else {
        std::string password;
        std::cout << "Se pare ca nu exista nici un nume de utilizator ca cel introdus." << std::endl;
        std::cout << "Te rugam sa introduci o parola pentru a putea efectua crearea contului." << std::endl;
        std::cin >> password;
        user.setPassword(password);
        std::cout << "Acum ca totul este in regula, va trebui sa facem niste setari. Te rog spune-ne mai multe despre tine." << std::endl;
        user = configurateUser(user);
        std::cout << "Felicitari, avem toate informatiile necesare pentru a putea naviga pe platforma noastra" << std::endl;
        std::cout << "Doresti sa ai si un profil sau sa navighezi pe platforma fara profil? Raspunde cu true sau false." << std::endl;
        bool booleanValue;
        std::cin >> booleanValue;
        if (booleanValue) {
            configureProfile(user);
        } else {
            std::cout << "Am inteles, totul este in regula, poti naviga si fara profil." << std::endl;
            navigatePlatform(user);
        }
    }
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
    text = handleInput(text);
    user.setFirstname(text);
    std::cout << "Ne-ar interesa si care este numele tau de familie:" << std::endl;
    text = handleInput(text);
    user.setLastname(text);
    std::cout << "Spune-ne te rog si CNP-ul tau:" << std::endl;
    std::cin >> text;
    user.setCNP(std::stol(text));
    // TODO: verify age
    std::cout << "Ultimul pas este despre sexul tau, te rog sa ni-l comunici:" << std::endl;
    std::cin >> text;
    text = std::toupper(text[0]);
    user.setSex(text);
    handleRegister(user);
    return user;
}

Profile Utils::configureProfile(User &user) {
    std::cout << "Ne bucuram ca iti doresti sa iti configurezi profilul. De aceea, te rugam sa ne spui urmatoarele informatii:" << std::endl;
    Profile profile;
    profile.setId(user.getCNP());
    std::cout << "Ce studiezi si ce studii ai avut pana acum? Te rugam sa le notezi cu virgula, fara spatii." << std::endl;

    std::string valuableStringForStudies;
    std::string valuableStringForLivingPlaces;

    std::string valuableString;
    valuableString = handleInput(valuableString);
    valuableStringForStudies = valuableString;
    std::vector<std::string> studies = Utils::explodeString(valuableString, ',');
    profile.setStudies(studies);
    std::cout << "Unde locuiesti si unde ai locuit pana acum? Te rugam sa le notezi cu virgula, fara spatii." << std::endl;
    valuableString = handleInput(valuableString);
    valuableStringForLivingPlaces = valuableString;
    std::vector<std::string> livingPlaces = Utils::explodeString(valuableString, ',');
    profile.setLivingPlaces(livingPlaces);
    // functie care salveaza informatiile in fisier.
    std::cout << "Ai configurat profilul cu succes!" << std::endl;
    return profile;
}

void Utils::navigatePlatform(User &user) {
    std::cout << "Acum ca doresti sa navighezi pe platforma, ai o multime de posibilitati." << std::endl;
    std::cout << "Poti crea o postare folosind /createPost" << std::endl;
    std::cout << "Poti intra intr-un grup folosind /enterGroup" << std::endl;
    std::cout << "Poti accesa un eveniment folosind /accessEvent" << std::endl;
    std::cout << "Poti sa iti modifici informatiile despre profil folosind /profile" << std::endl;
    std::cout << "Daca doresti sa iesi de pe platforma, foloseste /exit" << std::endl;
    std::cout << "Foloseste comanda respectiva!" << std::endl;

    std::string inputString;
    inputString = handleInput(inputString);
    if (inputString == "/createPost") {
        //TODO : Create post
    } else if (inputString == "/enterGroup") {
        //TODO: Enter group
    } else if (inputString == "/accessEvent") {
        //TODO: Access event
    } else if (inputString == "/profile") {
        configureProfile(user);
        navigatePlatform(user);
    } else if (inputString == "/exit") {
        std::cout << "Iti multumim ca ai folosit platforma noastra!" << std::endl;
    } else {
        std::cout << "Comanda nu a fost gasita. Te voi trimite inapoi la navigarea pe platforma." << std::endl;
        navigatePlatform(user);
    }
}

std::string Utils::handleInput(std::string &text) {
    for(;;) {
        getline(std::cin, text);

        if (!text.empty()) {
            break;
        } else if (std::cin.fail()) {
            std::cin.clear(); // unset failbit
        }
    }
    return text;
}
