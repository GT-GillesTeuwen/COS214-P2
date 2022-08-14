#ifndef JAGUARFACTORY_H
#define JAGUARFACTORY_H

#include "EnemyFactory.h"
#include <string>

class JaguarFactory : public EnemyFactory {


public:
	JaguarFactory();

	virtual Enemy* createEnemy(std::string attack, std::string defence);
};

#endif
