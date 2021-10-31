#include <iostream>
#include "includes/Utils.h"

void startApp() {
    std::cout << "Salut! Bine ai venit pe platforma de socializare UtilityIT" << std::endl;
    std::cout << "Pentru o a putea accesa ai nevoie de un cont." << std::endl;
    std::cout << "Pentru a te putea inregistra, foloseste /register" << std::endl;
    std::cout << "In cazul in care ai deja un cont, foloseste /login" << std::endl;

    std::string message;

    std::cin >> message;
    if (message == "/register") {
        Utils::registerUser();
    } else if (message == "/login") {
        Utils::loginUser();
    } else {
        std::cout << "Din pacate nu am putut identifica aceasta comanda. Te rugam sa folosesti /register sau /login." << std::endl;
    }

}



int main() {
    startApp();
    return 0;
}
