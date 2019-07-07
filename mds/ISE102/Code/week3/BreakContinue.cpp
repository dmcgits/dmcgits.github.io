#include <iostream>

using namespace std;

int main()
{
    // Infinite loop.
    while (true)
    {
        // Ask the user if they wish to continue playing game.
        char playerChoice = 'n';

        cout << "Continue to play? (Y)es or (N)o: ";
        cin >> playerChoice;

        // Test for upper and lower case.
        if(playerChoice == 'n' || playerChoice == 'N')
        {
            cout << "You have selected to exit the game." << endl;

            break;    // Exits the infinite loop.
        }
        else
        {
            cout << "Playing the game..." << endl;
        }
    }

    int sum = 0;
    for (int i = 0; i < 12; i++)
    {
        if (i == 2 || i == 4 || i == 8)
        {
            cout << "Found a restricted number (2, 4, 8), ";
            cout << "using continue." << endl;

            continue; // Jump to next cycle in for loop.
        }

        // If 'continue' did not happen, execute following code.
        sum += i;

        cout << endl;
        cout << "Current Value in i is: " << i << endl;
        cout << "Current Value in sum is: " << sum << endl;
        cout << endl;
    }

    // Wait for input, stops the Command Prompt closing automatically.
    int iTemp;
    cin >> iTemp;

    return (0);
}
