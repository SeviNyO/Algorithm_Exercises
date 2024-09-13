#pragma once
#include <iostream>
using namespace std;
using namespace System;

#define ANCHO 120
#define ALTO 30

void osuChar(int x, int y, char s) {
	Console::SetCursorPosition(x, y);
	cout << s;
}

void osuString(int x, int y, string s) {
	Console::SetCursorPosition(x, y);
	cout << s;
}