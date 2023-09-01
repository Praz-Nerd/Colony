#pragma once
#include <string>
class Animal
{
public:
	virtual void eat(int&supplies) = 0;
};

class Ant : public Animal
{
public:
	Ant(int antID, int startingHealth, int antAppetite) : ID(antID), maxHealth(startingHealth), health(startingHealth), appetite(antAppetite){}
	void eat(int&supplies) override
	{
		if (supplies == 0)
			health--;
		else
			supplies = supplies - appetite;
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
