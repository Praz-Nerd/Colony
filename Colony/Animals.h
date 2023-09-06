#pragma once
#include <vector>
//parent class for all entities
//generic functions+a 75/25 random function
class Animal
{
public:
	Animal(int animalID, int startingHealth, int animalAppetite, int animalMaxAge) : 
		ID(animalID), maxHealth(startingHealth), health(startingHealth), appetite(animalAppetite), maxAge(animalMaxAge) {}
	virtual void eat(int&supplies) = 0;
	void grow(){age++;}
	int getAge() { return age; }
	int getMaxAge() { return maxAge; }
	int getID() { return ID; }
	int getMaxHealth() { return maxHealth; }
	int getHealth() { return health; }
	int getAppetite() { return appetite; }
	void setHealth(int newval){ health = newval; }
	bool coinFlip(int modifier);
	
private:
	const int ID;
	int age = 0;
	int maxAge;
	int maxHealth;
	int health;
	int appetite;
};
//larva class, eats a lot, cannot procure food, grows into a worker ant after 12 days

class AntLarva : public Animal
{
public:
	AntLarva(int antID, int startingHealth = 1, int antAppetite = 3, int antMaxAge = 3) :
		Animal(antID, startingHealth, antAppetite, antMaxAge) {}
	void eat(int& supplies) override;
	
};

//ant class, low appetite, can procure food
class Ant : public Animal
{
public:
	Ant(int antID, int startingHealth = 3, int antAppetite = 1, int antMaxAge = 365) :
		Animal(antID, startingHealth, antAppetite, antMaxAge) {}

	void eat(int& supplies) override;
	//function for finding food
	void procureSupplies(int& supplies);
	
};
//queen class, large health, medium appetite, spawns larvae, eats after spawning
class QueenAnt : public Ant
{
public:
	QueenAnt(int antID, int startingHealth = 5, int antAppetite = 3, int antMaxAge = 730) :
		Ant(antID, startingHealth, antAppetite, antMaxAge)
	{
		//std::cout << "Ant #" << getID() << " was born, she's a queen\n";
	}

	//function for laying a larva
	bool antBirth(std::vector<AntLarva*>& larva_population, int& supplies, int& newID);
};

//generic function for deallocating animal objects
template <typename T>
void die(T** animal);

