#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  float posX = 1.4f;
  float posY = 2.6f;

  int cellX = round(posX);    // round returns a float, eg 3.0, 
  int cellY = round(posY);    // so assigning to an int truncates only zeroes

  cout << "posX = " << posX << ", cellX = " << cellX << endl << endl; 
  cout << "posY = " << posY << ", cellY = " << cellY << endl << endl;
}
