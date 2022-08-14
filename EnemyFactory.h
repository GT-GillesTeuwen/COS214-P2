#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include <string>
#include "Enemy.h"

class EnemyFactory
{

public:
	EnemyFactory();

	virtual ~EnemyFactory();

	virtual Enemy* createEnemy(std::string attack, std::string defence) = 0;

protected:
	std::string getName();
};

#endif
