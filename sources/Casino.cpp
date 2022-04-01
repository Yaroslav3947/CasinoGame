#include "Casino.hpp"
#include "ColorCasino.hpp"
#include "HardCasino.hpp"

#include <algorithm>
#include <iostream>

std::string PlayerName;

enum playerChoices {
    HARD_CASINO = 1,
    COLOR_CASINO = 2,
};

int BiggestBalanceFunction(std::vector<int> BalanceVector) {
    sort(BalanceVector.begin(), BalanceVector.end());
    return BalanceVector[BalanceVector.size() - 1];
}
void AcquaintanceWithThePlayer() {
    std::cout << "\t\t=====WELCOME TO CASINO WORLD=====" << std::endl;
    std::cout << "What is your name? ";
    std::getline(std::cin, PlayerName);
}
void GetChoiceOfSelection() {
        std::cout << PlayerName << ", which type of casino you want to choose?" << std::endl;
        std::cout << "1. Hard Casino 1...10" << std::endl;
        std::cout << "2. Color Casino" << std::endl;
}
void DoPlayerChoice() {
    int CasinoChoice;
     do {

        GetChoiceOfSelection();
       
        
        std::cin >> CasinoChoice;
        
        switch (CasinoChoice) {
        case HARD_CASINO: {
            HardCasinoRules();
            HardCasino1To10(PlayerName);
            break;
        }
        case COLOR_CASINO: {
            ColorCasinoRules();
            ColorCasino(PlayerName);
            break;
        }

        default: 
            std::cout << "We have only 2 types of casino, sorry......" << std::endl; break;

        }
    } while (CasinoChoice != 1 || CasinoChoice != 2);
}

void MainProblem() {
    
    AcquaintanceWithThePlayer();
    DoPlayerChoice();
}