#include <iostream>
#include <time.h>     // Including the C++ time library gives us the time(x) function

using namespace std;

int main()
{
  int secretNumber = 0;       // Declaring an integer variable to hold the secret number

  srand(time(0));             // Seed the C++ random number generator with current time.
  secretNumber = rand() % 6;  // Any number divided by 6 has a remainder from 0-5. 

  cout << "The secret Number between 0 and 5 is: ";
  cout << secretNumber;
  cout << endl;           // Asking console to go to the next line.

  return (0);
}
