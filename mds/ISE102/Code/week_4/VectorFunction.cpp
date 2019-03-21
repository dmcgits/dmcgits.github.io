// C++ program to illustrate the 
// capacity function in vector 
#include <iostream> 
#include <vector> 

using namespace std;

vector<int> g1;

void demoVector()
{
    for (int i = 1; i <= 5; i++)
		g1.push_back(i);

	cout << "Size : " << g1.size();
	cout << "\nCapacity : " << g1.capacity();
	cout << "\nMax_Size : " << g1.max_size();

	// resizes the vector size to 4 
	g1.resize(4);

	// prints the vector size after resize() 
	cout << "\nSize : " << g1.size();

	// checks if the vector is empty or not 
	if (g1.empty() == false)
		cout << "\nVector is not empty";
	else
		cout << "\nVector is empty";

	// Shrinks the vector 
	g1.shrink_to_fit();
	cout << "\nVector elements are: ";
	//for (auto it = g1.begin(); it != g1.end(); it++)
	//	cout << *it << " ";
	for (int j = 0; j < g1.size(); j++)
	{
		cout << g1[j] << ", ";
	}

    return;
}

float addTwoNumbers( float numA, float numB )
{
    
    return (numA + numB);
}

int main()
{
	
    demoVector();

    cout << addTwoNumbers(2.5f,5.6f) << endl;

	return 0;
}