#pragma once
#pragma comment(lib, "winmm.lib")
#include <Windows.h>
#include <chrono>
#include <functional>
#include <algorithm>

#ifndef __EIGHTIES_GAME__
#define __EIGHTIES_GAME__
using namespace std;
using namespace std::chrono;

enum Color
{
  FG_BLACK = 0x0000,
  FG_DARK_BLUE = 0x0001,
  FG_DARK_GREEN = 0x0002,
  FG_DARK_CYAN = 0x0003,
  FG_DARK_RED = 0x0004,
  FG_DARK_MAGENTA = 0x0005,
  FG_DARK_YELLOW = 0x0006,
  FG_GREY = 0x0007, // Thanks MS :-/
  FG_DARK_GREY = 0x0008,
  FG_BLUE = 0x0009,
  FG_GREEN = 0x000A,
  FG_CYAN = 0x000B,
  FG_RED = 0x000C,
  FG_MAGENTA = 0x000D,
  FG_YELLOW = 0x000E,
  FG_WHITE = 0x000F,
  BG_BLACK = 0x0000,
  BG_DARK_BLUE = 0x0010,
  BG_DARK_GREEN = 0x0020,
  BG_DARK_CYAN = 0x0030,
  BG_DARK_RED = 0x0040,
  BG_DARK_MAGENTA = 0x0050,
  BG_DARK_YELLOW = 0x0060,
  BG_GREY = 0x0070,
  BG_DARK_GREY = 0x0080,
  BG_BLUE = 0x0090,
  BG_GREEN = 0x00A0,
  BG_CYAN = 0x00B0,
  BG_RED = 0x00C0,
  BG_MAGENTA = 0x00D0,
  BG_YELLOW = 0x00E0,
  BG_WHITE = 0x00F0,
};

enum class PixelType {
  PIXEL_SOLID = 0x2588,
  PIXEL_THREEQUARTERS = 0x2593,
  PIXEL_HALF = 0x2592,
  PIXEL_QUARTER = 0x2591,
};

class OlcBits
{
public:
  int screenWidth;
  int screenHeight;
  int fontWidth = 12;
  int fontHeight = 12;
  time_point<system_clock> tp1 = system_clock::now();
  time_point<system_clock> tp2 = system_clock::now();

  HANDLE console;
  HANDLE consoleIn;
  HANDLE originalConsole;
  SMALL_RECT rectWindow;
  CHAR_INFO *bufScreen;


