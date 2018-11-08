# Lecture 8: File I/O

Topics:
>1. File Input and Output
>2. Text files:
>    * Reading (loading), Writing (saving)
>3. Binary files:
>    * Reading (loading), Writing (saving)
>4. Exercises

## Streams beyond cin and cout

A stream lets us flow data from A to B. We did it before with ```cout```, now we'll do it with ```ofstream``` and ```ifstream```.

**std::cout**
A stream of data flows from our program to the console window for display.

**std::cin**
The stream flows from the keyboard into our program.

**std::ofstream**
Sets up a stream to flow data from our application into a file.

**std::ifstream**  
The reverse of ofstream: flow data from the file to our application.

## Opening a file

To access ```std::ofstream``` and ```std:ofstream``` you'll need to:

```C++
#include <fstream>
```

and we'll use its member function ```open(filename)```

```C++
    myFileStream.open(filename, mode);

    /// Notice mode: we can add flags here to change how the file stream works
    /// The are bits, you can combine them with the bitwise OR operator: | 
    ios::in     // Open for input
    ios::out    // Open for output
    ios::binary // Open in binary mode
    ios::ate    // Start At The End of the file
    ios::app    // Open for appending to end of file.
    ios::trunc  // If the file already exists, replace its content with ours.
```

To check the file opened you can call ```is_open()```. It's a ```bool```, returning ```true``` or ```false```.

```C++
if (myFile.is_open())
{
    //SUCCESS
}
```

## Closing a file

Close a file when you're done to free up memory and release the disk. 

```C
myFile.close();
```

Opening a file locks it for other users, so calling ```close()``` lets other processes access, and frees your stream object to open another file.

# Text files  

Text files are expected to be entirely filled with characters that can displayed in a text editor or terminal. 

  * This could mean _ASCII_, _unicode_ (a superset of _ASCII_) or other text encodings. 
  * The ```ios::binary``` flag won't be set.

## File I/O code - Outputting text

Putting it all together. Here we'll just say "myFile" as it's shorter than myFileStream, but it remains a stream.

```C++
#include <iostream>
#include <fstream>

int main()
{
    std::ofstream myFile; // output file stream
    myFile.open("highscores.txt");
    myFile << "High Score Table." << std::endl;
    myFile.close();

    return(0);
}
```

## Input

A function called ```eof()``` lets you check if you've reached the end:

```C++
while ( !myFile.eof() )
    // read a line
}
```
and, helpfully, ```ifstream``` behaves like ```cin``` so we can use getLine

```C++
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string strLine;
    std::ifstream myFile;

    myFile.open("example.txt");
    if (myFile.is_open())
    {
        while (!myFile.eof())
        {
            std::getline(myFile, strLine);
            std::cout << strLine << std::endl;
        }
        
        myFile.close();
    }

    return (0);
}
```

## Checking the stream status

These functions on the fstream flag problems. A "flag" in computer science has its origins in how we use flags in the physical world (mostly before the invention of the bulb) to send a clear, unambiguous signal. Red flags were once used as a flood warning, or an an all stop signal on railways; a yellow flag in auto racing signals danger, a checkered flag signals the end of a race.

Flags in programming are often individual bits set in one or more bytes, but rather than memorise the meanings we can often call boolean-returning functions.  This is how our file stream tells us if it's in trouble:

```C++
    // bad() returns True if reading/writing fails 
    // eg: writing to a closed file or drive full
    myFileStream.bad();

    // fail() is like bad() but is true if a data format problem comes up
    // eg: expecting a numerical value and finding an alphabetical
    myFileStream.fail();

    // eof() == True if the end of the file was reached
    myFileStream.eof();

    // good() is True when all the other flags are false. 
    // Saves typing this: !(bad() || fail() || eof())
    myFileStream.good();
```

## Moving through the stream

All i/o streaming objects inherit their characteristics from ```<iostream>```.
* ```ifstream``` inherits a **get pointer**, that points to the next byte to be read from the input stream. 
* ```ofstream``` inherits a **put pointer**, you can probably guess what this does
* ```iofstream``` is the parent of both ifstream and ofstream. It can read and write to a stream, so it has both **get and put pointers**.

These pointers can also be moved with member functions.

```C++
    std::iofstream myFileStream;
    myFileStream.open("file.txt");

    // tellg() returns our get pointer, an integer representing our current get-data stream position.
    long getPointer = myFileStream.tellg(); 

    // putg() does the same but for our put pointer.
    long putPointer = myFileStream.putg();

    // seekg( position ) positions our get point
    myFileStream().seekg(0, std::ios::end);

    // seekp( position ).. I think you get it.
    // The stream pointer is changed to the absolute position, 
    // counting from the beginning of the file
    myFileStream().seekp( putPointer-7 );

    // Handy position pointers ready made for us:
    ios::beg;
    ios::cur;
    ios::end;

    myFileStream.close();
```

An example:

```C++
#include <iostream>
#include <fstream>

int main()
{
    long lBegin;
    long lEnd;

    ifstream myFile("test.txt");

    lBegin = myFile.tellg();
    myFile.seekg(0, ios::end);

    lEnd = myFile.tellg();
    myFile.close();

    cout << "Size is: " << (lEnd – lBegin) << " bytes." << endl;

    return (0);
}
```

# Binary files

Starting with an example

```C++
#include <iostream>
#include <fstream>

ifstream::pos_type size;
char* pMemblock = 0;

int main () 
{
    ifstream file("test.txt", ios::in | ios::binary | ios::ate);

    if (file.is_open())
    {
        size = file.tellg();
        pMemblock = new char[size];
        file.seekg(0, ios::beg);
        file.read(pMemblock, size);
        file.close();

        cout << "the complete file content is in memory" << endl;

        delete[] pMemblock;
        pMemBlock = 0;
    }
    else
    { 
        cout << "Unable to open file" << endl;
    }
  
    return (0);
}
```

## Real disks writes vs buffers

A physical disk write isn't triggered every single time we write a block to the stream. Writing to devices is complicated and particular and handled by the iostream and the operating system, which in most cases know more particulars than we do. 

A filestream has a block of memory and a lot of logic  to sort this in an object of type ```streambuff```. **Our characters/bytes are stored in the buffer until fstream writes to the device** via the operating system.

This write is called a _**syncronization**_.

## Whens and whys of synchronization

Synchronization can happen explicitly, implicitly or due to events outside our view.
Some examples of times a synchronization occurs:
* **When the file is closed:** any remaining buffers are synchronised, pending data is written.
* **When the buffer is full:** they have a certain size limit and when it is reached they are automatically synced.
* **When we use certain manipulators:** flush, endl.
* **When we call sync():** we can explicitly call this to trigger syncronization. It returns 0 unless there is a failure or no buffer, in which case it returns -1.