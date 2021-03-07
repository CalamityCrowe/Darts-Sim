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

	while (!RulesSet)
	{
		cout << "What rules would you like to play\n\n 1 = 301 rules	2 = 501 rules\n\n";

		cin >> Key;

		switch (Key)
		{
		case '1':
			Active = threezeroonerules();
			cout << "Rules have been set to 301\n\n";
#if _DEBUG
			cout << "THE START SCORE:" << Active.getSTARTSCORE() << "\n\n";
#endif 
			RulesSet = true;
			break;
		case '2':
			Active = fivezeroonerules();
			cout << "Rules have been set to 501\n\n";
#if _DEBUG
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


	currentGame = Game(Active);
	currentGame.SetPlayers();

	//cout << "I think you're a nazi.\n\nThat's great. I think you're a prick\n\n";

}



