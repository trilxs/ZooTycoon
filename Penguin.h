#pragma once
#include "Animal.h"
class Penguin :
	public Animal
{
public:
	Penguin();
	Penguin(int);
	~Penguin();
	void operator+(const Penguin& other);
	int getPenguinFoodCost();

	//mutator and accessor
	int getPenguinAge();
	void setPenguinAge(int);
private:
	int age;
	int cost;
	int babies;
};

