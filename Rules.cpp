#include "Rules.h"
Rules::Rules()
{
	STARTSCORE = 0;
	playerControlled = false;
}
Rules::~Rules()
{
}
int Rules::getSTARTSCORE()
{
	return STARTSCORE;
}
threezeroonerules::threezeroonerules()
{
	STARTSCORE = 301;
	playerControlled = false;
}
fivezeroonerules::fivezeroonerules()
{
	STARTSCORE = 501;
	playerControlled = false;
}
fivezeroonerules::fivezeroonerules(int Controlled)
{
	STARTSCORE = 501;
	if(Controlled == 1)
	{
		playerControlled = true;
	}
	else
	{
		playerControlled = false;
	}
}
