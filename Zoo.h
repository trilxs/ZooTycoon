#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Animal.h"
#include "Penguin.h"
#include "Polarbear.h"
#include "Tiger.h"


class Zoo
{
public:
	//constructors and deconstructors
	Zoo();
	Zoo(int);
	~Zoo();

	bool playDay();
	
	Animal animals;
	//arrays
	Tiger* tigers;
	Penguin* penguins;
	Polarbear* polarbears;

private:
	//functions
	void printLog();
	void randomEvent();
	void ageIncrease();
	void buyAnimals();
	void payOff();
	bool feedAnimals();

	int foodCost;
	bool playing;

	//random events
	void sickness();
	void boom();
	void babyIsBorn();

	//remove animals
	bool removeTiger();
	bool removePenguin();
	bool removePolarbear();

	//add animals
	void addTiger(bool);
	void addPenguin(bool);
	void addPolarbear(bool);

	//add animals
	//variables
	int dayNum;
	int animalNum;
	int bank;
};

