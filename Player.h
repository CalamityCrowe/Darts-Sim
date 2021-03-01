#pragma once
#include <iostream>
using namespace std;

class Player
{
private:
	
	string PlayerName ;
	
	int Score;
	int NumberOfWins;
	int ChanceOfHittingBull;

	
	bool activeTurn;
	

public:
	Player();
	Player(string,int,bool);
	~Player();

	void setPlayerName(string);
	void setStartingScore(int);
	void setChanceOfHittingBull(int);

	string getName();
	int getScore();
	int getWins();


	string getPlayerName();

};

