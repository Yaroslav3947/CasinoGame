#include "Casino.hpp"
#include "HardCasino.hpp"


#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

enum Instruments {
    CONTINUE_GAME = 'f',
};
void HardCasinoRules() {
    system("cls");
    std::cout << "\t\t=====CASINO NUMBER GUESSING RULES=====" << std::endl;
    std::cout << "\t1. Choose a number beetween 1 to 10" << std::endl;
    std::cout << "\t2. Winner gets 10 times of the money bet" << std::endl;
    std::cout << "\t3. Wrong bet, and you lose the amount you bet" << std::endl;
    std::cout << std::endl;
}

void HardCasino1To10(const std::string& PlayerName) {
    srand(time(NULL));
    int GuessNumber = 0;
    int BettingAmount = 0;
    char choice;
    std::set < int > BiggestBalanceSet;
    std::cout << "Choose your starting balance to play game : $";
    int balance;
    std::cin >> balance;
    BiggestBalanceSet.insert(balance);
    do {
        system("cls");
        std::cout << "Your current balance is $" << balance << std::endl;
        do {
            std::cout << "Hey, " << PlayerName << " ,lets start, enter your amount to bet: $" ;
            std::cin >> BettingAmount;
            if( BettingAmount > balance){
                std::cout << "Betting balance can't be more than than current balance!!!" << std::endl;
                std::cout << "Re-enter your balance" << std::endl;
            } 
        } while(BettingAmount > balance);

        do {
            std::cout << "Guess any number beetween 1 and 10 : ";
            
           
            std::cin >> GuessNumber;
            if (GuessNumber<=0 || GuessNumber>10){
                std::cout << "Your guess must be between 1 and 10" << std::endl;
                std::cout << "Re-enter your guessnumber" << std::endl;
            }

        } while(GuessNumber <=0 || GuessNumber>10);
        int dice = rand()%10+1;
        if (dice == GuessNumber) {
            balance+=BettingAmount*10;
            std::cout << "You're in a luck!! You have won $" << GuessNumber*10 << std::endl;
        } else {
            balance-=BettingAmount;
            std::cout << "Ooops, better luck next time! You have lost $" << BettingAmount << std::endl; 
            std::cout << "The winning number was " << dice << std::endl;
        }
        std::cout << PlayerName << ", your balance is $" << balance << std::endl;
        BiggestBalanceSet.insert(balance);
        
        if(balance == 0) {
            std::cout << "You have no money to play";
            break;
        }
        std::cout << "Do you want to play again? If yes, press f" << std::endl;
        std::cin >> choice;
    } while(choice == CONTINUE_GAME );
    std::cout << std::endl;
    std::cout << "Thanks for playing the game.Your Biggest balance was $" << BiggestBalance(BiggestBalanceSet) << std::endl;

}