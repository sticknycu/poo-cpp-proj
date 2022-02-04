//
// Created by nycuro on 10/30/21.
//

#include "../includes/User.h"
#include <fstream>
#include "../includes/Utils.h"
#include "../includes/Application.h"
#include "../includes/WrongPasswordException.h"
#include "../dependencies/include/bcrypt.h"
#include "../Meniu.h"

class User;

class Meniu;

class Group;

class Profile;

class Utils;

class Application;

// Implementarea constructorului de initializare
User::User(const std::string &username, const std::string &password, const std::string &firstname,
           const std::string &lastname,
           const int &cnp, const std::string &sex, std::shared_ptr<Profile> &userProfile) {
    std::cout << "[DEBUG] Apelare constructor User.h" << std::endl;
    this->username = username;
    this->password = password;
    this->firstname = firstname;
    this->lastname = lastname;
    this->cnp = cnp;
    this->sex = sex;
    this->userProfile = userProfile;
}

// Implementarea destructorului
User::~User() {
    std::cout << "[DEBUG] Apelare destructor User.h" << std::endl;
}

// Implementarea constructorului de copiere
User::User(const User &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere User.h" << std::endl;
    this->username = copie.username;
    this->password = copie.password;
    this->firstname = copie.firstname;
    this->lastname = copie.lastname;
    this->cnp = copie.cnp;
    this->sex = copie.sex;
    this->userProfile = copie.userProfile;
}

// Implementarea operatorului =
User &User::operator=(const User &copie) {
    std::cout << "[DEBUG] Apelare operator = User.h" << std::endl;
    this->username = copie.username;
    this->password = copie.password;
    this->firstname = copie.firstname;
    this->lastname = copie.lastname;
    this->cnp = copie.cnp;
    this->sex = copie.sex;
    this->userProfile = copie.userProfile;
    return *this;
}

// Implementarea operatorului <<
std::ostream &operator<<(std::ostream &os, const User &user) {
    std::cout << "[DEBUG] Apelare operator << User.h" << std::endl;
    os << std::endl << user.username;
    os << std::endl << user.password;
    os << std::endl << user.firstname;
    os << std::endl << user.lastname;
    os << std::endl << user.cnp;
    os << std::endl << user.sex;

    return os;
}

// Getter pentru campul "username"
std::string &User::getUsername() {
    return this->username;
}

// Setter pentru campul "username"
void User::setUsername(std::string &text) {
    this->username = text;
}

// Getter pentru campul "password"
std::string &User::getPassword() {
    return this->password;
}

// Setter pentru campul "password"
void User::setPassword(std::string &text) {
    this->password = text;
}

// Getter pentru campul "firstname"
std::string &User::getFirstname() {
    return this->firstname;
}

// Setter pentru campul "firstname"
void User::setFirstname(std::string &text) {
    this->firstname = text;
}

// Getter pentru campul "lastname"
std::string &User::getLastname() {
    return this->lastname;
}

// Setter pentru campul "lastname"
void User::setLastname(std::string &text) {
    this->lastname = text;
}

// Getter pentru campul "cnp"
long &User::getCNP() {
    return this->cnp;
}

// Setter pentru campul "cnp"
void User::setCNP(const long &text) {
    this->cnp = text;
}

// Getter pentru campul "sex"
std::string &User::getSex() {
    return this->sex;
}

// Setter pentru campul "sex"
void User::setSex(std::string &text) {
    this->sex = text;
}

// Implementarea de la userAvailability (verific daca userObject-ul exista)
bool User::checkUserAvailability(User &user) {
    std::ifstream file;
    std::string data;

    file.open("accounts.txt");

    while (std::getline(file, data)) {
        std::vector<std::string> wordsExploded = Utils::splitString(data, '|');
        if (wordsExploded.at(0) == user.getUsername()) {
            file.close();
            return true;
        }
    }

    file.close();

    return false;
}

User User::getUserInformationFromDatabase(User &user) {
    std::ifstream file;
    std::string data;

    file.open("accounts.txt");

    while (std::getline(file, data)) {
        std::vector<std::string> wordsExploded = Utils::splitString(data, '|');
        if (user.getUsername() == wordsExploded.at(0)) {
            user.setPassword(wordsExploded.at(1));
            user.setFirstname(wordsExploded.at(2));
            user.setLastname(wordsExploded.at(3));
            user.setCNP(std::stol(wordsExploded.at(4)));
            user.setSex(wordsExploded.at(5));
        }
    }

    file.close();

    return user;
}

