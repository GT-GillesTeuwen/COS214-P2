#include "CannibalFactory.h"

#include "Cannibal.h"
#include <random>

CannibalFactory::CannibalFactory() {
}

Enemy* CannibalFactory::createEnemy(std::string attack, std::string defence) {
	std::random_device rd{};
    std::mt19937 gen{rd()};
	std::uniform_int_distribution<> d{8,30};
	int health=0;
	while (health<=0)
	{	
		health=round(d(gen));
	}
	Enemy* createdCannibal=new Cannibal(health,attack,6,defence,getName());
	return createdCannibal;
}