#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H

class Game;

class GameManager {
public:
	void initGame();
	void startGame();
	bool restartGame();

private:
	Game *m_game;
	bool m_restart_game = false;
};

#endif _GAMEMANAGER_H