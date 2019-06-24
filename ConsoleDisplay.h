#ifndef _CONSOLEDISPLAY_H
#define _CONSOLEDISPLAY_H
#pragma once

#include "pch.h"
#include <string>

class Game;

class ConsoleDisplay {
public:

	static void greetUser();

	void displayBoard();
	void promptUserToGuess();
	void clearScreen();
	void printWrongInputMessage();
	void printWinMessage();
	void printResult(int *colors);

};

#endif CONSOLEDISPLAY_H