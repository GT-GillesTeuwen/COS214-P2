#ifndef SNAKEFACTORY_H
#define SNAKEFACTORY_H

class SnakeFactory : EnemyFactory {


public:
	SnakeFactory();

	virtual Enemy* createEnemy(string attack, string defence) = 0;
};

#endif
