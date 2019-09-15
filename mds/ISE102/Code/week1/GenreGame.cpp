#include <iostream>
#include <string>
using namespace std;

// c++ main function
int main()
{
    string genre = "";

    cout << "Please input your favourite game genre." << endl;
    cout << "eg: Farming, Cooking, Dancing, FPS, Strategy, Sports, Fighting, Battle Royale." << endl;
    cout << "Your choice:";
    
    cin >> genre;   // User can type response, we store it under "genre"
    
    cout << genre << " games are the WORST." << endl; // print our response.

    return(0);  // End program and tell windows there were no errors. 
}
