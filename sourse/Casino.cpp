#include "Casino.hpp"
#include "ColorCasino.hpp"
#include "HardCasino.hpp"

#include <algorithm>
#include <iostream>

int BiggestBalanceFunction(std::vector<int> BalanceVector) {
    sort(BalanceVector.begin(), BalanceVector.end());
    return BalanceVector[BalanceVector.size() - 1];
}

void MainProblem() {
     int CasinoChoice;
    std::cout << "\t\t=====WELCOME TO CASINO WORLD=====" << std::endl;
    std::cout << "What is your name? ";
    std::string PlayerName;
    std::getline(std::cin, PlayerName);
    do {
        std::cout << PlayerName << ", which type of casino you want to choose?" << std::endl;
        std::cout << "1. Hard Casino 1...10" << std::endl;
        std::cout << "2. Color Casino" << std::endl;
       
        std::string StringCasinoChoice;
        std::getline(std::cin,StringCasinoChoice);
        std::cin >> CasinoChoice;
        CasinoChoice = std::stoi(StringCasinoChoice);
        switch (CasinoChoice) {
        case 1: {
            HardCasinoRules();
            HardCasino1To10(PlayerName);
            break;
        }
        case 2: {
            ColorCasinoRules();
            ColorCasino(PlayerName);
            break;
        }

        default: {
            std::cout << "We have only 2 types of casino, sorry......" << std::endl; 
            break;
            }
        }
    } while (CasinoChoice != 1 || CasinoChoice != 2);
}