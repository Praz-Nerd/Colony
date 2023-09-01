#pragma once
class Animal
{
public:
	Animal(int animalMaxAge) : maxAge(animalMaxAge) {}
	virtual void eat(int&supplies) = 0;
	void grow(){age++;}
	int getAge() { return age; }
	int getMaxAge() { return maxAge; }
private:
	int age = 0;
	int maxAge;
};

class Ant : public Animal
{
public:
	Ant(int antID, int startingHealth = 3, int antAppetite = 1, int antMaxAge = 365) : 
		ID(antID), maxHealth(startingHealth), health(startingHealth), appetite(antAppetite), Animal(antMaxAge) 
	{
		//std::cout << "Ant #" << ID << " was born\n";
	}
/*	~Ant()
	{
		std::cout << "Ant #" << ID;
		if (health == 0)
			std::cout << " was slain...\n";
		else if (getAge() == getMaxAge())
			std::cout << " died of old age...\n";
		std::cout << "It was " << getAge() << " days young\n";
	}*/
	void eat(int&supplies) override
	{
		if (supplies == 0)
			health--;
		else
			supplies = supplies - appetite;
		grow();
	}
	int getID(){return ID;}
	int getMaxHealth() {return maxHealth;}
	int getHealth(){return health;}
	int getAppetite(){return appetite;}
private:
	const int ID;
	int maxHealth;
	int health;
	int appetite;
};

class QueenAnt : public Ant
{
public:
	QueenAnt(int antID, int startingHealth = 5, int antAppetite = 3, int antMaxAge = 730) :
		Ant(antID, startingHealth, antAppetite, antMaxAge)
	{
		std::cout << "Ant #" << getID() << " was born, she's a queen\n";
	}
};

template <typename T>
void die(T** animal)
{
	delete *animal;
	*animal = nullptr;
}
template <typename T>
bool death_condition(T** animal)
{
	if (((*animal)->getHealth()) == 0 || ((*animal)->getAge() == (*animal)->getMaxAge()))
	{
		die(animal);
		return true;
	}
	return false;
}
