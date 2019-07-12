#include <iostream>
#include <Windows.h>
using namespace std;

enum HadokenType
{
  AIR_HADOKEN,
  FIRE_HADOKEN,
  METSU_HADOKEN
};

void throwHadoken( HadokenType type )
{
  switch(type)
  {
    case AIR_HADOKEN:
      cout << ("\tAIR HADOKEN!! ~~~~*O}\n\n");
      break;
    case FIRE_HADOKEN:
      cout << ("\tFIRE HADOKEN!! ~~~~33}}\n\n");
      break;
  }
  return;
}

int main()
{
    cout << "\n\n\tPress A for air hadoken, F for fire hadoken, Q for Quit. \n\n";

    bool userHasQuit = false;
    bool aIsHeld = false;
    bool fIsHeld = false;
    
    while ( !userHasQuit )
    {
      if  (GetKeyState('A') & 0x8000)
      {
        // if a isn't already down, throw a fireball
        if (!aIsHeld)
        {
          aIsHeld = true;
          throwHadoken( AIR_HADOKEN );
        }
      } else {
        if (aIsHeld) aIsHeld = false;
      }

      if  (GetKeyState('F') & 0x8000)
      {
        // if a isn't already down, throw a fireball
        if (!fIsHeld)
        {
          fIsHeld = true;
          throwHadoken( FIRE_HADOKEN );
        }
      } else {
        if (fIsHeld) fIsHeld = false;
      }

      if  (GetKeyState('Q') & 0x8000)
      {
        userHasQuit = true;
      }
      
    }
    return(0);
    
}