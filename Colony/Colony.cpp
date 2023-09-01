// Colony.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//ant types 0 = queen, 1 = worker
#include <iostream>
#include "Animals.h"
using namespace std;

int main()
{
    int supplies = 100, day = 0;
    cout << "First ant...";
    cin.get();
    Ant *ant = new Ant(1, 3, 1);
    while (ant->getHealth() > 0)
    {
        ant->eat(supplies);
        cout << "day " << ++day << " supplies left = " << supplies << endl;
    }
    cout << "Ant died after " << day << "days...\nHe was " << ant->getAge() << " days old";
    if ((ant->getHealth()) == 0 || (ant->getAge() == ant->getMaxAge()))
        delete ant;
}

