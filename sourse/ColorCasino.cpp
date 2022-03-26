#include "ColorCasino.hpp"
#include "Casino.hpp"

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>


void ColorCasinoRules() {
    system("cls");
    std::cout << "\t\t=====CASINO NUMBER GUESSING RULES=====" << std::endl;
    std::cout << "\t1. Choose a color: red, green or black" << std::endl;
    std::cout << "\t2. Winner gets 2 times of the money bet if you will guess color(red or black),\n\t but if u will guess green color you will get 100 times money " << std::endl;
    std::cout << "\t3. Wrong bet, and you lose the amount you bet" << std::endl;
    std::cout << "\t\tLUCK YOU" << std::endl;
    std::cout << std::endl;
}

void ColorCasino(const std::string&  PlayerName) {
    srand(time(NULL));
    int BettingAmount;
    int guessColor;
    int BiggestBalance;
    int dice;
    char choice;
    char color;
    std::vector<int> BiggestBalanceVec;

    std::cout << "Choose your starting balance to play game : $";
    int balance;
    std::string StringBalance;
    std::getline(std::cin,StringBalance );
    int balance = std::stoi(StringBalance);
    
    do {
        system("cls");
        std::cout << "Your current balance is $" << balance << std::endl;
        do {
            std::cout << "Hey, " << PlayerName << ", lets start, enter your amount to bet: $";
            std::string StringBettingAnount;
            std::getline(std::cin,StringBettingAnount );
            int BettingAnount = std::stoi(StringBettingAnount);
            if (BettingAmount > balance) {
                std::cout << "Betting balance can't be more than than current balance!!!" << std::endl;
                std::cout << "Re-enter your balance" << std::endl;
            }
        } while (BettingAmount > balance);

        do {
            std::cout << "Guess color green(g), red(r), black(b) : ";
            std::cin >> color;
            if (color != 'g' && color != 'b' && color != 'r'){
                std::cout << "Your color must be only green, red or black" << std::endl;
                std::cout << "Re-enter your color" << std::endl;
            }
            else 
                continue;
            

        } while (color != 'g' && color != 'b' && color != 'r');
        dice = rand() % 37 + 1;
        if (dice == 1 && color == 'g') {
            balance += BettingAmount * 50;
            std::cout << "OMG, you did it!!!!!!!" << std::endl;
            std::cout << "You're in a huge luck!! You have won $" << BettingAmount * 100 << std::endl;
        }
        else if (dice % 2 == 0 && color == 'r') {
            balance += BettingAmount;
            std::cout << "You're in a luck!! You have won $" << BettingAmount * 2 << std::endl;
        }
        else if (dice % 2 == 1 && color == 'b') {
            balance += BettingAmount;
            std::cout << "You're in a luck!! You have won $" << BettingAmount * 2 << std::endl;
        } else {
            balance -= BettingAmount;
            std::cout << "Heh, luck you in next game, you have lost" << std::endl;
        }
        std::cout << "Hey, " << PlayerName << ", your balance is $" << balance << std::endl;
        BiggestBalanceVec.push_back(balance);

        if (balance == 0) {
            std::cout << "You have no money to play";
            break;
        }
        std::cout << "Do you want to play again? If yes, press F" << std::endl;
        std::cin >> choice;
    } while (choice == 'F' || choice == 'f');
    std::cout << std::endl;
    std::cout << "Thanks for playing the game.Your Biggest balance was $" << BiggestBalanceFunction(BiggestBalanceVec) << std::endl;
}
