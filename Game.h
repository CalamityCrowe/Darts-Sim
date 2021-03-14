#pragma once
#include "Player.h"
#include "Rules.h"
class Game
{
private:
	int CurrentGame;
	int MaxGames;
	int turn;
	Player Players[2];
	Rules ActiveRules;
	int DartBoard[2][21] = { {0, 20, 15, 17, 18, 12, 13, 19, 16, 14, 6, 8, 9, 4, 11, 10, 7, 2, 1, 3, 5},
							{0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
	
protected:

public:
	Game();
	Game(Rules);
	~Game();

	
	void SetPlayers();
	void Playing();
	void Playing301();
	void DisplayCurrentRoundResults(int);
	void Playing501();
	void PlayerContGame();
	void AI_501(int i);
	void SetGames();
	void DisplayResults();
	void Reset();
	void ChangeRules(Rules);

	int EnterValueForTarget(char);
};

