#pragma once
#include <iostream>

class Rules
{
protected:
	int STARTSCORE;
	bool playerControlled;//used only in the 501 rules

public:
	Rules();
	~Rules();
	int getSTARTSCORE();
	bool getPLAYERCONTROLLED() { return playerControlled; }

};
class threezeroonerules : public Rules
{
public:
	threezeroonerules();
};


class fivezeroonerules : public Rules
{
private:
public:
	fivezeroonerules();
	fivezeroonerules(int);
};
