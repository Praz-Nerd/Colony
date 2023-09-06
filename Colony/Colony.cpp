// Colony.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Structures.h"
using namespace std;

int main()
{
    int day = 0;
    cout << "First ant colony...";
    cin.get();
    //input is workar ant population and starting supplies
    Colony* colony = new Colony(250, 1000);
    while (!ColonyDeathCondition(colony))
    {
        cout << "Day " << ++day << " supplies " << colony->getSupplies() << " population " << colony->getColonySize() << "\n";
        colony->advance(day);
        cin.get();//press Enter to move on with the simulation
    }
    cout << "Colony perished...\nDays survived: " << day;
    //cout << "Ant died after " << day << "days...\nHe was " << ant->getAge() << " days old";
    
}

