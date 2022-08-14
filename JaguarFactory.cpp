#include "JaguarFactory.h"
#include "Jaguar.h"
#include <random>

JaguarFactory::JaguarFactory() {
}

Enemy* JaguarFactory::createEnemy(std::string attack, std::string defence) {
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(6,1);
	int health=0;
	while (health<=0)
	{
		health=round(distribution(generator));
	}
	Enemy* createdJaguar=new Jaguar(health,attack,2,defence);
	return createdJaguar;
}
