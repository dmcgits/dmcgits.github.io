#include <iostream>
using namespace std;

struct Point {
	float x = 0.0f;
	float y=0.0f;
} myPosition, targetPosition;

float getLookAtAngle(Point lookerPoint, Point targetPoint)
{
	// Some hypotenuse findin'
	// Atan2 maths
	return (88.3f);
}

int main()
{
	float angle = 0.0f;
	myPosition.x = 3.5f;
	myPosition.y = 2.5f;
	targetPosition.x = 6.1f;
	targetPosition.y = 8.0f;
	angle = getLookAtAngle(myPosition, targetPosition);

	printf("Got a point angle of %2.2f mate.\n", angle);

	cout << "To look at the point, set rotation to " << getLookAtAngle(myPosition, targetPosition) << endl;

	return(0);
}