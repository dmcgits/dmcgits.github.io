#include <iostream>

using namespace std;

enum EDAY
{
    Monday,
    Tuesday,
    Wednesday, 
    Thursday, 
    Friday, 
    Saturday, 
    Sunday,

    EDAY_MAX
};

int main()
{
    const EDAY myFavouriteDay = Friday;

    for (int today = Monday ; today < EDAY_MAX ; ++today)
    {
        if (Friday == today)
        {
            cout << "Hooray! It is Friday!" << endl;
        }
        else if (today > Friday)
        {
            cout << "A relaxing weekend day." << endl;
        }
        else
        {
            cout << "Have to go to school today..." << endl;
        }

        if (myFavouriteDay == today)
        {
            cout << "Today is my favourite day!!!" << endl;
        }
    }

    // Wait for input, stops the Command Prompt closing automatically.
    int iTemp;
    cin >> iTemp;

    return (0);
}
