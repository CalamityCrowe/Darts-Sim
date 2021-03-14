#pragma once
#include "Game.h"
#include <string>
#define DEFAULTGAMES 1


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
		for (int i = 0; i < 2; i++) // this will run for a total of 2 times
		{
			Players[i].TotalReset(ActiveRules.getSTARTSCORE());// this resets the players stats
			string tempName; // this is a temporary variable for storing the name from the cin check
			int tempChance; // this is a teporarty variable for storing the hit chance from the cin check
			cout << "What is the players name?\n\n";
			cin >> tempName; // assigns a value to the tempName variable
			Players[i].setPlayername(tempName); //sets the name to what was assigned to tempName


			do
			{
				cin.clear();// clears the error flags from the cin
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skips to the next new line so the error doesn't happen again
				system("CLS");// clears the screen
				cout << "What is the hit chance you want for the player\n\n";
				cin >> tempChance; //assigns a value to the tempChance variable
			} while (!cin); // this will repeat till the value for the integer is an actual int and not a 

			Players[i].setChanceOfHitting(tempChance); // sets the chance of hitting if cin didn't fail in obtaining a value
			Players[i].setScore(ActiveRules.getSTARTSCORE());
			system("CLS");
		}
		system("CLS"); // clears the screen



		while (Key == NULL)
		{
			cout << "Do you want to set who goes first?\n\nY = yes		N = no\n\n";
			cin >> Key; // this assigns a value to the key press
			switch (Key)
			{
			case 'y': case 'Y': // this one will allow the user to choose who shall go first in the turn order

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
			default: //this will display a message saying that the key press was invalid
				cout << "That key that was pressed was an invalid key\n\n";
				Key = NULL;
				break;
			}
		}

		system("CLS");
		cout << "Are the details of the players correct?\n\n";
		for (int i = 0; i < 2; i++) // prints both players details ou on the screen
		{
			cout << "Name: " << Players[i].getName() << "\nChance of hitting: " << Players[i].getChanceOfHitting() << "%\nStarting Score: " << Players[i].getScore() << "\nActive Turn: " << std::boolalpha << Players[i].getActiveTurn() << "\n\n";
		}
		cout << "Y = yes		N = no\n\n";
		Key = NULL;
		while (Key == NULL) // this keeps it in a loop if the wrong key is pressed
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
	system("CLS");


}

void Game::Playing()
{
	if (ActiveRules.getPLAYERCONTROLLED() == false)
	{
		SetGames(); //sets how many games shall be played at max if there is no player contrling it
	}

	while (true)
	{
		switch (ActiveRules.getSTARTSCORE()) // this will decide what one of the rule sets it should play by using a case statement to seperate it properly
		{
		case 301:

			Playing301();
			DisplayResults();

			break;
		case 501:
			switch (ActiveRules.getPLAYERCONTROLLED())
			{
			case true:
				PlayerContGame();
				break;
			case false:

				Playing501();

				break;
			}

			DisplayResults();
			break;
		default:

			cout << "THERE WAS AN ERROR SOMEWHERE CAUSING AN INVALID START SCORE SO THE PROGRAM IS FORCE SHUTTING ITSELF";
			exit(_CONSOLE);

			break;
		}
	}

}

void Game::Playing301()
{
	while (CurrentGame <= MaxGames) // this will loop whilst the current games is less than or equal to the max games
	{
		for (int i = 0; i < 2; i++)
		{
			if (Players[i].getActiveTurn())
			{
				cout << Players[i].getName() << " Turn		Score: " << Players[i].getScore() << "\n\n";

				int tempScore = Players[i].getScore();// this gets a temporary 
				Players[i].setScore(Players[i].getScore() - Players[i].ThrowBull()); // this sets the player score to the current score minus whatever throw bull returns
				if (Players[i].getScore() < 50 && Players[i].getScore() != 0)
				{
					Players[i].setScore(tempScore);
				}
				else if (Players[i].getScore() == 0)
				{
					DisplayCurrentRoundResults(i);
					if (CurrentGame == MaxGames)
					{
						break;
					}
				}

			}

		}
		if (Players[0].getActiveTurn())
		{
			Players[0].setActiveTurn(false);
			Players[1].setActiveTurn(true);
		}
		else
		{
			Players[0].setActiveTurn(true);
			Players[1].setActiveTurn(false);
		}
	}
}

void Game::DisplayCurrentRoundResults(int CURRENTPLAYER)
{
	cout << "current round: " << CurrentGame << " out of " << MaxGames << " games\nThe winner of this game was " << Players[CURRENTPLAYER].getName() << "\nIt took " << Players[CURRENTPLAYER].getThrows() << " throws to win this game\n";
	for (int RESET = 0; RESET < 2; RESET++)
	{
		Players[RESET].CalculateAverageHits();
		Players[RESET].ResetPlayer(ActiveRules.getSTARTSCORE());
	}
	Players[CURRENTPLAYER].setNumberOfWins(Players[CURRENTPLAYER].getWins() + 1);
	CurrentGame++;

}

