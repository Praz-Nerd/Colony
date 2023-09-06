#pragma once
#include <iostream>
#include <cmath>
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
	//basic simulation behaviour
	void advance(int day);
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
bool ColonyDeathCondition(Colony*& colony);