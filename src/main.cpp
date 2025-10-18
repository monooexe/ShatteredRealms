#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

// Function declarations
void clearScreen();
void waitForInput();
int getRandomNumber(int mini, int max);
void combat(string playerName, int &playerHP, int &enemyHP, int &xp, int &gold);

int main() {
    srand(static_cast<unsigned int>(time(0)));

    string playerName;
    int playerHP = 100;
    int xp = 0;
    int gold = 0;

    clearScreen();
    cout << "=========================================\n";
    cout << "       WELCOME TO SHATTERED REALMS       \n";
    cout << "=========================================\n\n";
    cout << "Enter your hero's name: ";
    getline(cin, playerName);

    if (playerName.empty()) playerName = "Nameless Wanderer";

    clearScreen();
}