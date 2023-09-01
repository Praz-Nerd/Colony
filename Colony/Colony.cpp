// Colony.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Animal.h"
using namespace std;

int main()
{
    int supplies = 100, day = 0;
    cout << "First ant...";
    cin.get();
    Ant ant(1, 3, 1);
    while (ant.getHealth() > 0)
    {
        ant.eat(supplies);
        cout << "day " << ++day << " supplies left = " << supplies << endl;
    }
    cout << "ant died after " << day << "days...\n";
}

