#ifndef CANNIBALFACTORY_H
#define CANNIBALFACTORY_H

#include "EnemyFactory.h"

class CannibalFactory : public EnemyFactory {


public:
	CannibalFactory();

	virtual Enemy* createEnemy(std::string attack, std::string defence);
};

#endif
