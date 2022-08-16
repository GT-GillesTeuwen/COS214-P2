#include "JaguarFactory.h"
#include "Jaguar.h"
#include <random>

JaguarFactory::JaguarFactory() {
}

Enemy* JaguarFactory::createEnemy(std::string attack, std::string defence) {
	std::random_device rd{};
    std::mt19937 gen{rd()};
	std::normal_distribution<> d{10,3};
	int health=0;
	while (health<=0)
	{
		health=round(d(gen));
	}
	Enemy* createdJaguar=new Jaguar(health,attack,4,defence);
	return createdJaguar;
}
