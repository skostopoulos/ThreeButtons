#include "pch.h"
#include <ctime>
#include <iostream>
#include <windows.h>

#include "Game.h"
#include "ConsoleDisplay.h"

using namespace std;

Game::Game()
{
	generateRandomSequence();
}

void Game::play() {


	m_display->clearScreen();
	m_display->displayBoard();

	// Save user's guess
	for (int i = 0; i < num_of_buttons; i++) {
		do {
			m_display->promptUserToGuess();
			std::cin >> m_user_guess[i];
		} while (!inputCorrect(toupper(m_user_guess[i])));
	}


	// Make all letters uppercase
	for (int i = 0; i < num_of_buttons; i++) {
		m_user_guess[i] = toupper(m_user_guess[i]);
	}


	// Check if player has guessed correctly
	for (int i = 0; i < num_of_buttons; i++) {
		if (m_user_guess[i] == m_buttons_sequence[i]) {
			m_correct_guesses++;
			m_led_colors[i] = 10; //green
		}
		else {
			if (m_button_exists[m_user_guess[i]]) {
				m_led_colors[i] = 14; // orange
			}
			else {
				m_led_colors[i] = 12;// red
			}
		}
	}

	// Print results
	m_display->printResult(m_led_colors);

	// check if the game should be restarted
	if (m_correct_guesses == num_of_buttons) {
		m_user_wins = true;
		m_display->printWinMessage();
	}

}

bool Game::userWins()
{
	return m_user_wins;
}


// Private functions

void Game::generateRandomSequence()
{
	srand(time(0));

	for (int i = 0; i < 3; i++) {
		m_buttons_sequence[i] = 'A' + rand() % num_of_buttons;
		// set the exist flag for this letter to true
		m_button_exists[m_buttons_sequence[i]] = true;
	}
}

bool Game::inputCorrect(char guess)
{	
	bool retval = false; 
	
	m_display->clearScreen();
	m_display->displayBoard();

	if (guess == 'A' || guess == 'B' || guess == 'C') {
		retval = true;
	}
	else {
		m_display->printWrongInputMessage();
	}

	return retval;
}

