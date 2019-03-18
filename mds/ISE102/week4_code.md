# Week 4 Exercises

Functions

## Code

Type these in, don't cut and paste!

#### 4.1 Scope

```c++
#include <iostream>
using namespace std;

int main()
{
    int x = 9;

    for (int i = 0; i < 1; i++)
    {
        int j = 77;

        cout << "----------------------" << endl;
        cout << "Inside of the for loop" << endl;
        cout << "----------------------" << endl;

        cout << "Value in x = " << x << endl;
        cout << "Value in i = " << i << endl;
        cout << "Value in j = " << j << endl;
    }

    cout << "-----------------------" << endl;
    cout << "Outside of the for loop" << endl;
    cout << "-----------------------" << endl;

    cout << "Value in x = " << x << endl;
//    cout << "Value in i = " << i << endl;
//    cout << "Value in j = " << j << endl;

    // Wait for input, stops the Command Prompt closing automatically.
    int iTemp;
    cin >> iTemp;

    return (0);
}
```
___

#### 4.2 Function

```c++

#include <iostream>
using namespace std;

float Area()
{
    float fPI = 3.14f;
    float fRadius = 0.0f;

    cout << "Enter a radius of a circle: ";
    cin >> fRadius;

    float fArea = fPI * fRadius * fRadius;

    return (fArea);
}

int main()
{
    cout << "Area = " << Area() << endl;

    // Do some other work.
    cout << "Other work..." << endl;

    cout << "Area = " << Area() << endl;

    // Do some other work.
    cout << "Other work..." << endl;

    cout << "Area = " << Area() << endl;

    // Wait for input, stops the Command Prompt closing automatically.
    int iTemp;
    cin >> iTemp;

    return (0);
}

```

___

#### 4.3 Function with prototype (definition) 


```c++
#include <iostream>
using namespace std;

// Prototype or definition. 
// Just like a variable declaration, but with parentheses and arguments.
float cube(float x);

int main()
{
    float input0 = 0.0f;

    cout << "Enter a real number: ";
    cin >> input0;
    cout << input0 << "^3 is = " << cube(input0) << endl;

    float input1 = 0.0f;
    cout << "Enter another real number: ";
    cin >> input1;
    cout << input1 << "^3 is = " << cube(input1) << endl;

    float input2 = 0.0f;
    cout << "Enter a third real number: ";
    cin >> input2;
    cout << input2 << "^3 is = " << cube(input2) << endl;

    // Wait for input, stops the Command Prompt closing automatically.
    int iTemp;
    cin >> iTemp;

    return (0);
}

float cube(float x)
{
    float fResult = x * x * x; // x^3 = x * x * x

    return (fResult);
}

```

___

#### 4.1 Scope

```c++
```

___

#### 4.1 Scope

```c++
```

___

#### 4.1 Scope

```c++
```

___

#### 4.1 Scope

```c++
```
