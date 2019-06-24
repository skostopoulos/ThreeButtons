#include "pch.h"
#include "GameManager.h"
#include "Game.h"

using namespace std;


void GameManager::initGame() {

	ConsoleDisplay::greetUser();
	m_game = new Game();

}

void GameManager::startGame()
{
	m_game->play();
	if (m_game->userWins()) {
		m_restart_game = true;
	}
}

bool GameManager::restartGame()
{
	delete m_game;
	return m_restart_game;
}

