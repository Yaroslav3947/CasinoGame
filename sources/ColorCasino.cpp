#include "ColorCasino.hpp"
#include "Casino.hpp"

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>


std::vector<int> BiggestBalanceVec;
int BettingAmount = 0;
int balance;
int dice;
char choice;
char color;

enum ColorSelection {
    GREEN_COLOR = 'g',
    BLACK_COLOR = 'b',
    RED_COLOR = 'r',
    
};
enum Instruments {
    CONTINUE_GAME = 'f',
};
void ColorCasinoRules() {
    system("cls");
    std::cout << "\t\t=====CASINO NUMBER GUESSING RULES=====" << std::endl;
    std::cout << "\t1. Choose a color: red, green or black" << std::endl;
    std::cout << "\t2. Winner gets 2 times of the money bet if you will guess color(red or black),\n\t but if u will guess green color you will get 100 times money " << std::endl;
    std::cout << "\t3. Wrong bet, and you lose the amount you bet" << std::endl;
    std::cout << "\t\tLUCK YOU" << std::endl;
    std::cout << std::endl;
}
int GetBalance() {
    std::string StringBalance;
    std::cout << "Choose your starting balance to play game : $";
    std::getline(std::cin,StringBalance );
    return std::stoi(StringBalance);
}
void GetAndCheckBettingAmount (int balance) {
        std::cin >> BettingAmount;
            if (BettingAmount > balance) {
                std::cout << "Betting balance can't be more than than current balance!!!" << std::endl;
                std::cout << "Re-enter your balance" << std::endl;
            }
}
void InputBetingAmount(std::string PlayerName) {
    do {
            std::cout << "Hey, " << PlayerName << ", lets start, enter your amount to bet: $";
             GetAndCheckBettingAmount(balance);
        } while (BettingAmount > balance);
}
void InputAndCheckSelectionOfColor() {
    do {
            std::cout << "Guess color green(g), red(r), black(b) : ";
            std::cin >> color;
            if (color != GREEN_COLOR && color != BLACK_COLOR && color != RED_COLOR){
                std::cout << "Your color must be only green, red or black" << std::endl;
                std::cout << "Re-enter your color" << std::endl;
            }
            else 
                continue;
        } while (color != GREEN_COLOR && color != BLACK_COLOR && color != RED_COLOR);
}
void CheckColorAndAmountOfWin() {
    dice = rand() % 37 + 1;
        if (dice == 1 && color == GREEN_COLOR) {
            balance += BettingAmount * 50;
            std::cout << "OMG, you did it!!!!!!!" << std::endl;
            std::cout << "You're in a huge luck!! You have won $" << BettingAmount * 100 << std::endl;
        }
        else if (dice % 2 == 0 && color == RED_COLOR) {
            balance += BettingAmount;
            std::cout << "You're in a luck!! You have won $" << BettingAmount * 2 << std::endl;
        }
        else if (dice % 2 == 1 && color == BLACK_COLOR) {
            balance += BettingAmount;
            std::cout << "You're in a luck!! You have won $" << BettingAmount * 2 << std::endl;
        } else {
            balance -= BettingAmount;
            std::cout << "Heh, luck you in next game, you have lost" << std::endl;
        }
}
void ShowBiggestBalance( std::string PlayerName) {
    std::cout << "Hey, " << PlayerName << ", your balance is $" << balance << std::endl;
        BiggestBalanceVec.push_back(balance);
}
void EndingOfTheGameAndShowsYourRecords() {
    std::cout << "Thanks for playing the game.Your Biggest balance was $" << BiggestBalanceFunction(BiggestBalanceVec) << std::endl;
}

void ColorCasino(const std::string&  PlayerName) {
    srand(time(NULL));
    balance = GetBalance();
    
    do {
        system("cls");
        std::cout << "Your current balance is $" << balance << std::endl;

        InputBetingAmount(PlayerName);

        InputAndCheckSelectionOfColor();
        
        CheckColorAndAmountOfWin();

        ShowBiggestBalance(PlayerName);

        if (balance == 0) {
            std::cout << "You have no money to play";
            break;
        }
        std::cout << "Do you want to play again? If yes, press f" << std::endl;
        std::cin >> choice;
    } while (choice == CONTINUE_GAME);
    std::cout << std::endl;
    EndingOfTheGameAndShowsYourRecords();
}
