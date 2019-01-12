#pragma once

#include <Windows.h>

static int g_nScreenIndex;
static HANDLE g_hScreen[2];

void ScreenInit()
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;

	for(int i=0; i<2; i++)
	{
		g_hScreen[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		SetConsoleCursorInfo(g_hScreen[i], &info);
	}
}

void ScreenFlipping()
{
	SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
	g_nScreenIndex = !g_nScreenIndex;
}

void ScreenClear()
{
	COORD Coor = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 0x1000, Coor, &dw);
}

void ScreenRelease()
{
	CloseHandle(g_hScreen[0]);
	CloseHandle(g_hScreen[1]);
}

void ScreenPrint(int x, int y, const char *text) 
{
	DWORD dw;
	COORD CursorPosition = { (SHORT)x, (SHORT)y };
	WriteConsoleOutputCharacter(g_hScreen[g_nScreenIndex], text, strlen(text), CursorPosition, &dw);
}

void SetColor(unsigned short color)
{
	SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
}