void Game::Playing501()
{
	while (CurrentGame <= MaxGames)// this will loop till the current games is greater than the max games 
	{
		for (int i = 0; i < 2; i++) // loops for both instances of the player
		{
			if (Players[i].getActiveTurn()) // runs this code if the current player turn is active
			{
				cout << Players[i].getName() << " Turn		Score: " << Players[i].getScore() << "\n\n";

				int tempScore = Players[i].getScore(); // gets the players score currently as a temp value

				AI_501(i);// this is for the ai player of the of the 501 game as there will be a player controlled version

				if (Players[i].getScore() == 1 || Players[i].getScore() < 0) // if the score is one or less than 
				{
					Players[i].setScore(tempScore);
				}
				else if (Players[i].getScore() == 0)
				{
					DisplayCurrentRoundResults(i);
					if (CurrentGame == MaxGames)
					{
						break;
					}
				}
			}
		}// end of the players loop
		if (Players[0].getActiveTurn())// swaps the players turns based on the first instance of the players active turn
		{
			Players[0].setActiveTurn(false);
			Players[1].setActiveTurn(true);
		}
		else
		{
			Players[0].setActiveTurn(true);
			Players[1].setActiveTurn(false);
		}

	}//end of the while loop
}

void Game::PlayerContGame()
{
	CurrentGame = DEFAULTGAMES;
	MaxGames = DEFAULTGAMES;

	while (CurrentGame <= MaxGames)
	{
		for (int i = 0; i < 2; i++)
		{
			int TempScore = Players[i].getScore();
			switch (i)
			{
			case 0:
				if (Players[i].getActiveTurn())
				{
					cout << Players[i].getName() << " Turn		Score: " << Players[i].getScore() << "\n\n";

					for (int dart = 0; dart < 3; dart++) // runs this loop 3 times as this is the number of darts to throw
					{
						if(Players[i].getScore() == 0)
						{
							break;
						}
						char Key = NULL;
						int TARGET;
						cout << "T = treble		D = Double		B = Bull		S = Single\n\n";
						while (Key == NULL)
						{
							cin >> Key;
							switch (Key)
							{
							case 't': case'T':
								Players[i].setScore(Players[i].getScore() - Players[i].ThrowTreble(DartBoard, EnterValueForTarget(Key)));
								break;
							case 'd': case'D':
								Players[i].setScore(Players[i].getScore() - Players[i].ThrowDouble(DartBoard, EnterValueForTarget(Key)));
								break;
							case 'b': case'B':
								Players[i].setScore(Players[i].getScore() - Players[i].ThrowBull());
								break;
							case 's': case'S':
								Players[i].setScore(Players[i].getScore() - Players[i].ThrowSingle(DartBoard, EnterValueForTarget(Key)));
								if (Players[i].getScore() <= 0)
								{
									Players[i].setScore(TempScore);
									dart = 3;
								}
								break;
							default:
								cout << "That was an invalid key\n";
								Key = NULL;
								break;
							}
						}
					}
				}
				break;
			default:
				if (Players[i].getActiveTurn())
				{
					cout << Players[i].getName() << " Turn		Score: " << Players[i].getScore() << "\n\n";
					AI_501(i);
				}
				break;
			}

			if (Players[i].getScore() == 1 || Players[i].getScore() < 0) // if the score is one or less than 
			{
				Players[i].setScore(TempScore);
			}
			else if (Players[i].getScore() == 0)
			{
				DisplayCurrentRoundResults(i);
				if (CurrentGame == MaxGames)
				{
					break;
				}
			}
		}//end of the players loop
		if (Players[0].getActiveTurn())// swaps the players turns based on the first instance of the players active turn
		{
			Players[0].setActiveTurn(false);
			Players[1].setActiveTurn(true);
		}
		else
		{
			Players[0].setActiveTurn(true);
			Players[1].setActiveTurn(false);
		}
	}

}



