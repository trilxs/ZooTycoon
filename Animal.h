#pragma once
class Animal
{
public:
	//constructor 
	Animal();
	Animal(int);
	void operator+(const Animal& other);
	~Animal();

	//accessors
	int getAnimalFoodCost();

	int getTigerNum();
	int getPolarbearNum();
	int getPenguinNum();

	//mutators
	void setTigerNum(int);
	void setPolarbearNum(int);
	void setPenguinNum(int);

protected:
	int foodCost;
private:
	int tigerNum;
	int polarbearNum;
	int penguinNum;
};
