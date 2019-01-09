# ConsoleScreenAPI
[Double buffering] windows console screen API (C, C++)

## void ScreenInit()
Initialize back and front screen buffer

## void SetColor(unsigned short color)
Change screen color

## void ScreenClear()
Clear back screen buffer

## void ScreenPrint(int x, int y, const char *text)
Textout with coordinate on the screen

## void ScreenFlipping()
Swap back buffer and front buffer

## void ScreenRelease()
Release screen buffer
