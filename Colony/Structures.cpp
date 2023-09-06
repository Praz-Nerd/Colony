#include <iostream>
#include <cmath>
#include <vector>
#include "Structures.h"

void Colony::advance(int day)
{
	int i;
	//queen behaviour
	queen->eat(supplies);
	//if (day % 2) (queen->getHealth()*2+1)
	{
		for (i = 0; i < (800 * std::log(day)); i++)
		{
			queen->antBirth(larva_population, supplies, counter);
			//std::cout << "Queen cannot give birth, not enough food...\n";
		}
	}
	//larvae behaviour
	for (i = 0; i < larva_population.size(); i++)
	{
		if ((!growth_condition(larva_population, i, population)) && (!death_condition(larva_population, i)))
		{
			larva_population[i]->eat(supplies);
		}
	}
	//worker ant behaviour
	for (i = 0; i < population.size(); i++)
	{
		if (!death_condition(population, i))
		{
			population[i]->procureSupplies(supplies);
			population[i]->eat(supplies);
		}
	}
}

bool ColonyDeathCondition(Colony*& colony)
{
	if (death_condition(colony->getQueen()))
	{
		delete colony;
		colony = nullptr;
		return true;
	}
	return false;
}