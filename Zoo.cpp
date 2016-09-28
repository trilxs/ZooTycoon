#include "Zoo.h"



Zoo::Zoo()
{
}

Zoo::Zoo(int foodCost) 
{
	this->foodCost = foodCost;
	animals = Animal(this->foodCost);
	dayNum = 0;
	animalNum = 0;
	bank = 100000;
}

Zoo::~Zoo()
{
	if (animals.getPolarbearNum() > 0) delete[] polarbears;
	if (animals.getPenguinNum() > 0) delete[] penguins;
	if (animals.getTigerNum() > 0) delete[] tigers;
}

bool Zoo::playDay()
{
	system("clear");	
	system("clear");
	dayNum++;
	animalNum = animals.getPenguinNum() + animals.getTigerNum() + animals.getPolarbearNum();
	printLog();
	if (animalNum > 0) {
		playing = feedAnimals();
		if (!playing) return false;
		randomEvent();
	}
	else {
		std::cout << "You have no animals at your zoo." << std::endl;
		std::cout << "================" << std::endl;
	}
	buyAnimals();
	payOff();
	int repeat;
	std::cout << "Would you like to continue to the next day? (1/0)\n";
	std::cin >> repeat;
	if (repeat == 1) return true;
	else return false;
}

void Zoo::payOff()
{
	int bonus = 0;
	bonus += animals.getTigerNum() * 1000;
	bonus += animals.getPenguinNum() * 50;
	bonus += animals.getPolarbearNum() * 250;
	std::cout << "For payoffs per animal, you get a total bonus of $" << bonus << "!\n";
	bank += bonus;
}

void Zoo::buyAnimals()
{
	int choice, tigerAmount = 0, penguinAmount = 0, polarbearAmount = 0;
	bool valid = false;
	std::cout << "Would you like to buy any animals? (1/0) ";
	std::cin >> choice;
	if (choice == 1) {
		int whichAnimal;
		while (!valid) {
			std::cout << "Bank: $" << bank << std::endl;
			std::cout << "Which animal(s) would you like to buy? (up to two per animal)\n1. Tigers ($10,000)\n2. Penguins ($1,000)\n3. Polarbears ($5,000)\n4. I'm done\nChoice: ";
			std::cin >> whichAnimal;
			if (whichAnimal == 1) {
				if (tigerAmount < 3) {
					int num;
					std::cout << "How many tigers?\n";
					std::cin >> num;
					if ((num + tigerAmount) < 3 && ((tigerAmount * 10000) <= bank)) {
						for (int i = 0; i < num; i++) {
							addTiger(false);
							bank -= 10000;
						}
						tigerAmount += num;
					}
					else std::cout << "That's too many tigers.\n";
				}
				else std::cout << "You've already bought the maximum limit for today.\n";
			}
			else if (whichAnimal == 2) {
				if (penguinAmount < 3) {
					int num;
					std::cout << "How many penguins?\n";
					std::cin >> num;
					if ((num + penguinAmount) < 3 && ((penguinAmount * 1000) <= bank)) {
						for (int i = 0; i < num; i++) {
							addPenguin(false);
							bank -= 1000;
						}
						penguinAmount += num;
					}
					else std::cout << "That's too many penguins.\n";
				}
				else std::cout << "You've already bought the maximum limit for today.\n";
			}
			else if (whichAnimal == 3) {
				if (polarbearAmount < 3) {
					int num;
					std::cout << "How many polarbears?\n";
					std::cin >> num;
					if ((num + polarbearAmount) < 3 && ((polarbearAmount * 5000) <= bank)) {
						for (int i = 0; i < num; i++) {
							addPolarbear(false);
							bank -= 5000;
						}
						polarbearAmount += num;
					}
					else std::cout << "That's too many polarbears.\n";
				}
				else std::cout << "You've already bought the maximum limit for today.\n";
			}
			else {
				valid = true;
				std::cout << "================" << std::endl;
			}
		}
	}
	else {
		std::cout << "================" << std::endl;
	}
}

void Zoo::printLog()
{
	std::cout << "~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "|    DAY  " << dayNum << "    |" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~" << std::endl << std::endl;
	std::cout << "======LOG=======" << std::endl;
	if (animalNum > 0) {
		std::cout << "Total # of animals at the zoo: " << animalNum << std::endl;
		std::cout << "Total # of tigers at the zoo: " << animals.getTigerNum() << std::endl;
		std::cout << "Total # of penguins at the zoo: " << animals.getPenguinNum() << std::endl;
		std::cout << "Total # of polarbears at the zoo: " << animals.getPolarbearNum() << std::endl;
		std::cout << "------------------------\n";
	}
	ageIncrease();
	std::cout << "BANK: $" << bank << std::endl;
}

