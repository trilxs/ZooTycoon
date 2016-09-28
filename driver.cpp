#include <iostream>
#include "Zoo.h"

int main() 
{
	int foodCost; bool playing = true;
	std::cout << "WELCOME TO ZOO TYCOON!\nBefore we start, how much should the food cost be? ";
	std::cin >> foodCost;
	Zoo playerZoo(foodCost);
	while (playing) {
		playing = playerZoo.playDay();
	}
	std::cout << "You ditched your zoo and let all your animals die. :(\n";
}