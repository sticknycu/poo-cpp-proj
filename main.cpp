#include <iostream>
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
        user.setEmail(username);
        bool availabilityUser = User::checkUserAvailability(user);
        if (availabilityUser) {
            std::cout << "Se pare ca ai cont, deci putem sa cream alt cont cu acelasi nume de utilizator." << std::endl;
            std::cout << "Te rugam sa revi cu alt nume de utilizator" << std::endl;
        } else {
            std::cout << "Se pare ca nu exista nici un nume de utilizator ca cel introdus." << std::endl;
            std::cout << "Te rugam sa introduci o parola pentru a putea efectua crearea contului." << std::endl;
            std::cin >> password;
            std::cout
                    << "Acum ca totul este in regula, va trebui sa facem niste setari. Te rog spune-ne mai multe despre tine."
                    << std::endl;
        }
    } else {
        std::cout << "Din pacate nu am putut identifica aceasta comanda. Te rugam sa folosesti /register sau /login." << std::endl;
    }

}



int main() {
    startApp();
    return 0;
}
