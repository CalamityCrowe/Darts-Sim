#pragma once
#include "Player.h"
#include <iomanip>
Player::Player()
{
	PlayerName = "";

	score = 0;
	numberOfWins = 0;
	chanceOfHittingBull = 0;

	numOfHits = 0;
	numOfThrows = 0;

	activeTurn = false;

	averageHits = 0;
}
Player::~Player()
{

}
#pragma region All the Player getters
string Player::getName()
{
	return PlayerName;
}

int Player::getScore()
{
	return score;
}

int Player::getWins()
{
	return numberOfWins;
}

int Player::getThrows()
{
	return numOfThrows;
}
int Player::getHits()
{
	return numOfHits;
}
int Player::getChanceOfHitting()
{
	return chanceOfHittingBull;
}



bool Player::getActiveTurn()
{
	return activeTurn;
}

#pragma endregion

#pragma region All the Player setters
void Player::setPlayername(string NAME)
{
	PlayerName = NAME;
}

void Player::setChanceOfHitting(int NEW_CHANCE)
{
	chanceOfHittingBull = NEW_CHANCE;
	// this checks that the chance can't exceed 100 and if it does it sets it to 100 if it does
	if (chanceOfHittingBull > 100)
	{
		chanceOfHittingBull = 100;
	}
	// same idea as before but if it goes bellow 0 it will set it to 0
	else if (chanceOfHittingBull < 0)
	{
		chanceOfHittingBull = 0;
	}
}

void Player::setScore(int NEW_SCORE)
{
	score = NEW_SCORE;
}

void Player::setActiveTurn(bool NEW_ACTIVETURN)
{
	activeTurn = NEW_ACTIVETURN;
}
void Player::setNumberOfWins(int NEW_NUMBEROFWINS) // this will get the number of wins and add one before it sets the new value
{
	numberOfWins = NEW_NUMBEROFWINS;
}
void Player::setThrows(int NEW_THROWS) //similar to the number of wins, it will get the number of throws and add however many throws before it sets the value
{
	numOfThrows = NEW_THROWS;
}
void Player::setHits(int NEW_HITS) //similar to the number of wins it will get the of his add one whenever there's a successful hit before it sets the value
{
	numOfHits = NEW_HITS;
}

#pragma endregion

void Player::ResetPlayer(int ACTIVESCORE)
{
	score = ACTIVESCORE;
	numOfThrows = 0;
	numOfHits = 0;

}
void Player::TotalReset(int ACTIVESCORE)
{
	ResetPlayer(ACTIVESCORE);
	totalHits = 0;
	totalThrows = 0;
	numberOfWins = 0;
}



void Player::CalculateAverageHits()
{
	averageHits = (static_cast<float>(numOfHits) / static_cast<float>(numOfThrows)) * 100;
	totalAverageHits = (static_cast<float>(totalHits) / static_cast<float>(totalThrows) * 100);
	cout << "The percentage of actual hits for " << PlayerName << " was\n\n" << std::fixed << std::setprecision(2) << averageHits << "%\nThe average over all games was" << totalAverageHits << "%\n\n";
}

