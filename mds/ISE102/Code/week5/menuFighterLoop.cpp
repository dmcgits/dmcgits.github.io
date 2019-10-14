#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

// Headers
int displayMenuAndGetChoice() {
    int choice;
    
    cout << "1: Play Game | 2: Options | 3: Quit" << endl;
    cout << "Enter a number to choose:" << endl;
    cin >> choice;
    
    return choice;
}

void displaySection(int section) {
    if (section == 1) {
        cout << "Round 1, Fight! Bish bish bash URGH!! You win." << endl;
    }
    if (section == 2) {
        cout << "Your only option is to fight." << endl;
    }
    if (section == 3) {
        cout << "Bye" << endl;
    }
}

int main() {
    int menuChoice= 0;
    cout << "---- WELCOME TO MENU FIGHTER -----" << endl;

    while (menuChoice != 3) {    
        menuChoice = displayMenuAndGetChoice();
        displaySection(menuChoice);
    }
    return 0;
}


