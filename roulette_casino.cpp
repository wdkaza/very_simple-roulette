#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

void spinWheel(int &randNum);
void betMoney(std::string &userChoice, int &moneyBet, int balance, int randNum);
void checkWin(const std::string &userChoice, int &moneyBet, int randNum);

int main() {
    srand(time(0));
    int randNum;
    int balance = 100;
    int moneyBet;
    std::string userChoice;
    std::string userChoiceMenu;
    while(true){
        std::cout << "Welcome! Your balance is: " << balance << "\n";
        std::cout << "Would you like to spin or quit: ";
        std::cin >> userChoiceMenu;

        if (userChoiceMenu == "spin") {
            betMoney(userChoice, moneyBet, balance, randNum);
        }
    }


    return 0;
}

void spinWheel(int &randNum) {
    randNum = rand() % 37; // Random number between 0 and 36
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    std::cout << "Number: " << randNum << "\n";
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
}

void betMoney(std::string &userChoice, int &moneyBet, int balance, int randNum) {
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    std::cout << "1/3, 2/3, 3/3\n";
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    std::cout << "Odd, even, black/red/green\n";
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    std::cout << "Choice: ";
    std::cin >> userChoice;
    std::cout << "How much chips: ";
    std::cin >> moneyBet;

    if (moneyBet > balance) {
        std::cout << "You are broke, gg.\n";
    } else {
        spinWheel(randNum);
        checkWin(userChoice, moneyBet, randNum);
        balance += moneyBet; // Adjust balance based on win/loss
        std::cout << "Your new balance is: " << balance << "\n";
    }
}

void checkWin(const std::string &userChoice, int &moneyBet, int randNum) {
    if (userChoice == "1/3" && randNum >= 1 && randNum <= 12) {
        moneyBet *= 3;
        std::cout << "Congrats! Chips won: " << moneyBet << "\n";
    } else if (userChoice == "2/3" && randNum >= 13 && randNum <= 24) {
        moneyBet *= 3;
        std::cout << "Congrats! Chips won: " << moneyBet << "\n";
    } else if (userChoice == "3/3" && randNum >= 25 && randNum <= 36) {
        moneyBet *= 3;
        std::cout << "Congrats! Chips won: " << moneyBet << "\n";
    } else if (userChoice == "odd" && randNum % 2 != 0) {
        moneyBet *= 2;
        std::cout << "Congrats! Chips won: " << moneyBet << "\n";
    } else if (userChoice == "even" && randNum % 2 == 0 && randNum != 0) {
        moneyBet *= 2;
        std::cout << "Congrats! Chips won: " << moneyBet << "\n";
    } else if (userChoice == "green" && randNum == 0) {
        moneyBet *= 13;
        std::cout << "Congrats! Chips won: " << moneyBet << "\n";
    } else {
        std::cout << "Sorry, you lost.\n";
        moneyBet = -moneyBet; // Deduct bet amount from balance
    }
}
