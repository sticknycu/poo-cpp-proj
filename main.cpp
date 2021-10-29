#include <iostream>
#include <fstream>
#include "includes/User.h"

void startApp() {
    std::cout << "Salut! Bine ai venit pe platforma de socializare UtilityIT" << std::endl;
    std::cout << "Pentru o a putea accesa ai nevoie de un cont." << std::endl;
    std::cout << "Pentru a te putea inregistra, foloseste /register" << std::endl;
    std::cout << "In cazul in care ai deja un cont, foloseste /login" << std::endl;

    std::string message;
    std::string username;
    std::string password;

    std::cin >> message;
    if (message == "/register") {
        std::cout << "Deci nu ai un cont. Te rugam sa introduci numele de utilizator dorit." << std::endl;
        std::cin >> username;
        User user;
        user.setEmail(message);
        bool availabilityUser = User::checkUserAvailability(user);
        if (availabilityUser) {
            std::cout << "Se pare ca nu ai cont inca, deci putem sa iti cream un cont." << std::endl;
            std::cout << "Acum te rog sa introduci parola:" << std::endl;
            //std::cin >> password;
            // TODO: Implementation for pass & add new users and etc.
        }
    } else {
        std::cout << "Din pacate nu am putut identifica aceasta comanda. Te rugam sa revi." << std::endl;
    }

}



int main() {
    startApp();
    return 0;
}
