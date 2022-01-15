//
// Created by Nicolae Marius Ghergu on 12.01.2022.
//

#include "../includes/Application.h"
#include "../includes/Utils.h"
#include "../includes/Admin.h"

class Utils;

template <typename T>
class Admin;

void Application::navigatePlatform(User &user) {
    std::cout << "Acum ca doresti sa navighezi pe platforma, ai o multime de posibilitati." << std::endl;
    std::cout << "Poti crea o postare folosind /createPost" << std::endl;
    std::cout << "Poti crea o regula folosind /createRule" << std::endl;
    std::cout << "Poti intra intr-un grup folosind /enterGroup" << std::endl;
    std::cout << "Poti adauga un comentariu unei postari folosind /addComment" << std::endl;
    std::cout << "Poti accesa un eveniment folosind /accessEvent" << std::endl;
    std::cout << "Poti sa iti modifici informatiile despre profil folosind /profile" << std::endl;
    std::cout << "Daca doresti sa iesi de pe platforma, foloseste /exit" << std::endl;
    std::cout << "Afla cine sunt administratorii platformei folosind /admins" << std::endl;
    std::cout << "Foloseste comanda respectiva!" << std::endl;

    std::string inputString;
    inputString = Utils::handleInput(inputString);
    if (inputString == "/createPost") {
        Post::handlePost(user);
    } else if (inputString == "/enterGroup") {
        //TODO: Enter group
        std::cout << "Din pacate aceasta functionalitate inca nu este implementata. Te rugam sa reviii." << std::endl;
        navigatePlatform(user);
    } else if (inputString == "/createRule") {
        Rule::createRule(user);
    } else if (inputString == "/accessEvent") {
        //TODO: Access event
        std::cout << "Din pacate aceasta functionalitate inca nu este implementata. Te rugam sa reviii." << std::endl;
        navigatePlatform(user);
    } else if (inputString == "/addComment") {
        Comment::handleComment(user);
    } else if (inputString == "/profile") {
        Profile::configureProfile(user);
        navigatePlatform(user);
    } else if (inputString == "/exit") {
        std::cout << "Iti multumim ca ai folosit platforma noastra!" << std::endl;
    } else if (inputString == "/admins") {
        std::cout << "Lista administratorilor este: " << std::endl;
        Admin<std::string> admin;
        for (const User& castedUser : admin.getAdmins()) {
            std::cout << castedUser << std::endl;
        }
    } else {
        std::cout << "Comanda nu a fost gasita. Te voi trimite inapoi la navigarea pe platforma." << std::endl;
        navigatePlatform(user);
    }
}
