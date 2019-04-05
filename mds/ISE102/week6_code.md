# Week 6 Code: Pointers and References

Nicknames, passing around addresses. Really we're getting a look behind the curtain at the memory in which our data is stored.

### Varible Memory Addresses

If you're not on the left side of a variable declaration:
    * `variableName` evaluates to the data stored for that variable
    * `&variableName` evaluates to the address of that variable's data in memory

```cpp
#include <iostream>

using namespace std;

int main()
{
    signed int siNum = 10;
    double dNum = 10.005;
    char cString[] = "Hello Interactive Gaming!";

    cout << "siNum has a value of: " << siNum << endl;
    cout << "siNum is stored at: " << &siNum << endl;
    cout << endl;

    cout << "dNum has a value of: " << dNum << endl;
    cout << "dNum is stored at: " << &dNum << endl;
    cout << endl;

    cout << "cString has a value of: " << cString << endl;
    cout << "cString is stored at: " << &cString << endl;
    cout << endl;

    int iTemp;
    cin >> iTemp;

    return (0);
}
```

### References 1

If you're on the left side of a declaration:
    * `string operaHouse = "Opera House";` declares a variable that will evaluate to "Opera House". Using `=` you can change the string contents later.
    * `int& building = otherVariableName;` creates a reference variable called `building` that evaluates to _whatever data is stored for the `operHouse` variable, and can be used with `=` to change the contents later.
References can't be changed.

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string operaHouse = "Opera House"; 
    string& building = operaHouse;

    cout << "operaHouse: " << operaHouse << endl;
    cout << "building: " << building << endl;

    cout << "\n -Assigning \"Oprah Haus\" to buiding. -" << endl;
    building = "Oprah Haus";

    cout << "operaHouse: " << operaHouse << endl;
    cout << "building: " << building << endl;
}
```

### Pointers Tute Code

```cpp
#include <iostream>

using namespace std;

int main()
{
    bool boolVar = true;
    int intVar = 1977;
    float floatVar = 19.8080f;

    // Declare pointers to each of the vars above.
    bool* boolPtr = &boolVar;
    int* intPtr = &intVar;
    float* floatPtr = &floatVar;

    // Print the normal variables.
    cout << "Value in boolVar is: " << boolVar << endl;
    cout << "Value in intVar is: " << intVar << endl;
    cout << "Value in floatVar is: " << floatVar << endl;

    cout << endl << endl;

    // Print the addresses in the pointers...
    // [32 bit hexadecimal number ]
    cout << "boolPtr = address of boolVar = " << boolPtr << endl;
    cout << "intPtr = address of intVar = " << intPtr << endl;
    cout << "floatPtr = address of floatVar = " << floatPtr << endl;

    int iTemp;
    cin >> iTemp;

    return (0);

}
```

### Gary's Pointers on Pointers

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// declare a variable
	int age = 27;
	// declare a pointer to age (address)
	int* age_p = &age; // assigning the address of age

	cout << "age: " << age << endl;
	cout << "&age: " << &age << endl;


	cout << age_p << endl;
	// print the memory address.
	cout << *age_p << endl;
	// print out the real value of age_p's target

	string gary = "gary";
	string* gary_p = &gary;

	cout << "\n\n gary.size() = " << gary.size() << endl;

	cout << "\n\n (*gary).size() = " << (*gary_p).size() << endl;
	
	cout << "\n\n gary_p->size() = " << gary_p->size() << endl;


	return 0;
}
```