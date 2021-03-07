#pragma once
#include <iostream>

class Rules
{
protected:
	int STARTSCORE;

public:
	Rules();
	~Rules();
	int getSTARTSCORE();
};
class threezeroonerules : public Rules
{
public:
	threezeroonerules();
};


class fivezeroonerules : public Rules
{
public:
	fivezeroonerules();
};
