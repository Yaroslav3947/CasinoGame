#include <exception>
#include <iostream>

#include "Casino.hpp"

int main() {

    try {
        MainProblem();  
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}