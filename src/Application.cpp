//
// Created by Nicolae Marius Ghergu on 12.01.2022.
//

#include "../includes/Application.h"
#include "../includes/Utils.h"
#include "../includes/Admin.h"
#include "../includes/FileNotFoundException.h"

class FileNotFoundException;

class Utils;

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
    std::cout << "poti afla informatiile pe care le avem despre tine folosind /myInfo" << std::endl;
    std::cout << "Foloseste comanda respectiva!" << std::endl;

    std::string inputString;
    //inputString = Utils::handleInput(inputString);
    while (std::cin >> inputString) {
        if (inputString == "/createPost") {
            try {
                Post::handlePost(user);
            } catch (FileNotFoundException &e) {
                e.what();
            }
        } else if (inputString == "/enterGroup") {
            std::cout << "Din pacate aceasta functionalitate inca nu este implementata. Te rugam sa reviii."
                      << std::endl;
        } else if (inputString == "/createRule") {
            try {
                Rule::createRule(user);
            } catch (FileNotFoundException &e) {
                e.what();
            }
        } else if (inputString == "/accessEvent") {
            std::cout << "Din pacate aceasta functionalitate inca nu este implementata. Te rugam sa reviii."
                      << std::endl;
        } else if (inputString == "/addComment") {
            Comment::handleComment(user);
        } else if (inputString == "/myInfo") {
            std::cout << "Informatiile pe care le avem despre tine sunt: " << std::endl;
            User userManage = Profile::getUserInformationFromDatabase(user);
            userManage.showInformationsAboutUser();
        } else if (inputString == "/profile") {
            Profile::configureProfile(user);
        } else if (inputString == "/exit") {
            std::cout << "Iti multumim ca ai folosit platforma noastra!" << std::endl;
            exit(0);
        } else if (inputString == "/admins") {
            std::cout << "Lista administratorilor este: " << std::endl;
            std::string identificator;
            Admin<std::string> admin{};
            for (const User &castedUser: admin.getAdmins()) {
                std::cout << castedUser << std::endl;
            }
        } else {
            std::cout << "Comanda nu a fost gasita. Te voi trimite inapoi la navigarea pe platforma." << std::endl;
        }
    }
}
