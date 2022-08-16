#include "SnakeFactory.h"
#include "Snake.h"
#include <random>
#include <iostream>

SnakeFactory::SnakeFactory() {
}

SnakeFactory::~SnakeFactory(){
	
}

Enemy* SnakeFactory::createEnemy(std::string attack, std::string defence) {
	std::random_device rd{};
    std::mt19937 gen{rd()};
	std::normal_distribution<> d{6,1};
	int health=0;
	while (health<=0)
	{	
		health=round(d(gen));
	}
	Enemy* createdSnake=new Snake(health,attack,2,defence,getName());
	return createdSnake;
}
