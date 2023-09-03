#pragma once
#include <iostream>
#include <vector>
#include "Animals.h"
#include "AntFunctions.h"
//colony deals with instantiating queen, worker and larvae objects for simulating an ant colony
class Colony
{
public:
	Colony(int size, int startingSupplies) : supplies(startingSupplies)
	{
		queen = new QueenAnt(counter++);

		for (int i = 0; i < size; i++)
		{
			Ant* ant = new Ant(counter++);
			population.push_back(ant);
		}
		std::cout << "Colony has " << size << " workers and a queen\nIts starting supplies are " << startingSupplies << "\n";
	}
	~Colony()
	{
		delete queen;
		queen = nullptr;
		std::cout << "Long Live the Queen...\n";
	}
	void advance(int day)//basic simulation behaviour
	{
		int i;
		//queen behaviour
		queen->eat(supplies);
		//if (day % 2)
		{
			for (i = 0; i < (queen->getHealth()*2+1); i++)
			{
				if (!(queen->antBirth(larva_population, supplies, counter)))
					std::cout << "Queen cannot give birth, not enough food...\n";
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
				population[i]->eat(supplies);
				population[i]->procureSupplies(supplies);
			}
		}
	}
	int getColonySize(){ return (population.size() + larva_population.size() + 1); }
	int getSupplies() { return supplies; }
	QueenAnt *getQueen() { return queen; }
private:
	int counter = 0;
	QueenAnt *queen;
	std::vector<Ant*> population;
	std::vector<AntLarva*> larva_population;
	int supplies;
};
//function that deals with deallocating the colony object
bool ColonyDeathCondition(Colony*& colony)
{
	if(death_condition(colony->getQueen()))
	{
		delete colony;
		colony = nullptr;
		return true;
	}
	return false;
}