#ifndef CANNIBALFACTORY_H
#define CANNIBALFACTORY_H

class CannibalFactory : EnemyFactory {


public:
	CannibalFactory();

	virtual Enemy* createEnemy(string attack, string defence) = 0;
};

#endif
