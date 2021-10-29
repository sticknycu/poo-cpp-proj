#include <iostream>
#include <fstream>
#include "includes/User.h"

void startApp() {
    std::cout << "Salut! Bine ai venit pe platforma de socializare UtilityIT";
    std::cout << "Pentru o a putea accesa ai nevoie de un cont.";
    std::cout << "Pentru a te putea inregistra, foloseste /register";
    std::cout << "In cazul in care ai deja un cont, foloseste /login";
    
    std::string message;
    std::string username;
    std::string password;
    std::ifstream file;

    std::cin >> message;
    
    if (message == "/register") {
        std::cout << "Deci nu ai un cont. Te rugam sa introduci numele de utilizator dorit.";
        std::cin >> username;
        file.open("accounts.txt", std::ios::in);
        std::cout << "Acum te rog sa introduci parola:";
        std::cin >> password;
    }

    file.close();

}



int main() {
    startApp();
    return 0;
}
