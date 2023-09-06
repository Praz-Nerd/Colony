#include <iostream>
#include <vector>
#include <ctime>     // For time()
#include <cstdlib>   // For rand() and srand()
#include "Animals.h"

bool Animal::coinFlip(int modifier)
{
	std::srand((std::time(nullptr) + modifier));
	int result = std::rand() % 3;//0, 1, 2
	return (result <= 1) ? true : false;
}

void AntLarva::eat(int &supplies)
{
	if (supplies == 0)
		setHealth(getHealth() - 1);
	else
	{
		supplies = supplies - getAppetite();
	}
	grow();
}

void Ant ::eat(int &supplies)
{
	if (supplies <= 0)
		setHealth(getHealth() - 1);
	else
	{
		supplies = supplies - getAppetite();
		if (getHealth() < getMaxHealth())
			setHealth(getHealth() + 1);
	}

	grow();
}

void Ant::procureSupplies(int& supplies)
{
	if (coinFlip(getID()))
	{
		supplies = supplies + getHealth() * 2;
		//std::cout << "Ant #" << getID() << " has found " << getHealth()*2 << " pieces of food\n";
	}
	else
	{
		supplies = supplies + getHealth();
		//std::cout << "Ant #" << getID() << " has found " << getHealth() << " pieces of food\n";
		setHealth(getHealth() - 1);
	}
}

//function for laying a larva
bool QueenAnt::antBirth(std::vector<AntLarva*>& larva_population, int& supplies, int& newID)
{
	if (supplies < getMaxHealth())
		return false;

	AntLarva* larva = new AntLarva(++newID);
	larva_population.push_back(larva);
	//std::cout << "Larva #" << newID << " was born\n";
	supplies -= getMaxHealth();
	return true;
}

//generic function for deallocating animal objects
template <typename T>
void die(T** animal)
{
	delete animal;
	animal = nullptr;
}
