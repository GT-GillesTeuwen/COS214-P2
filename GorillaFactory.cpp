#include "GorillaFactory.h"
#include "Gorilla.h"
#include"EnemyState.h"
#include <random>

GorillaFactory::GorillaFactory() {
}

Enemy* GorillaFactory::createEnemy(std::string attack, std::string defence) {
	std::random_device rd{};
    std::mt19937 gen{rd()};
	std::uniform_int_distribution<> d{4,12};
	int health=0;
	while (health<=0)
	{	
		health=round(d(gen));
	}
	Enemy* createdGorilla=new Gorilla(health,attack,1,defence,getName());
	return createdGorilla;
}

 EnemyState* Gorilla::saveState(){
	return new EnemyState(HP,attackMove,attackDamage,defensiveMove,2);
 }