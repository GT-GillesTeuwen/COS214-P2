#include "EnemyFactory.h"
#include<string>
#include <cstdlib>

EnemyFactory::EnemyFactory() {
	
}

EnemyFactory::~EnemyFactory() {
}

std::string EnemyFactory::getName() {
	std::string firstNames [5] = { "Timmy","Rook","Balthazar","Meetlep","Moron"};
	std::string titles [5]= {"the Destroyer","the Amazing","from Accounting","the Adequate","the Genius"};
	return firstNames[rand()%5]+titles[rand()%5];

}
