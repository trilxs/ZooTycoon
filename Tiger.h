#pragma once
#include <iostream>
#include "Animal.h"
class Tiger :
	public Animal
{
public:
	Tiger();
	Tiger(int);
	~Tiger();
	int getTigerFoodCost();
	void operator+(const Tiger& other);
	//mutator and accessor
	int getTigerAge();
	void setTigerAge(int);
private:
	int age;
	int cost;
	int babies; 
};

