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
    cout << "Greetings, " << playerName << "!\n";
    cout << "Your journey begins...\n";
    waitForInput();

    bool playing = true;
    while (playing) {
        clearScreen();
        cout << "======= SHATTERED REALMS =======\n";
        cout << "1. Explore\n";
        cout << "2. Rest\n";
        cout << "3. Stats\n";
        cout << "4. Quit\n";
        cout << "================================\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                clearScreen();
                cout << "You venture into the dark forest...\n";
                int enemyHP = getRandomNumber(30, 70);
                combat(playerName, playerHP, enemyHP, xp, gold);
                if (playerHP <= 0) {
                    cout << "\nYou have fallen in battle.\n";
                    cout << "Game Over.\n";
                    playing = false;
                }
                waitForInput();
                break;
            }
            case 2:
                clearScreen();
                cout << "You make camp and rest...\n";
                playerHP = 100;
                cout << "Your health has been restored!\n";
                waitForInput();
                break;
            case 3:
                clearScreen();
                cout << "===== PLAYER STATS =====\n";
                cout << "Name: " << playerName << "\n";
                cout << "HP: " << playerHP << "\n";
                cout << "XP: " << xp << "\n";
                cout << "Gold: " << gold << "\n";
                cout << "=========================\n";
                waitForInput();
                break;
            case 4:
                clearScreen();
                cout << "Farewell, hero...\n";
                playing = false;
                break;
            default:
                break;
        }
    }

    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();
    return 0;
}

// Clears the console screen
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Waits for user to press Enter
void waitForInput() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Generates a random number
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Simple combat system
void combat(string playerName, int &playerHP, int &enemyHP, int &xp, int &gold) {
    string enemyName = "Shadow Beast";
    cout << "A wild " << enemyName << " appears!\n'\n'";

    while (playerHP > 0 && enemyHP > 0) {
        cout << "Your HP: " << playerHP << " | " << enemyName << "'s HP: " << enemyHP << "\n";
        cout << "1. Attack\n2. Defend\n3. Run\nChoose: ";

        int choice;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        int playerDmg = getRandomNumber (10, 25);
        int enemyDmg = getRandomNumber (5, 20);

        switch (choice) {
            case 1:
                cout << "You strike the " << enemyName << " for " << playerDmg << " damage!\n";
                enemyHP -= playerDmg;
                break;
            case 2:
                cout << "You brace for impact and take reduced damage.\n";
                enemyDmg /= 2;
                break;
            case 3:
                cout << "You flee from battle...\n";
                return;
            default:
                cout << "You hesitate...\n";
                break;
        }

        if (enemyHP > 0) {
            cout << "The " << enemyName << " hits you for " << enemyDmg << " damage!\n";
            playerHP -= enemyDmg;
        }
    }

    if (enemyHP <= 0) {
        cout << "\nYou have slain the " << enemyName << "!\n";
        int rewardXP = getRandomNumber(10, 30);
        int rewardGold = getRandomNumber(5, 15);
        xp += rewardXP;
        gold += rewardGold;
        cout << "You gained " << rewardXP << " XP and " << rewardGold << " gold!\n";
    }
}