#pragma once
#include <iostream>
#include <vector>
#include "Animals.h"

bool death_condition(std::vector<Ant*> &population, size_t index);
bool death_condition(QueenAnt* queen);
bool death_condition(std::vector<AntLarva*>& larva_population, size_t index);
bool growth_condition(std::vector<AntLarva*>& larva_population, size_t index, std::vector<Ant*>& population);
