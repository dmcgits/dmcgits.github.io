#include <iostream>
// This function has an argument, degrees, of type int.
using namespace std;

int _rotation = 0;

void turnRight( int degrees = 90 )
{
	_rotation -= degrees;
	return;
}

int main()
{
	cout << "Rotation:  " << _rotation << endl;
	turnRight(15); // calling with no argument..
	cout << "Rotation:  " << _rotation << endl;
	turnRight();
	cout << "Rotation:  " << _rotation << endl;
	return 0;
}