#ifndef SNAKEFACTORY_H
#define SNAKEFACTORY_H

#include "EnemyFactory.h"
#include <string>

class SnakeFactory : public EnemyFactory {


public:
	SnakeFactory();

	virtual ~SnakeFactory();

	virtual Enemy* createEnemy(std::string attack, std::string defence);
};

#endif