void Game::AI_501(int i)
{
	for (int dart = 0; dart < 3; dart++)
	{
		bool DARTTHROWN = false;
		if (Players[i].getScore() == 0) // if the score is equal to 0 it will break from the darts loop as this should end it on a double,triple or bull
		{
			break;
		}
		for (int dartboardValues = 20; dartboardValues > 0; dartboardValues--) // cycles through the values of a dartboard and decreases as it goes through it 
		{
			if (Players[i].getScore() % (dartboardValues * 3) == 0) // if the score remainder is equal to 0 after dividing by the dartvalue * 3 it will aim for that value on the board
			{
				Players[i].setScore(Players[i].getScore() - Players[i].ThrowTreble(DartBoard, dartboardValues));
				DARTTHROWN = true;
				break;
			}
			else if (Players[i].getScore() % (dartboardValues * 2) == 0) // if the score remainder is equal to 0 after dividing by the dartvalue * 2 it will aim for that value on the board
			{
				Players[i].setScore(Players[i].getScore() - Players[i].ThrowDouble(DartBoard, dartboardValues));
				DARTTHROWN = true;
				break;
			}
			else if (Players[i].getScore() % 50 == 0)// if the score remainder is equal to 0 after dividing by the bull it will aim for that value on the board
			{
				Players[i].setScore(Players[i].getScore() - Players[i].ThrowBull());
				DARTTHROWN = true;
				break;
			}

		}// end of the dart board value loop
		if (!DARTTHROWN)
		{
			Players[i].setScore(Players[i].getScore() - Players[i].ThrowSingle(DartBoard, rand() % 21 + 1));
		}

	}
}

void Game::SetGames()
{
	CurrentGame = 1;
	do
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("CLS");
		cout << "How many games should be played?\n\n";
		cin >> MaxGames;

	} while (!cin); // this has been explained in the set players section of code as it does the exact same thing
}

void Game::DisplayResults()
{
	char Key = ' ';

	cout << "Game results:\n\nName:	" << Players[0].getName() << "		Name: " << Players[1].getName() << "\n"; // this will display both the players names on the screen
	cout << "Wins: " << Players[0].getWins() << "/" << MaxGames << "		Wins: " << Players[1].getWins() << "/" << MaxGames << "\n"; // this will show the number of wins for both players
	string temp;
	if (Players[0].getWins() > Players[1].getWins()) // this sets the first instance of the players name to the temp string
	{
		temp = Players[0].getName();
	}
	else if (Players[1].getWins() > Players[0].getWins()) // this sets the second instance of the players name to the temp string
	{
		temp = Players[1].getName();
	}
	else //sets the temp to draw
	{
		temp = "Draw";
	}

	cout << "Who won overall: " << temp << "\n\n"; // this will show who won or if it was a draw

	cout << "Do you want to play again?\n\n1 = yes same rules		2 = yes diffrent rules		3 = No and closes the game\n\nEnter a value:";

	cin >> Key; // gets the key and then puts it in a switch depending on the input
	switch (Key)
	{
	case '1': //resets it with the current rules
		Reset();
		break;

	case '2':// resets it with a different rule set

		system("CLS");
		Key = ' ';
		cout << "1 = 301 rules		2 = 501 rules		3 = 501(Player Controlled)\n\n";
		while (Key == ' ')
		{
			cin >> Key;
			switch (Key)
			{
			case '1':
				ChangeRules(threezeroonerules());
				break;
			case '2':
				ChangeRules(fivezeroonerules(0));
				break;
			case '3':
				ChangeRules(fivezeroonerules(1));
				break;
			default:
				cout << "Invalid input\n";
				break;
			}
		}


		break;

	case '3':
		exit(_CONSOLE);

		break;

	default:
		cout << "Invalid value\n\n";
		break;
	}
}
void Game::Reset() // resets the games
{
	system("CLS");
	//resets the game
	CurrentGame = 0;
	MaxGames = 0;
	SetPlayers();
	if(!ActiveRules.getPLAYERCONTROLLED())
	{
		SetGames(); // this only runs if the active player is set as false
	}
}
void Game::ChangeRules(Rules NEW_RULES)
{
	ActiveRules = NEW_RULES;
	Reset();
}


int Game::EnterValueForTarget(char Key) // this is used for getting the target that the player has decided to aim for
{
	int target;
	do
	{
		cin.clear();//clears the error flags from the cin
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skips to the next new line so the error doesn't happen again
		if (Key == 's' || Key == 'S')
		{
			cout << "Enter a value between 1 - 21	21 = outer bull ring\n\n";

		}
		else
		{
			cout << "Enter a value between 1 - 20\n\n";
		}
		cin >> target; // assigns a value to target

	} while (!cin);// will repeat if a string is put in for the interger value as it will fail to assign the value

	if (Key == 's' || Key == 'S') // this has a different upper limit as if the player aims for 21 it will aim for the outer bull ring
	{
		if (target > 21) // limits it so it can't go above 20
		{
			target = 21;
			return target;
		}
		else if (target < 1) // limits it so it can't go bellow 1
		{
			target = 1;
			return target;
		}
		else
		{
			return target;
		}
	}
	else
	{
		if (target > 20) // limits it so it can't go above 20
		{
			target = 20;
			return target;
		}
		else if (target < 1) // limits it so it can't go bellow 1
		{
			target = 1;
			return target;
		}
		else
		{
			return target;
		}
	}

}
