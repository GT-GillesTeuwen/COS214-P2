#ifndef GORILLAFACTORY_H
#define GORILLAFACTORY_H

#include "EnemyFactory.h"
#include <string>

class GorillaFactory : public EnemyFactory {


public:
	GorillaFactory();

	virtual Enemy* createEnemy(std::string attack, std::string defence);
};

#endif
