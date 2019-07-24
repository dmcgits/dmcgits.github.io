---
html:
  embed_local_images: false
  embed_svg: true
  offline: false
  toc: undefined
export_on_save:
  html: true
---
# Week 7 ISE code

## Unary operator precedence and conversion during  assignment

```cpp
// Example program
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a1 = 5;
    int a2 = 5;
    
    int x1 = a1++; // a1 current value assigned x1, THEN a1 is incremented.
    // x1 = a1;
    // a1 = a1 + 1;
    
    int x2 = ++a2; // a2 is incremented, then it's new value is assigned to x2.
    // a2 = a2 + 1;
    // x2 = a2;
    
    cout << "x1 = " << x1 << ", x2 = " << x2 << endl; 
    
    cout << "a1 = " << a1 << ", a2 = " << a2 << endl; 
    
    int d = 10;         // whole number
    float e = 2.8f;     // fractional
    
    int w = 0;
    
    float f = d = e;   // converted a float to an integer, then assigned to a float.
    // what order of assigment is there? right to left
    // What happens when you assign a float (e or 2.8f) to an integer? The fraction is simply chopped off, equivalent to Math.floor(e); Math.round(e);
    cout << "f = " << f << endl;
    
    return 0;
}
```

## cassting/conversion

```cpp
// Example program
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int number = 20;
    int divisor = 3;
    
    
    //int c = a % b;
    
    
    //divisor = 3;
        
    float dividend = (float)number / (float)divisor; // two ints divided gives an int result
    // Do i have to declare numbers as floats if i want to divide them later
    // Can I cast(convert) integers to floats at any random time I need them (eg: when I want floating point results from maths)
    
    //string numberOfBalls = "1000";
    //int tenTimesBalls = 10 * to_int(numberOfBalls);
    
    int remainder = number % divisor;
    
    cout << "dividend = " << dividend << endl;  
    cout << "remainder = " << remainder << endl;  
    
    return 0;
}
```

## Booleans

```cpp
#include <iostream>
using namespace std;

int main() {

  // Start here.

  bool isAsleep = false;

  isAsleep = !isAsleep;  // toggle a boolean from T to F or vice versa

  if ( isAsleep ) {
    cout << "Is asleep." << endl;
  }
  else {
    cout << "Is awake." << endl;
  }

  cout << std::boolalpha;
  cout << "isAsleep: " << isAsleep << endl;
  cout << "true: " << true << endl;


}
```