#include "Polarbear.h"



Polarbear::Polarbear()
{
}

Polarbear::Polarbear(int foodCost)
{
	this->foodCost = foodCost;
}

Polarbear::~Polarbear()
{
}

int Polarbear::getPolarbearFoodCost()
{
	if (age < 3) return (foodCost * 6);
	else return (foodCost * 3);
}

int Polarbear::getPolarbearAge()
{
	return age;
}

void Polarbear::setPolarbearAge(int age)
{
	this->age = age;
}

void Polarbear::operator+(const Polarbear& other)
{
	this->age = other.age;
}