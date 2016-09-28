#include "Tiger.h"



Tiger::Tiger()
{
}

Tiger::Tiger(int foodCost)
{
	this->foodCost = foodCost;
}

Tiger::~Tiger()
{
}

int Tiger::getTigerFoodCost()
{
	if (age < 3) return (foodCost * 10);
	else return (foodCost * 5);
}

int Tiger::getTigerAge()
{
	return age;
}

void Tiger::setTigerAge(int age)
{
	this->age = age;
}

void Tiger::operator+(const Tiger& other)
{
	this->age = other.age;
}