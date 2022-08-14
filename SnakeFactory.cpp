#include "SnakeFactory.h"
#include "Snake.h"
#include <random>

SnakeFactory::SnakeFactory() {
}

Enemy* SnakeFactory::createEnemy(std::string attack, std::string defence) {
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(6,1);
	int health=0;
	while (health<=0)
	{
		health=round(distribution(generator));
	}
	Enemy* createdSnake=new Snake(health,attack,2,defence);
	return createdSnake;
}
