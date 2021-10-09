#include <iostream>
#include "main.h"

class main {

public:
    static void print() {
        int i = 5;
        std::cout << i;
    }
};

int main() {
    main::print();
}