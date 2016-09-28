#include "Animal.h"



Animal::Animal()
{
}


Animal::~Animal()
{
}

Animal::Animal(int foodCost) 
{
	this->foodCost = foodCost;
	penguinNum = 0;
	tigerNum = 0;
	polarbearNum = 0;	
}

int Animal::getAnimalFoodCost()
{
	return foodCost;
}

int Animal::getTigerNum()
{
	return tigerNum;
}

int Animal::getPolarbearNum()
{
	return polarbearNum;
}

int Animal::getPenguinNum()
{
	return penguinNum;
}

void Animal::setTigerNum(int tigerNum)
{
	this->tigerNum = tigerNum;
}

void Animal::setPolarbearNum(int polarbearNum)
{
	this->polarbearNum = polarbearNum;
}

void Animal::setPenguinNum(int penguinNum)
{
	this->penguinNum = penguinNum;
}

void Animal::operator+(const Animal& other)
{
	this->foodCost = other.foodCost;
}