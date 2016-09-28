#pragma once
#include "Animal.h"
class Polarbear :
	public Animal
{
public:
	Polarbear();
	Polarbear(int);
	~Polarbear();
	void operator+(const Polarbear& other);
	int getPolarbearFoodCost();

	//mutator and accessor
	int getPolarbearAge();
	void setPolarbearAge(int);
private:
	int age;
	int cost;
	int babies;
};

