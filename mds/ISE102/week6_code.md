# Week 6 Code: Pointers and References

Nicknames, passing around addresses. Really we're getting a look behind the curtain at the memory in which our data is stored.

### Getting Memory Addresses

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

### Pointers

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