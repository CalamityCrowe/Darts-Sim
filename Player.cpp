#pragma once
#include "Player.h"
Player::Player()
{

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
	if(chanceOfHittingBull > 100)
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

void Player::ResetPlayer()
{

}

void Player::CalculateAverageHits()
{
	averageHits = (static_cast<float>(numOfHits) / static_cast<float>(numOfThrows)) * 100;

	cout << "The percentage of actual hits for " << PlayerName << " was\n\n" << averageHits << "%\n\n";
}

#pragma region All the Throws
int Player::ThrowBull(int Dartboard[2][21])
{
	return 0;

}
int Player::ThrowTreble(int Dartboard[2][21])
{
	return 0;

}
int Player::ThrowDouble(int Dartboard[2][21])
{
	return 0;

}
int Player::ThrowSingle(int Dartboard[2][21])
{
	return 0;
}
#pragma endregion