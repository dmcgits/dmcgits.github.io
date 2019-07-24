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