#pragma once
#include "Game.h"
#include <string>

Game::Game()
{
	CurrentGame = 0;
	MaxGames = 0;
	turn = 0;
	for (int i = 0; i < 2; i++)
	{
		Players[i] = Player();
	}
	ActiveRules = Rules();
}
Game::Game(Rules NEW_RULES)
{
	CurrentGame = 0;
	MaxGames = 0;
	turn = 0;
	for (int i = 0; i < 2; i++)
	{
		Players[i] = Player();
	}
	ActiveRules = NEW_RULES;
#if _DEBUG
	cout << "RULES HAVE BEEN SET";
#endif
}
Game::~Game()
{

}
void Game::SetPlayers()
{
	char Key = NULL; // this is used for most of the single key inputs asking for Y or N
	char ChoiceOfWhoGoesFirst = NULL; // this is used in setting who goes first
	int RANDOMNUMBER;// used if the user selects no to who goes first
	system("CLS");
	bool PlayersSet = false;// used for running the loop directly bellow and will repeat till the players are set
	while (!PlayersSet)
	{
		for (int i = 0; i < 2; i++)
		{
			string tempName;
			int tempChance;
			cout << "What is the players name?\n\n";
			cin >> tempName;
			Players[i].setPlayername(tempName);


			do
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				system("CLS");
				cout << "What is the hit chance you want for the player\n\n";
				cin >> tempChance;
			} while (!cin);

			Players[i].setChanceOfHitting(tempChance);
			Players[i].setScore(ActiveRules.getSTARTSCORE());
		}
		system("CLS");

		while (Key == NULL)
		{
			cout << "Do you want to set who goes first?\n\nY = yes		N = no";
			cin >> Key;
			switch (Key)
			{
			case 'y': case 'Y':

				system("CLS");
				cout << "Who do you want to go first?\n\n 1 = " << Players[0].getName() << "		2 = " << Players[1].getName() << "\n\n";
				cin >> ChoiceOfWhoGoesFirst; // assigns a value to the temp variable Choice of who goes first
				switch (ChoiceOfWhoGoesFirst)
				{
				case '1':
					Players[0].setActiveTurn(true);//sets the first player in the array active turn to true
					Players[1].setActiveTurn(false);//sets the second player in the array active turn to false
					break;
				case '2':
					Players[0].setActiveTurn(false); //sets the first player in the array active turn to false
					Players[1].setActiveTurn(true);	//sets the second player in the array active turn to true
					break;
				default:
					cout << "That key that was pressed was an invalid key\n\n";
					ChoiceOfWhoGoesFirst = NULL;
					break;
				}

				break;
			case 'n': case 'N': // this will randomly choose who shall go first by selecting a random number between 1 and 2
				system("CLS");
				RANDOMNUMBER = rand() % 2 + 1;
				switch (RANDOMNUMBER)
				{
				case 1:
					Players[0].setActiveTurn(true);//sets the first player in the array active turn to true
					Players[1].setActiveTurn(false);//sets the second player in the array active turn to false
					break;
				case 2:
					Players[0].setActiveTurn(false); //sets the first player in the array active turn to false
					Players[1].setActiveTurn(true);	//sets the second player in the array active turn to true
					break;
				}
				break;
			default:
				cout << "That key that was pressed was an invalid key\n\n";
				Key = NULL;
				break;
			}
		}

		system("CLS");
		cout << "Are the details of the players correct?\n\n";
		for (int i = 0; i < 2; i++)
		{
			cout << "Name: " << Players[i].getName() << "\nChance of hitting: " << Players[i].getChanceOfHitting() << "%\nStarting Score: " << Players[i].getScore() << "\nActive Turn: " << std::boolalpha << Players[i].getActiveTurn() << "\n\n";
		}
		cout << "Y = yes		N = no\n\n";
		Key = NULL;
		while (Key == NULL)
		{
			cin >> Key;
			switch (Key)
			{
			case 'y': case 'Y':
				PlayersSet = true; // breaks from the while loop and allows for the game to actually be played.THIS SHOULD BE THE ONLY EXIT CONDITION INVOLVING THIS VARIABLE
				break;
			case 'n': case 'N':
				system("CLS");
				for (int i = 0; i < 2; i++)
				{
					Players[i] = Player(); // resets the player back to their default values
				}
				break;
			default: // if none of the keys were the correct one it will do this instead
				cout << "That key that was pressed was an invalid key\n\n";
				Key = NULL;
				break;
			}
		}

	}


}

void Game::Playing()
{
	do
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("CLS");
		cout << "How many games should be played?\n\n";
		cin >> MaxGames;

	} while (!cin);

	switch (ActiveRules.getSTARTSCORE()) // this will decide what one of the rule sets it should play by using a case statement to seperate it properly
	{
	case 301:

		break;
	case 501:

		break;
	}
}

void Game::DisplayResults()
{

}
void Game::Reset()
{

}
void Game::Reset(Rules NEW_RULES)
{
	ActiveRules = NEW_RULES;
}