bool Zoo::feedAnimals()
{
	int fee = 0;
	for (int i = 0; i < animals.getTigerNum(); i++) {
		fee += tigers[i].getTigerFoodCost();
	}
	for (int i = 0; i < animals.getPenguinNum(); i++) {
		fee += penguins[i].getPenguinFoodCost();
	}
	for (int i = 0; i < animals.getPolarbearNum(); i++) {
		fee += polarbears[i].getPolarbearFoodCost();
	}
	if (bank >= fee) {
		std::cout << "====FOOD COST===" << std::endl;
		std::cout << "You have paid a total food cost fee of $" << fee << " to feed the animals." << std::endl;
		bank -= fee;
		return true;
	}
	std::cout << "====FOOD COST===" << std::endl;
	std::cout << "You're unable to play for food cost.\nGAME OVER!\n" << std::endl;
	return false;
}

void Zoo::ageIncrease()
{
	if (animals.getTigerNum() > 0) {
		std::cout << "YOUR TIGERS' AGES: " << std::endl;
		for (int i = 0; i < animals.getTigerNum(); i++) {
			tigers[i].setTigerAge(tigers[i].getTigerAge() + 1);
			std::cout << "Tiger " << (i + 1) << ": " << tigers[i].getTigerAge() << std::endl;
		}
	}
	if (animals.getPenguinNum() > 0) {
		std::cout << "YOUR PENGUINS' AGES: " << std::endl;
		for (int i = 0; i < animals.getPenguinNum(); i++) {
			penguins[i].setPenguinAge(penguins[i].getPenguinAge() + 1);
			std::cout << "Penguin " << (i + 1) << ": " << penguins[i].getPenguinAge() << std::endl;
		}
	}
	if (animals.getPolarbearNum() > 0) {
		std::cout << "YOUR POLAR BEARS' AGES: " << std::endl;
		for (int i = 0; i < animals.getPolarbearNum(); i++) {
			polarbears[i].setPolarbearAge(polarbears[i].getPolarbearAge() + 1);
			std::cout << "Polar bear " << (i + 1) << ": " << polarbears[i].getPolarbearAge() << std::endl;
		}
	}
	if (animalNum > 0) std::cout << "------------------------\n";
}

void Zoo::randomEvent()
{
	std::cout << "=====EVENT======" << std::endl;
	srand (time(NULL)); int randNum;
	//randNum = (rand() % 4) + 1;
	randNum = 1;
	switch (randNum) {
		case 1: sickness(); break;
		case 2: boom(); break;
		case 3: babyIsBorn(); break;
	}
}

void Zoo::sickness()
{
	int choice; bool correct = false;
	std::cout << "A sickness has occurred in the zoo!" << std::endl;
	while (!correct) {
		std::cout << "Which animal do you want to kill off? (1-3)\n1. Tiger\n2. Penguin\n3. Polar bear\n";
		std::cin >> choice;
		switch (choice) {
		case 1: correct = removeTiger(); break;
		case 2: correct = removePenguin(); break;
		case 3: correct = removePolarbear(); break;
		}
	}
}

void Zoo::babyIsBorn()
{
	int choice;
	std::cout << "An animal has given birth!" << std::endl;
	std::cout << "Which animal is giving birth? (1-3)\n1. Tiger\n2. Penguin\n3. Polar bear\n";
	std::cin >> choice;
	switch (choice) {
	case 1: addTiger(true); break;
	case 2: addPenguin(true); break;
	case 3: addPolarbear(true); break;
	}
}


void Zoo::boom()
{
	int bonus = 0;
	std::cout << "A boom in zoo attendance has occurred!" << std::endl;
	if (animalNum > 0) {
		int tigerBonus;
		tigerBonus = (rand() % 250) + 251;
		std::cout << "Tiger Bonus: $" << tigerBonus << std::endl;
		std::cout << "You have " << animals.getTigerNum() << " tigers in your zoo, giving you a tiger bonus of $" << (tigerBonus * animals.getTigerNum()) << std::endl;
		bonus += (tigerBonus * animals.getTigerNum());
	}
	else {
		std::cout << "Uhh just kidding. There are no animals here.\n";
	}
	bank += bonus;
}

