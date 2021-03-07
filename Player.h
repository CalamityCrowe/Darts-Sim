#pragma once
#include <iostream>
using namespace std;

class Player
{
private:
	
	string PlayerName ;
	
	int score;
	int numberOfWins;
	int chanceOfHittingBull;
	int numOfTurns;
	int numOfHits;
	int numOfThrows;
	
	bool activeTurn;
	
	float averageHits;

public:
	Player();
	~Player();

	string getName();
	int getScore();
	int getWins();
	int getThrows();
	int getHits();
	int getChanceOfHitting();
	bool getActiveTurn();

	int ThrowBull(int[2][21]);
	int ThrowTreble(int[2][21]);
	int ThrowDouble(int[2][21]);
	int ThrowSingle(int[2][21]);

	void setPlayername(string);
	void setChanceOfHitting(int);
	void setScore(int);
	void setActiveTurn(bool);
	void setNumberOfWins(int); 
	void setThrows(int);
	void setHits(int);

	void ResetPlayer();

	void CalculateAverageHits();

	
};