  int Error(const wchar_t *msg)
  {
    wchar_t buf[256];
    FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), buf, 256, NULL);
    SetConsoleActiveScreenBuffer(originalConsole);
    //wprintf(L"ERROR: %s\n\t%s\n", msg, buf); FIX
    return 0;
  }

  static BOOL CloseHandler(DWORD evt)
  {
    // Note this gets called in a seperate OS thread, so it must
    // only exit when the game has finished cleaning up, or else
    // the process will be killed before OnUserDestroy() has finished
    if (evt == CTRL_CLOSE_EVENT)
    {
      //m_bAtomActive = false;

      // Wait for thread to be exited
      //std::unique_lock<std::mutex> ul(m_muxGame);
      //m_cvGameFinished.wait(ul);
    }
    return true;
  }

  int setupConsole(int width = 20, int height = 20, int characterWidth = 12, int characterHeight = 12)
  {
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    consoleIn = GetStdHandle(STD_INPUT_HANDLE);

    fontWidth = characterWidth;
    fontHeight = characterHeight;
    if (console == INVALID_HANDLE_VALUE)
      return Error(L"Bad Handle");

    screenWidth = width;
    screenHeight = height;

    // Update 13/09/2017 - It seems that the console behaves differently on some systems
    // and I'm unsure why this is. It could be to do with windows default settings, or
    // screen resolutions, or system languages. Unfortunately, MSDN does not offer much
    // by way of useful information, and so the resulting sequence is the reult of experiment
    // that seems to work in multiple cases.
    //
    // The problem seems to be that the SetConsoleXXX functions are somewhat circular and 
    // fail depending on the state of the current console properties, i.e. you can't set
    // the buffer size until you set the screen size, but you can't change the screen size
    // until the buffer size is correct. This coupled with a precise ordering of calls
    // makes this procedure seem a little mystical :-P. Thanks to wowLinh for helping - Jx9

    // Change console visual size to a minimum so ScreenBuffer can shrink
    // below the actual visual size
    rectWindow = { 0, 0, 1, 1 };
    SetConsoleWindowInfo(console, TRUE, &rectWindow);

    // Set the size of the screen buffer
    COORD coord = { (short)screenWidth, (short)screenHeight };
    if (!SetConsoleScreenBufferSize(console, coord))
      Error(L"SetConsoleScreenBufferSize");

    // Assign screen buffer to the console
    if (!SetConsoleActiveScreenBuffer(console))
      return Error(L"SetConsoleActiveScreenBuffer");

    // Set the font size now that the screen buffer has been assigned to the console
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = fontWidth;
    cfi.dwFontSize.Y = fontHeight;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;

    /*	DWORD version = GetVersion();
      DWORD major = (DWORD)(LOBYTE(LOWORD(version)));
      DWORD minor = (DWORD)(HIBYTE(LOWORD(version)));*/

      //if ((major > 6) || ((major == 6) && (minor >= 2) && (minor < 4)))		
      //	wcscpy_s(cfi.FaceName, L"Raster"); // Windows 8 :(
      //else
      //	wcscpy_s(cfi.FaceName, L"Lucida Console"); // Everything else :P

      //wcscpy_s(cfi.FaceName, L"Liberation Mono");
    wcscpy_s(cfi.FaceName, L"Consolas");
    if (!SetCurrentConsoleFontEx(console, false, &cfi))
      return Error(L"SetCurrentConsoleFontEx");

    // Get screen buffer info and check the maximum allowed window size. Return
    // error if exceeded, so user knows their dimensions/fontsize are too large
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(console, &csbi))
      return Error(L"GetConsoleScreenBufferInfo");
    if (screenHeight > csbi.dwMaximumWindowSize.Y)
      return Error(L"Screen Height / Font Height Too Big");
    if (screenWidth > csbi.dwMaximumWindowSize.X)
      return Error(L"Screen Width / Font Width Too Big");

    // Set Physical Console Window Size
    rectWindow = { 0, 0, (short)screenWidth - 1, (short)screenHeight - 1 };
    if (!SetConsoleWindowInfo(console, TRUE, &rectWindow))
      return Error(L"SetConsoleWindowInfo");

    // Set flags to allow mouse input		
    if (!SetConsoleMode(consoleIn, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT))
      return Error(L"SetConsoleMode");

    // Allocate memory for screen buffer
    bufScreen = new CHAR_INFO[screenWidth*screenHeight];
    memset(bufScreen, 0, sizeof(CHAR_INFO) * screenWidth * screenHeight);

    SetConsoleCtrlHandler((PHANDLER_ROUTINE)CloseHandler, TRUE);
    return 1;
  }

  void drawBufferToConsole()
  {
    WriteConsoleOutput(console, bufScreen, { (short)screenWidth, (short)screenHeight }, { 0,0 }, &rectWindow);
  }

  void drawCharacter(int x, int y, short c = 0x2588, Color col = Color::FG_WHITE)
  {
    if (x >= 0 && x < screenWidth && y >= 0 && y < screenHeight)
    {
      bufScreen[y * screenWidth + x].Char.UnicodeChar = c;
      bufScreen[y * screenWidth + x].Attributes = (short)col;
    }
  }

  float getTimeSinceLastFrame()
  {
    tp2 = std::chrono::system_clock::now();
    std::chrono::duration<float> elapsedTime = tp2 - tp1;
    tp1 = tp2;
    return(elapsedTime.count());

  }

  void drawString(int x, int y, std::wstring c, Color fgColor = Color::FG_WHITE, Color bgColor = Color::BG_BLACK)
  {
    for (size_t i = 0; i < c.size(); i++)
    {
      bufScreen[y * screenWidth + x + i].Char.UnicodeChar = c[i];
      bufScreen[y * screenWidth + x + i].Attributes = (short)fgColor | (short)bgColor;
    }
  }

  void drawRow(int y, Color color = Color::FG_WHITE)
  {
    for (int x = 0; x < screenWidth; x++)
    {
      drawCharacter(x, y, 0x2588, color);
    }
  }

  void drawPixel(int x, int y, Color colour = Color::FG_WHITE)
  {
    drawCharacter(x, y, 0x2588, colour);
  }

};

OlcBits engine;

// should  work why error?
//std::function<void(int, int, short)> drawPixel = engine.drawPixel;

int setupWindow (int w, int h, int pw, int ph) 
{
  return engine.setupConsole(w, h, pw, ph);
}

void renderWindow() 
{
  engine.drawBufferToConsole();
}

float getTimeElapsed() {
  return engine.getTimeSinceLastFrame();
}

void printWString(int x, int y, std::wstring aWString, Color fgColor = Color::FG_WHITE, Color bgColor = Color::BG_BLACK) 
{
  engine.drawString(x, y, aWString, fgColor, bgColor);
}

void drawPixel(int x, int y, Color color)
{
  engine.drawPixel(x, y, color);
}

//auto dpfunc = std::bind(&OlcBits::drawPixel, &engine, placeholders::_1, placeholders::_2, placeholders::_3);

//typedef void(*DrawPixelFunction)(int x, int y, Color color);

//typedef void(OlcBits::*DrawPixelFunction)(int x, int y, Color color);

//DrawPixelFunction dP = &OlcBits::drawPixel;


//auto dpix = OlcBits::drawPixel;

//DrawPixelFunction drawPix = &(engine.drawPixel);

//void(*setupCon) = &engine.setupConsole;
//void *setupCon = &engine.setupConsole;
//void (*drawPixel) = &(engine.drawPixel);
//void &setupCons() = engine.setupConsole;
#endif