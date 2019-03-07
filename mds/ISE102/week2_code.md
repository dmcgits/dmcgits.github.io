# Week 2 code samples
Type code samples into a new project and compile to test. From there, experiment with the code. If you have a question about a how an operator or conditional works, test it out! 

Google any keywords or library functions you don't recognise, it's all out there.

1. [Week 2 code samples](#week-2-code-samples)
   1. [2.1 Relational Operators](#21-relational-operators)
   2. [2.2 Truth Tables](#22-truth-tables)
   3. [2.3 Logical Operators](#23-logical-operators)
   4. [2.4 If Statements](#24-if-statements)
   5. [2.5 Switch](#25-switch)
   6. [2.6 Switch, with fall through](#26-switch-with-fall-through)
   7. [2.7 Enumerated constants](#27-enumerated-constants)

## 2.1 Relational Operators

```C++
#include <iostream> 

using namespace std; 

int main() 
{

// Sets the cout output bool flag to TRUE or FALSE values 
// instead of 1 or 0. 
cout.setf(ios_base::boolalpha); 

// Declare and define two float variables. 
float fNum1 = 0.0f; 
float fNum2 = 0.0f; 

// Take user input into the first float. 
cout << "Enter a number: "; 
cin >> fNum1; 
cout << endl; 

// Take user input into the second float. 
cout << "Enter another number: "; 
cin >> fNum2; 
cout << endl << endl; 

// Use Boolean Operators to compare the float values. 
bool isEqual = fNum1 == fNum2; 
bool isNotEqual = fNum1 != fNum2; 
bool isNum1Greater = fNum1 > fNum2;

	bool isNum2GrtrOrEqual = fNum2 >= fNum1; 
bool isNum2LessOrEqual = fNum2 <= fNum1; 
cout << "Value in isEqual is:          " << isEqual << endl;
cout << "Value in isNotEqual is:       " << isNotEqual << endl; 
cout << "Value in isNum1Greater is:    " << isNum1Greater << endl; 
cout << "Value in isNum1Less is:	      " << isNum1Less << endl;
cout << "Value in isNum2GrtrOrEqual is: " << isNum2GrtrOrEqual << endl; 
cout << "Value in isNum2LessOrEqual is: " << isNum2LessOrEqual << endl;


// Wait for input, stops the Command Prompt closing automatically.
	int _iTemp;
	cin >> _iTemp;

	return (0);
}
```

## 2.2 Truth Tables

```C++
#include <iostream>

using namespace std;

int main()
{
    // Sets the cout output bool flag to TRUE or FALSE values
    // instead of 1 or 0.
    cout.setf(ios_base::boolalpha);

    // Examining Logical AND:
    cout << "AND Truth Table:" << endl << endl;

    cout << "   A   |   B   |  A && B  " << endl;
    cout << "-------+-------+----------" << endl;
    cout << " false | false | " << (false && false) << endl;
    cout << " false | true  | " << (false && true) << endl;
    cout << " true  | false | " << (true && false) << endl;
    cout << " true  | true  | " << (true && true) << endl;
	
    cout << endl;

    // Examining Logical OR:
    cout << "OR Truth Table:" << endl << endl;

    cout << "   A   |   B   |  A || B  " << endl;
    cout << "-------+-------+----------" << endl;
    cout << " false | false | " << (false || false) << endl;
    cout << " false | true  | " << (false || true) << endl;
    cout << " true  | false | " << (true || false) << endl;
    cout << " true  | true  | " << (true || true) << endl;

    cout << endl;

    // Examining Logical NOT:
    cout << "NOT Truth Table:" << endl << endl;

    cout << "   A   |   !A    " << endl;
    cout << "-------+--------" << endl;
    cout << " false | " << (!false) << endl;
    cout << " true  | " << (!true) << endl;

    int iTemp;
    cin >> iTemp;

    return (0);
}
```

## 2.3 Logical Operators

```C++
#include <iostream>

using namespace std;

int main()
{
    // Sets the cout output bool flag to TRUE or FALSE values
    // instead of 1 or 0.
    cout.setf(ios_base::boolalpha);

    bool B0 = false;
    bool B1 = false;
    bool B2 = false;

    cout << "Enter 0 for false or 1 for true: ";
    cin >> B0;

    cout << "Enter 0 for false or 1 for true: ";
    cin >> B1;

    cout << "Enter 0 for false or 1 for true: ";
    cin >> B2;

    bool notB0 = !B0;
    bool notB1 = !B1;
    bool notB2 = !B2;

    bool isB0AndB1 = B0 && B1;
    bool isB0AndB1AndB2 = B0 && B1 && B2;

    bool isB0OrB1 = B0 || B1;
    bool isB1OrB2 = B1 || B2;
    
    // Exclusive OR.
    bool isB0ExclOrB1 = (B0 || B1) && !(B0 && B1);

    // Complex logical expression.
    bool isComplex = (B0 && (B1 || B2)) && !((B0 && B1) || (B0 && B2));

    cout << "B0             == " << B0 << endl;
    cout << "B1             == " << B1 << endl;
    cout << "B2             == " << B2 << endl;

    cout << "Not B0         == " << notB0 << endl;
    cout << "Not B1         == " << notB1 << endl;
    cout << "Not B2         == " << notB2 << endl;

    cout << "isB0AndB1      == " << isB0AndB1 << endl;
    cout << "isB0AndB1AndB2 == " << isB0AndB1AndB2 << endl;

    cout << "isB0OrB1       == " << isB0OrB1 << endl;
    cout << "isB1OrB2       == " << isB1OrB2 << endl;

    cout << "isB0ExclOrB1   == " << isB0ExclOrB1 << endl;
    cout << "isComplex      == " << isComplex << endl;

    int iTemp;
    cin >> iTemp;

    return (0);
}

```

## 2.4 If Statements

```C++
#include <iostream>

using namespace std;

int main()
{
    float fNum = 0.0f;
    cout << "Enter the player's health: ";
    cin >> fNum;

    if (fNum > 0)
    {
        // If the player's health is above 0.

        cout << "Player is still alive. Continue Game.";
        cout << endl;
    }
    else
    {
        // Player's health is less than or equal to 0.
        // The player should be dead!

        cout << "Player's health is less than 0. ";
        cout << "Decrement lives. Restart level.";
        cout << endl;
    }

    // Wait for input, stops the Command Prompt closing automatically.
    int iTemp;
    cin >> iTemp;

    return (0);
}
```

## 2.5 Switch

```C++
#include <iostream>

using namespace std;

int main()
{
    int iNum = 0;

    cout << "Enter an even number in the range [2, 8]: ";
    cin >> iNum;

    switch(iNum) // Evaluate the value in num.
    {
        case 2:
        {
            cout << "You entered 2." << endl;
            break; // Steps out of condition.
        }
        case 4:
        {
            cout << "You entered 4." << endl;
            break;
        }
        case 6:
        {
            cout << "You entered 6." << endl;
            break;
        }
        case 8:
        {
            cout << "You entered 8." << endl;
            break;
        }
        default:
        {
            cout << "Input does not match what we expected.";
            cout << endl;
            cout << "Program asked for 2, 4, 6, or 8." << endl;
            break;
        }
    }

    // Wait for input, stops the Command Prompt closing automatically.
    int iTemp;
    cin >> iTemp;

    return (0);
}

```

## 2.6 Switch, with fall through

```C++
#include <iostream>

using namespace std;

int main()
{
    cout << "Start Playing..." << endl;

    bool bPlaying = true;

    char cInput = 0;

    cout << "Continue playing? ";
    cin >> cInput;
    cout << endl;

    switch (cInput)
    {
        case 'y': //Fall Through.
        case 'Y':
        {
            cout << "Continue..." << endl;
            break;
        }
        case 'n': //Fall Through.
        case 'N':
        {
            bPlaying = false;
            break;
        }
        default:
        {
            cout << "Unknown input!";
            cout << endl;
            break;
        }
    }

    if (bPlaying)
    {
        cout << "The Game Continues!" << endl;
    }
    else
    {
        cout << "Game Over!" << endl;
    }

    // Wait for input, stops the Command Prompt closing automatically.
    int iTemp;
    cin >> iTemp;

    return (0);
}
```

## 2.7 Enumerated constants

```C++
#include <iostream>

using namespace std;

enum EDAY
{
    Monday, 
    Tuesday, 
    Wednesday, 
    Thursday, 
    Friday, 
    Saturday, 
    Sunday, 
    
    EDAY_MAX
};

int main()
{
    const EDAY myFavouriteDay = Friday;
    const EDAY today = Wednesday;

    if (Friday == today)
    {
        cout << "Hooray! It is Friday!" << endl;
    }
    else if (today > Friday)
    {
        cout << "A relaxing weekend day." << endl;
    }
    else
    {
        cout << "Have to go to school today..." << endl;
    }

    if (myFavouriteDay == today)
    {
        cout << "Today is my favourite day!!!" << endl;
    }

    int iTemp = 0;
    cin >> iTemp;

    return (0);
}
```
