# Week 8 Exercises - File IO, writing data
Here are some samples of code showing how we can use the new C++ syntax and concepts we learned this week. The idea is to manually enter this code yourself and compile. 

1. [Week 8 Exercises - File IO, writing data](#week-8-exercises---file-io-writing-data)
        1. [8.1 Writing to a text file](#81-writing-to-a-text-file)
        2. [8.2 Reading from a text file](#82-reading-from-a-text-file)
        3. [8.3 Writing text: high scores](#83-writing-text-high-scores)
        4. [8.4 Reading text: high scores](#84-reading-text-high-scores)
        5. [8.5 Seek and put](#85-seek-and-put)
        6. [8.6 Write and read](#86-write-and-read)

### 8.1 Writing to a text file

```c++
#include <iostream>
#include <fstream>

int main()
{
    std::ofstream myFile;

    myFile.open("example.txt");

    if (myFile.is_open())
    {
        myFile << "Hello!" << std::endl;
        myFile << "BSENGG!" << std::endl;
    
        myFile.close();
    }

    return (0);
}

```

### 8.2 Reading from a text file

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

### 8.3 Writing text: high scores

```C++
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ofstream myFile;

    const int kiMaxScores = 3;
    std::string highscoreNames[kiMaxScores];
    int highscoreScores[kiMaxScores];

    // Setup Test Data.
    highscoreNames[0] = "Mark";
    highscoreScores[0] = 100;
    highscoreNames[1] = "Alistair";
    highscoreScores[1] = 200;
    highscoreNames[2] = "Kevin";
    highscoreScores[2] = 6000;

    //Write the score file to disk.
    myFile.open("scores.txt");

    if (myFile.is_open())
    {
        for (int i = 0; i < kiMaxScores; ++i)
        {
            myFile << highscoreNames[i] << "=";
            myFile << highscoreScores[i] << std::endl;
        }

        myFile.close();
    }

    return (0);
}

```

### 8.4 Reading text: high scores

```C++
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream myFile;

    myFile.open("scores.txt");

    if (myFile.is_open())
    {
        std::string strLine;

        while (!myFile.eof())
        {
            std::getline(myFile, strLine);

            size_t equalsPos = strLine.find('=');

            std::string strName = strLine.substr(0, equalsPos);
            std::string strScore = strLine.substr(equalsPos + 1,
                                                  strLine.length());

            int iScore = atoi(strScore.c_str());

            //Then put the score in the highscore table...
        }

        myFile.close();
    }

    return (0);
}

```

### 8.5 Seek and put

```C++
#include <iostream>
#include <fstream>

int main()
{
    long lBegin;
    long lEnd;

    std::ifstream myFile("test.txt");

    lBegin = myFile.tellg();
    myFile.seekg(0, std::ios::end);

    lEnd = myFile.tellg();
    myFile.close();

    std::cout << "Size is: " << (lEnd – lBegin) << " bytes." << std::endl;

    return (0);
}

```

### 8.6 Write and read

```C++
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Writing to a Binary File. 
    std::ofstream myOutFile;

    float x = 3.0f;
    float y = 4.0f;
    float z = 5.0f;

    myOutFile.open("myBinary.bin", std::ios::binary);

    if (myOutFile.is_open())
    {
        myOutFile.write(reinterpret_cast<char*>(&x), 4);
        myOutFile.write(reinterpret_cast<char*>(&y), 4);
        myOutFile.write(reinterpret_cast<char*>(&z), 4);

        myOutFile.close();
    }

    // Reading from a Binary File. 
    std::string strLine;
    std::ifstream myInFile;

    float x2 = 0.0f;
    float y2 = 0.0f;
    float z2 = 0.0f;

    myInFile.open("myBinary.bin", std::ios::binary);

    if (myInFile.is_open())
    {
        myInFile.read(reinterpret_cast<char*>(&x2), 4);
        myInFile.read(reinterpret_cast<char*>(&y2), 4);
        myInFile.read(reinterpret_cast<char*>(&z2), 4);

        myInFile.close();
    }

    return (0);
}

```
