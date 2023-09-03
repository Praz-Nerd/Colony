#include "Animals.h"
#include <vector>
#include<iostream>
bool death_condition(std::vector<Ant*> &population, size_t index)
{
	if (index >= population.size()) {
		// Handle an invalid index
		return false;
	}

	if ((population[index]->getHealth()) <= 0 || (population[index]->getAge() == population[index]->getMaxAge()))
	{
		population.erase(population.begin() + index);
		return true;
	}
	return false;
}

bool death_condition(QueenAnt *queen)
{
	if (queen->getHealth() <= 0 || queen->getAge() == queen->getMaxAge())
		return true;
	return false;
}

bool death_condition(std::vector<AntLarva*>& larva_population, size_t index)
{
	if (index >= larva_population.size()) {
		// Handle an invalid index
		return false;
	}

	if (larva_population[index]->getHealth() <= 0)
	{
		larva_population.erase(larva_population.begin() + index);
		return true;
	}
	return false;
}

bool growth_condition(std::vector<AntLarva*>& larva_population, size_t index, std::vector<Ant*> &population)
{
	if (index >= larva_population.size()) {
		// Handle an invalid index
		return false;
	}

	if (larva_population[index]->getAge() == larva_population[index]->getMaxAge())
	{
		Ant* ant = new Ant(larva_population[index]->getID());
		larva_population.erase(larva_population.begin() + index);
		population.push_back(ant);
		std::cout << "New ant...\n";
		//delete ant;
		return true;
	}
	return false;
}

