#pragma once
#ifndef _GAME_H
#define _GAME_H

#include "pch.h"
#include<unordered_map>

#include "ConsoleDisplay.h"

#define num_of_buttons 3

class ConsoleDisplay;

class Game {
public:

	Game();

	void play();
	bool userWins();

private:
	void generateRandomSequence();

	char m_buttons_sequence[num_of_buttons] = { '0' };
	char m_user_guess[num_of_buttons];
	bool m_user_wins = false;
	int m_correct_guesses = 0;
	int m_led_colors[3] = { 0 };
	ConsoleDisplay* m_display;

	std::unordered_map<char, int> m_button_exists = {
		{'A', false},
		{'B', false},
		{'C', false}
	};

	bool inputCorrect(char guess);

};

#endif _GAME_H