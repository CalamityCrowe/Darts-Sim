#pragma once
#include "Player.h"
#include "Rules.h"
#include "Game.h"

int main()
{
	Rules Active;
	Game currentGame;
	char Key;
	bool RulesSet = false;

	srand(time(NULL));// sets up the random number

#pragma region set the initial rules of the game
	while (!RulesSet)
	{
		cout << "What rules would you like to play\n\n 1 = 301 rules	2 = 501 rules	3 = 501 rules(Player controlled)\n\n";

		cin >> Key;

		switch (Key) // sets the rules for the current game
		{
		case '1':
			Active = threezeroonerules();
#if _DEBUG
			cout << "Rules have been set to 301\n\n";
			cout << "THE START SCORE:" << Active.getSTARTSCORE() << "\n\n";
#endif 
			RulesSet = true;
			break;
		case '2':
			Active = fivezeroonerules(0);
#if _DEBUG
			cout << "Rules have been set to 501\n\n";
			cout << "THE START SCORE:" << Active.getSTARTSCORE() << "\n\n";
#endif 
			RulesSet = true;
			break;
		case '3':
			Active = fivezeroonerules(1);
#if _DEBUG
			cout << "Rules have been set to 501 PlayerControlled\n\n";
			cout << "THE START SCORE:" << Active.getSTARTSCORE() << "\n\n";
#endif 
			RulesSet = true;
			break;
		default:

			system("CLS");
			cout << "The input was invalid. please try again\n\n";

			break;
		}


	}
#pragma endregion

	currentGame = Game(Active);
	currentGame.SetPlayers();
	currentGame.Playing();

	//cout << "I think you're a nazi.\n\nThat's great. I think you're a prick\n\n";

}