#pragma region All the Throws
int Player::ThrowBull()
{
	numOfThrows++;
	totalThrows++;

	int r = rand() % 100;

	if (r < (chanceOfHittingBull - 20))
	{
		numOfHits++;
		totalHits++;
		cout << getName() << " hit 50 and the score is now " << getScore() - 50 << "\n\n";
		return 50;
	}
	else if (r < 85)
	{
		cout << getName() << " hit 25 and the score is now " << getScore() - 25 << "\n\n";
		return 25;
	}
	else
	{
		int value = 1 + rand() % 20;
		cout << getName() << " hit " << value << " and the score is now " << getScore() - 50 << "\n\n";

		return value;
	}

}
int Player::ThrowTreble(int Dartboard[2][21], int Target)// target is the value that is getting aimed at initially
{
	int r = rand() % 100;
	numOfThrows++;
	totalThrows++;

	cout << "TRIPLE " << Target << "\n\n";

	if (r < chanceOfHittingBull)
	{
		numOfHits++;
		totalHits++;
		cout << getName() << " hit " << Target * 3 << " and the score is now " << getScore() - (Target * 3) << "\n\n";

		return 3 * Target;
	}
	else if (r < 90)
	{
		cout << getName() << " hit " << Target << " and the score is now " << getScore() - (Target) << "\n\n";

		return Target;

	}
	else if (r < 93)
	{
		cout << getName() << "hit " << Dartboard[0][Target + 1] * 3 << " and the score is now " << getScore() - (Dartboard[0][Target + 1] * 3) << "\n\n";

		return 3 * Dartboard[0][Target + 1];
	}
	else if (r < 96)
	{
		cout << getName() << " hit " << Dartboard[1][Target + 1] * 3 << " and the score is now " << getScore() - (Dartboard[1][Target + 1] * 3) << "\n\n";

		return 3 * Dartboard[1][Target + 1];
	}
	else if (r < 98)
	{
		cout << getName() << " hit " << Dartboard[0][Target + 1] << " and the score is now " << getScore() - (Dartboard[0][Target + 1]) << "\n\n";

		return Dartboard[0][Target + 1];
	}
	else
	{
		cout << getName() << " hit " << Dartboard[1][Target + 1] << " and the score is now " << getScore() - (Dartboard[1][Target + 1]) << "\n\n";

		return Dartboard[1][Target + 1];
	}


}
int Player::ThrowDouble(int Dartboard[2][21], int Target)
{
	numOfThrows++;
	totalThrows++;
	int r = rand() % 100;
	cout << "DOUBLE " << Target << "\n\n";


	if (r < chanceOfHittingBull)
	{
		numOfHits++;
		totalHits++;
		cout << getName() << " hit " << Target * 2 << " and the score is now " << getScore() - (Target * 2) << "\n\n";

		return 2 * Target;
	}
	else if (r < 85)
	{
		cout << getName() << " hit " << Target * 0 << " and the score is now " << getScore() - (Target * 0) << "\n\n";

		return 0;
	}

	else if (r < 90)
	{
		cout << getName() << " hit " << Target << " and the score is now " << getScore() - (Target) << "\n\n";

		return Target;
	}
	else if (r < 93)
	{
		cout << getName() << " hit " << Dartboard[0][Target + 1] * 2 << " and the score is now " << getScore() - (Dartboard[0][Target + 1] * 2) << "\n\n";

		return 2 * Dartboard[0][Target];
	}
	else if (r < 96)
	{
		cout << getName() << " hit " << Dartboard[1][Target + 1] * 2 << " and the score is now " << getScore() - (Dartboard[1][Target + 1] * 2) << "\n\n";

		return 2 * Dartboard[1][Target];
	}
	else if (r < 98)
	{
		cout << getName() << " hit " << Dartboard[0][Target + 1] << " and the score is now " << getScore() - (Dartboard[0][Target + 1]) << "\n\n";

		return Dartboard[0][Target];
	}
	else
	{
		cout << getName() << " hit " << Dartboard[1][Target + 1] << " and the score is now " << getScore() - (Dartboard[1][Target + 1]) << "\n\n";

		return Dartboard[1][Target + 1];

	}

}
int Player::ThrowSingle(int Dartboard[2][21], int Target)
{
	numOfThrows++;
	totalThrows++;
	int r = rand() % 100;
	cout << "SINGLE " << Target << "\n\n";


	if (Target == 21) {		// outer  80%
		if (r < chanceOfHittingBull)
		{
			numOfHits++;
			totalHits++;
			cout << getName() << " hit 25 and the score is now " << getScore() - 25 << "\n\n";

			return 25;
		}
		else if (r < 90)
		{
			cout << getName() << " hit 50 and the score is now " << getScore() - 50 << "\n\n";

			return 50;
		}
		else
		{
			int value = 1 + rand() % 20;

			cout << getName() << " hit" << value << " and the score is now " << getScore() - 50 << "\n\n";

			return value;
		}
	}
	else
	{			// 1 to 20 single
		if (r < 88)
		{
			numOfHits++;
			totalHits++;
			cout << getName() << " hit " << Target << " and the score is now " << getScore() - Target << "\n\n";


			return Target;
		}
		else if (r < 92)
		{
			cout << getName() << " hit " << Dartboard[0][Target + 1] << " and the score is now " << getScore() - Dartboard[0][Target + 1] << "\n\n";

			return Dartboard[0][Target + 1];
		}
		else if (r < 96)
		{
			cout << getName() << " hit " << Dartboard[1][Target + 1] << " and the score is now " << getScore() - Dartboard[1][Target + 1] << "\n\n";


			return Dartboard[1][Target + 1];
		}
		else if (r < 98)
		{
			cout << getName() << " hit " << Target * 3 << " and the score is now " << getScore() - (Target * 3) << "\n\n";

			return 3 * Target;
		}
		else
		{
			cout << getName() << " hit " << Target * 2 << " and the score is now " << getScore() - (Target * 2) << "\n\n";

			return 2 * Target;
		}
	}
}
#pragma endregion