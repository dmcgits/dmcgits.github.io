# Code for Week 5: more function fun

Passing different variable types, default arguments.


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

* [Code for Week 5: more function fun](#code-for-week-5-more-function-fun)
		* [TurnRight.cpp](#turnrightcpp)
		* [PassingValues.cpp](#passingvaluescpp)
		* [PassingArrays.cpp](#passingarrayscpp)
		* [PassingVectors.cpp](#passingvectorscpp)

<!-- /code_chunk_output -->


### TurnRight.cpp

```c++
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
	turnRight(45); // calling with no argument..
	cout << "Rotation:  " << _rotation << endl;
	turnRight();
	cout << "Rotation:  " << _rotation << endl;
	return 0;
}

```

### PassingValues.cpp

Values, say an int or a float, pass a copy to the function.

```c++
void printMyHeight(int someonesHeight)
{
	someonesHeight = 2;
	cout << "SHE'S ONLY " << someonesHeight << " FEET TALL!\n\n";
}

int main()
{
	cout << "How tall are you?\n\n";
	int height = 6;
	printMyHeight(height);

	cout << "Thanks. I'm actually " << height << " feet tall.\n\n";
}
```

### PassingArrays.cpp

Arrays, being weird and difficult, pass themselves rather than a copy. If you change it, you change the original.

```c++
#include <iostream>
using namespace std;

void printMyHeight(int someonesHeight[1])
{
	someonesHeight[0] = 2;
	cout << "SHE'S ONLY " << someonesHeight[0] << " FEET TALL!\n\n";
}

int main()
{
	cout << "How tall are you?\n\n";

	int height[1] = { 6 };
	printMyHeight(height);

	cout << "Thanks. I'm actually " << height[0] << " feet tall.\n\n";
}
```

### PassingVectors.cpp

Another good reason to use vectors. They pass a copy.

```c++
#include <iostream>
#include <vector>
using namespace std;

void printMyHeight(vector<int> someonesHeight)
{
	someonesHeight[0] = 2;
	cout << "SHE'S ONLY " << someonesHeight[0] << " FEET TALL!\n\n";
}

int main()
{
	cout << "How tall are you?\n\n";
	
	vector<int> height = { 6 };
	printMyHeight(height);

	cout << "Thanks. I'm actually " << height[0] << " feet tall.\n\n";
}
```