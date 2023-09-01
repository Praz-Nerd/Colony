#pragma once
#include <iostream>
#include <vector>
#include "Animals.h"
class Colony
{
public:
	Colony(int size, int startingSupplies) : supplies(startingSupplies)
	{
		int id = 0;
		queen = new QueenAnt(id++);

		for (int i = 0; i < size; i++)
		{
			Ant ant(id++);
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
	void advance()
	{
		queen->eat(supplies);
		for (Ant& ant : population)
		{
			ant.eat(supplies);
		}
	}
	QueenAnt &getQueen() { return *queen; }
private:
	QueenAnt *queen;
	std::vector<Ant> population;
	int supplies;
};

bool ColonyDeathCondition(Colony** colony)
{
	if (((*colony)->getQueen().getAge() == (*colony)->getQueen().getMaxAge()) || ((*colony)->getQueen().getHealth() == 0))
	{
		delete *colony;
		return true;
	}
	return false;
}