bool Zoo::removeTiger() 
{
	if (animals.getTigerNum() == 0) {
		std::cout << "There are no tigers at this zoo." << std::endl;
		return false;
	}
	else if (animals.getTigerNum() == 1) {
		animals.setTigerNum(0);
		delete[] tigers;
		std::cout << "A tiger has died!\n";
	}
	else {
		animals.setTigerNum(animals.getTigerNum()-1);
		std::cout << "A tiger has died!\n";
	}
	return true;
}

bool Zoo::removePenguin()
{
	if (animals.getPenguinNum() == 0) {
		std::cout << "There are no penguins at this zoo." << std::endl;
		return false;
	}
	else if (animals.getPenguinNum() == 1) {
		animals.setPenguinNum(0);
		delete[] penguins;
		std::cout << "A penguin has died!\n";
	}
	else {
		animals.setPenguinNum(animals.getPenguinNum() - 1);
		std::cout << "A penguin has died!\n";
	}
	return true;
}

bool Zoo::removePolarbear()
{
	if (animals.getPolarbearNum() == 0) {
		std::cout << "There are no polarbears at this zoo." << std::endl;
		return false;
	}
	else if (animals.getPolarbearNum() == 1) {
		animals.setPolarbearNum(0);
		delete[] polarbears;
		std::cout << "A polar bear has died!\n";
	}
	else {
		animals.setPolarbearNum(animals.getPolarbearNum() - 1);
		std::cout << "A polar bear has died!\n";
	}
	return true;
}

void Zoo::addTiger(bool born)
{
	if (animals.getTigerNum() == 0) {
		animals.setTigerNum(animals.getTigerNum() + 1);
		tigers = new Tiger[animals.getTigerNum()];
	}
	else {
		animals.setTigerNum(animals.getTigerNum() + 1);
		Tiger* temp;
		temp = new Tiger[animals.getTigerNum()];
		std::copy(tigers, tigers + (animals.getTigerNum() - 1), temp);
		delete[] tigers;
		tigers = temp;
	}
	tigers[animals.getTigerNum() - 1] = Tiger(animals.getAnimalFoodCost());

	if (born) {
		tigers[animals.getTigerNum() - 1].setTigerAge(0);
		std::cout << "A tiger has been born!\n";
	}
	else {
		tigers[animals.getTigerNum() - 1].setTigerAge(3);
		std::cout << "A tiger has been bought!\n";
	}
}

void Zoo::addPenguin(bool born)
{
	if (animals.getPenguinNum() == 0) {
		animals.setPenguinNum(animals.getPenguinNum() + 1);
		penguins = new Penguin[animals.getPenguinNum()];
	}
	else {
		animals.setPenguinNum(animals.getPenguinNum() + 1);
		Penguin* temp;
		temp = new Penguin[animals.getPenguinNum()];
		std::copy(penguins, penguins + (animals.getPenguinNum() - 1), temp);
		delete[] penguins;
		penguins = temp;
	}
	penguins[animals.getPenguinNum() - 1] = Penguin(animals.getAnimalFoodCost());

	if (born) {
		penguins[animals.getPenguinNum() - 1].setPenguinAge(0);
		std::cout << "A penguin has been born!\n";
	}
	else {
		penguins[animals.getPenguinNum() - 1].setPenguinAge(3);
		std::cout << "A penguin has been bought!\n";
	}
}

void Zoo::addPolarbear(bool born)
{
	if (animals.getPolarbearNum() == 0) {
		animals.setPolarbearNum(animals.getPolarbearNum() + 1);
		polarbears = new Polarbear[animals.getPolarbearNum()];
	}
	else {
		animals.setPolarbearNum(animals.getPolarbearNum() + 1);
		Polarbear* temp;
		temp = new Polarbear[animals.getPolarbearNum()];
		std::copy(polarbears, polarbears + (animals.getPolarbearNum() - 1), temp);
		delete[] polarbears;
		polarbears = temp;
	}
	polarbears[animals.getPolarbearNum() - 1] = Polarbear(animals.getAnimalFoodCost());

	if (born) {
		polarbears[animals.getPolarbearNum() - 1].setPolarbearAge(0);
		std::cout << "A polar bear has been born!\n";
	}
	else {
		polarbears[animals.getPolarbearNum() - 1].setPolarbearAge(3);
		std::cout << "A polar bear has been bought!\n";
	}
}
