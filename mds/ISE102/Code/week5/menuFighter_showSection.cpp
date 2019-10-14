#include <iostream>
using namespace std;

void showSection(int section) 
{
    if (menuChoice == 1) {
        cout << "Round 1, Fight! Bish bish bash URGH!! You win." << endl;
    }
    if (menuChoice == 2) {
        cout << "Your only option is to fight." << endl;
    }
    if (menuChoice == 3) {
        cout << "Bye" << endl;
    }
}

int main() 
{
    int menuChoice = 0;
    cout << "---- WELCOME TO MENU FIGHTER -----" << endl;

    while (menuChoice != 3) {
        cout << "1: Play Game | 2: Options | 3: Quit" << endl;
        cout << "Enter a number to choose:" << endl;
        cin >> menuChoice;
        showSection(menuChoice);
    }
    return 0;
}
