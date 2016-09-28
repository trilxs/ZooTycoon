#include "Penguin.h"



Penguin::Penguin()
{
}

Penguin::Penguin(int foodCost)
{
	this->foodCost = foodCost;
}

Penguin::~Penguin()
{
}

int Penguin::getPenguinFoodCost()
{
	if (age < 3) return (foodCost * 2);
	else return (foodCost);
}

int Penguin::getPenguinAge()
{
	return age;
}

void Penguin::setPenguinAge(int age)
{
	this->age = age;
}

void Penguin::operator+(const Penguin& other)
{
	this->age = other.age;
}