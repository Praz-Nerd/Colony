// Colony.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//ant types 0 = queen, 1 = worker
#include <iostream>
#include "Structures.h"
#include "Animals.h"
using namespace std;

int main()
{
    int day = 0;
    cout << "First ant colony...";
    cin.get();
    //QueenAnt *ant = new QueenAnt(0);
    Colony* colony = new Colony(10, 1000);
    while (!ColonyDeathCondition(&colony))
    {
        colony->advance();
        day++;
    }
    cout << "Colony perished...\nDays survived: " << day;
    //cout << "Ant died after " << day << "days...\nHe was " << ant->getAge() << " days old";
    
}

