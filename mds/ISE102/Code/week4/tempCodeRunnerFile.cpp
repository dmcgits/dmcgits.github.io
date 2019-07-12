#include <iostream>
using namespace std;

struct Point {
	float x = 0;
	float y=0;
};

float getLookAtAngle(Point pointFrom, Point pointTo)
{

}

int main()
{
	Point myPosition = { 3.5, 2.5 };
	Point targetPosition = { 6.0, 8.0 };
	getLookAtAngle(myPosition, targetPosition);

	return (0);
}