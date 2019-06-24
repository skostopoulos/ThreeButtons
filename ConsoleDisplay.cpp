#include "pch.h"
#include <Windows.h>
#include <iostream>
#include "ConsoleDisplay.h"

using namespace std;

void ConsoleDisplay::greetUser() {

	char username[100];

	cout << "################################################################################" << endl;
	cout << "#                                                                              #" << endl;
	cout << "# ##   ##  ######  ##       ####    ####   ##   ##  ######      ######  ####   #" << endl;
	cout << "# ##   ##  ##      ##      ##  ##  ##  ##  ### ###  ##            ##   ##  ##  #" << endl;
	cout << "# ## # ##  ####    ##      ##      ##  ##  ## # ##  ####          ##   ##  ##  #" << endl;
	cout << "# #######  ##      ##      ##  ##  ##  ##  ##   ##  ##            ##   ##  ##  #" << endl;
	cout << "#  ## ##   ######  ######   ####    ####   ##   ##  ######        ##    ####   #" << endl;
	cout << "#                                                                              #" << endl;
	cout << "#      #####      #####   ##  ##  ######  ######  ######  ##  ##   ####        #" << endl;
	cout << "#          ##     ##  ##  ##  ##    ##      ##    ##  ##  ### ##  ##           #" << endl;
	cout << "#       ####      #####   ##  ##    ##      ##    ##  ##  ######   ####        #" << endl;
	cout << "#          ##     ##  ##  ##  ##    ##      ##    ##  ##  ## ###      ##       #" << endl;
	cout << "#      #####      #####    ####     ##      ##    ######  ##  ##   ####        #" << endl;
	cout << "#                                                                              #" << endl;
	cout << "################################################################################" << endl;

	cout << endl << endl << endl;
	cout << "              Please enter your name: ";
	do {
		cin >> username;
	} while (cin.fail());
	cout << endl;
	cout << "Hi " << username << ", nice to see you. Let's begin!" << endl << endl;

}


void ConsoleDisplay::displayBoard() {

	cout << "   .----------------.      .----------------.       .----------------.  " << endl;
	cout << "  | .--------------. |    | .--------------. |     | .--------------. | " << endl;
	cout << "  | |      __      | |    | |   ______     | |     | |     ______   | | " << endl;
	cout << "  | |     /  \\     | |    | |  |_   _ \\    | |     | |   .' ___  |  | | " << endl;
	cout << "  | |    / /\\ \\    | |    | |    | |_) |   | |     | |  / .'   \\_|  | | " << endl;
	cout << "  | |   / ____ \\   | |    | |    |  __'.   | |     | |  | |         | | " << endl;
	cout << "  | | _/ /    \\ \\_ | |    | |   _| |__) |  | |     | |  \\ `.___.'\\  | | " << endl;
	cout << "  | ||____|  |____|| |    | |  |_______/   | |     | |   `._____.'  | | " << endl;
	cout << "  | |              | |    | |              | |     | |              | | " << endl;
	cout << "  | '--------------' |    | '--------------' |     | '--------------' | " << endl;
	cout << "   '----------------'      '----------------'       '----------------'  " << endl;
	cout << endl << endl << endl;
	cout << "            The above three buttons have been pressed 3 times." << endl;
	cout << "     Can you guess which buttons and in what order they were pressed?" << endl << endl << endl;

}

void ConsoleDisplay::promptUserToGuess()
{
	cout << "Take a guess: ";
}

void ConsoleDisplay::clearScreen()
{
	COORD tl = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO s;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &s);
	DWORD written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(console, ' ', cells, tl, &written);
	FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(console, tl);
}


void ConsoleDisplay::printWrongInputMessage() {
	cout << "Incorrect input! You have to pick one of three following letters:";
	cout << "    A, B, C  " << endl;
	cout << " (it's easy as A, B, C)    :) " << endl;
}

void ConsoleDisplay::printResult(int *colors)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < num_of_buttons; i++) {
		SetConsoleTextAttribute(hConsole, colors[i]);
		cout << "  O   ";
	}
	
	cout << endl;
	//reset text color to white
	SetConsoleTextAttribute(hConsole, 15);
}


void ConsoleDisplay::printWinMessage() {

	cout << " YOU WIN!!! " << endl;

	cout << "           Thanks for playing!\n\n";
	cout << "           Let's play again!\n\n";

}

