#pragma once
#include <iostream>
using namespace std;

class Player
{
private:

	string PlayerName;

	int score;
	int numberOfWins;
	int chanceOfHittingBull;
	int numOfHits;
	int numOfThrows;

	int totalThrows,totalHits;

	bool activeTurn;

	float averageHits;
	float totalAverageHits;

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


	int ThrowBull();
	int ThrowTreble(int[2][21],int);
	int ThrowDouble(int[2][21],int);
	int ThrowSingle(int[2][21],int);

	void setPlayername(string);
	void setChanceOfHitting(int);
	void setScore(int);
	void setActiveTurn(bool);
	void setNumberOfWins(int);
	void setThrows(int);
	void setHits(int);


	void ResetPlayer(int);
	void TotalReset(int);

	void CalculateAverageHits();


};

