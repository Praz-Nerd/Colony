#pragma once
#include <string>
class Animal
{
public:
	Animal(int animalAge, int animalMaxAge) : age(animalAge), maxAge(animalMaxAge) {}
	virtual void eat(int&supplies) = 0;
	//virtual void die() = 0;
	void grow(){age++;}
	int getAge() { return age; }
	int getMaxAge() { return maxAge; }
private:
	int age;
	int maxAge;
};

class Ant : public Animal
{
public:
	Ant(int antID, int startingHealth, int antAppetite, int antAge = 0, int antMaxAge = 365) : 
		ID(antID), maxHealth(startingHealth), health(startingHealth), appetite(antAppetite), Animal(antAge, antMaxAge) {}
	~Ant()
	{
		std::cout << "Ant died...";
	}
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
	int type;
	int maxHealth;
	int health;
	int appetite;
};
