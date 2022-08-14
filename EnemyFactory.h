#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

class EnemyFactory {


public:
	void SnakeFactory();

	virtual void ~EnemyFactory() = 0;

	virtual Enemy* createEnemy(string attack, string defence) = 0;

	string getName();
};

#endif
