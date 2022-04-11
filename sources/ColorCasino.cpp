#include "ColorCasino.hpp"
#include "Casino.hpp"

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <set>

const int NumberOfRouletteSectors = 38;

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
    int Balance;
    std::cout << "Choose your starting balance to play game : $";
    std::cin >> Balance;
    return Balance;
}
char GetColor() {
    char Color;
    std::cout << "Guess color green(g), red(r), black(b) : ";
    std::cin >> Color;
    return Color;
}
int GetBettingAmount () {
    int BettingAmount;
    std::cin >> BettingAmount;
    return BettingAmount;
}
void InputBetingAmount(std::string PlayerName, int Balance,int BettingAmount) {
    do {
            std::cout << "Hey, " << PlayerName << ", lets start, enter your amount to bet: $";
            std::cin >> BettingAmount;
            if (BettingAmount > Balance) {
                std::cout << "Betting balance can't be more than than current balance!!!" << std::endl;
                std::cout << "Re-enter your balance" << std::endl;
            }else continue;
        } while (BettingAmount > Balance);
}

void InputAndCheckSelectionOfColor(char &Color) {
    do {
            
            if (Color != GREEN_COLOR && Color != BLACK_COLOR && Color != RED_COLOR){
                std::cout << "Your color must be only green, red or black" << std::endl;
                std::cout << "Re-enter your color" << std::endl;
            }
            else 
                continue;
        } while (Color != GREEN_COLOR && Color != BLACK_COLOR && Color != RED_COLOR);
}
void CheckColorAndAmountOfWin(int &Balance, char &Color,int &BettingAmount) {
        int dice = rand() % NumberOfRouletteSectors;

        if (dice == 1 && Color == GREEN_COLOR) {
            Balance += BettingAmount * 100;
            std::cout << "OMG, you did it!!!!!!!" << std::endl;
            std::cout << "You're in a huge luck!! You have won $" << BettingAmount * 100 << std::endl;
        }
        else if (dice % 2 == 0 && Color == RED_COLOR) {
            Balance += BettingAmount;
            std::cout << "You're in a luck!! You have won $" << BettingAmount * 2 << std::endl;
        }
        else if (dice % 2 == 1 && Color == BLACK_COLOR) {
            Balance += BettingAmount;
            std::cout << "You're in a luck!! You have won $" << BettingAmount * 2 << std::endl;
        } else {
            Balance -= BettingAmount;
            std::cout << "Heh, luck you in next game, you have lost" << std::endl;
        }
}
void ShowBalanceAfterGame(std::string PlayerName, int Balance) {
    std::cout << "Hey, " << PlayerName << ", your balance is $" << Balance << std::endl;
}
void EndingOfTheGameAndShowsYourRecords(std::set<int> BalanceSet) {
    std::cout << "Thanks for playing the game.Your Biggest balance was $" << BiggestBalance(BalanceSet) << std::endl;
}
void ShowYourCurrentBalance(int Balance ) {
    std::cout << "Your current balance is $" << Balance << std::endl;
}
void AnswerChoice() {
    std::cout << "Do you want to play again? If yes, press f" << std::endl;
}
void ColorCasino(const std::string&  PlayerName) {
    srand(time(NULL));
    std::set<int> BalanceSet;
    int BettingAmount = GetBettingAmount();
    int Balance = GetBalance();
    char Color = GetColor();
    char Choice;
    do {
        system("cls");
        ShowYourCurrentBalance(Balance);
        InputBetingAmount(PlayerName,Balance,BettingAmount);
        InputAndCheckSelectionOfColor(Color);
        CheckColorAndAmountOfWin(Balance,Color,BettingAmount);
        ShowBalanceAfterGame(PlayerName,Balance);
        BalanceSet.insert(Balance);
        if (Balance == 0) {
            std::cout << "You have no money to play";
            break;
        }
        AnswerChoice();
        std::cin >> Choice;
    } while (Choice == CONTINUE_GAME);
    std::cout << std::endl;
    
    EndingOfTheGameAndShowsYourRecords(BalanceSet);
}