// Functia pentru a salva datele utilizatorului in fisier
void User::handleRegister(User &user) {
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

// Functia pentru a salva profilele in fisier
void User::handleProfile(Profile &profile) {
    std::ofstream file;
    std::string empty;

    profile.manageExistenceProfileData();

    std::string id = std::to_string(profile.getId());

    std::string stringPosts;
    std::vector<std::shared_ptr<Post>> posts = profile.getPosts();
    for (const auto &post: posts) {
        if (stringPosts.empty()) {
            stringPosts.append(std::to_string(post->getId()));
        } else {
            stringPosts = stringPosts
                    .append(std::string(","))
                    .append(std::to_string(post->getId()));
        }
    }

    std::string stringGroups;
    std::vector<std::shared_ptr<Group>> groups = profile.getGroups();
    for (const auto &group: groups) {
        if (stringGroups.empty()) {
            stringGroups.append(group->getName());
        } else {
            stringGroups = stringGroups
                    .append(std::string(","))
                    .append(group->getName());
        }
    }

    std::string stringFollowers;
    std::vector<std::shared_ptr<User>> followers = profile.getFollowers();
    for (const auto &follower: followers) {
        if (stringFollowers.empty()) {
            stringFollowers.append(follower->getUsername());
        } else {
            stringFollowers = stringFollowers
                    .append(std::string(","))
                    .append(follower->getUsername());
        }
    }

    std::string stringStudies;
    std::vector<std::string> studies = profile.getStudies();
    for (const auto &study: studies) {
        if (stringStudies.empty()) {
            stringStudies = stringStudies.append(study);
        } else {
            stringStudies = stringStudies
                    .append(std::string(","))
                    .append(study);
        }
    }

    std::string stringLivingPlaces;
    std::vector<std::string> livingPlaces = profile.getLivingPlaces();
    for (const auto &livingPlace: livingPlaces) {
        if (stringLivingPlaces.empty()) {
            stringLivingPlaces.append(livingPlace);
        } else {
            stringLivingPlaces = stringLivingPlaces
                    .append(std::string(","))
                    .append(livingPlace);
        }
    }

    std::string data = id
            .append("|").append(stringPosts)
            .append("|").append(stringGroups)
            .append("|").append(stringFollowers)
            .append("|").append(stringStudies)
            .append("|").append(stringLivingPlaces);

    file.open("profiles.txt", std::ios::out | std::ios::app);

    file << std::endl << data;

    file.close();
}


// Implementarea pentru register
void User::registerUser() {
    std::string username;
    std::cout << "Deci nu ai un cont. Te rugam sa introduci numele de utilizator dorit." << std::endl;
    std::cin >> username;
    User user;
    user.setUsername(username);
    bool availabilityUser = User::checkUserAvailability(user);
    if (availabilityUser) {
        std::cout << "Nume indisponibil." << std::endl;
        std::cout << "Te rugam sa revii cu alt nume de utilizator" << std::endl;
    } else {
        std::string password;
        std::cout << "Se pare ca nu exista nici un nume de utilizator ca cel introdus." << std::endl;
        std::cout << "Te rugam sa introduci o parola pentru a putea efectua crearea contului." << std::endl;
        std::cin >> password;
        password = bcrypt::generateHash(password);
        user.setPassword(password);
        std::cout
                << "Acum ca totul este in regula, va trebui sa facem niste setari. Te rog spune-ne mai multe despre tine."
                << std::endl;
        UserBuilder userBuilder;
        userBuilder = userBuilder.user();
        User newUser = userBuilder.build();
        newUser.setUsername(username);
        newUser.setPassword(password);
        std::cout << "Felicitari, avem toate informatiile necesare pentru a putea naviga pe platforma noastra"
                  << std::endl;
        std::cout << "Doresti sa ai si un profil sau sa navighezi pe platforma fara profil? Raspunde cu true sau false."
                  << std::endl;
        std::string val;
        std::cin >> val;
        bool booleanValue;
        if (val == "true") {
            booleanValue = true;
        } else if (val == "false") {
            booleanValue = false;
        } else {
            booleanValue = true;
        }
        if (booleanValue) {
            ProfileBuilder profileBuilder;
            profileBuilder.profile();
        } else {
            std::cout << "Am inteles, totul este in regula, poti naviga si fara profil." << std::endl;
            Application::navigatePlatform(user);
        }
    }
}

// Implementarea pentru login
void User::loginUser() {
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
            std::cout << "Cum raspunsul tau este pozitiv, te voi transmite catre pasii de inregistrare"
                      << std::endl;
            registerUser();
        } else {
            throw std::runtime_error("Din pacate nu poti naviga pe platforma daca nu ai un cont.");
            exit(1);
        }
    } else {
        std::string password;
        std::cout
                << "Te rugam sa introduci parola"
                << std::endl;
        std::cin >> password;

        User authedUser = User::getUserInformationFromDatabase(user);
        if (bcrypt::validatePassword(password, authedUser.getPassword())) {
            std::cout << "Ai fost logat cu succes pe platforma. Spune-ne ce doresti sa faci mai departe."
                      << std::endl;
            Application::navigatePlatform(authedUser);
        } else {
            std::string wrongPasswordMessage = "Combinatia user-parola nu este buna. Te rugam sa revii.";
            throw WrongPasswordException(wrongPasswordMessage);
        }

    }
}

void User::showInformationsAboutUser() {
    std::cout << "User informations: " << std::endl;
    std::cout << this->getUsername() << std::endl;
    std::cout << this->getFirstname() << std::endl;
    std::cout << this->getLastname() << std::endl;
    std::cout << this->getSex() << std::endl;
    std::cout << this->getCNP() << std::endl;
}
