#ifndef GORILLAFACTORY_H
#define GORILLAFACTORY_H

class GorillaFactory : EnemyFactory {


public:
	GorillaFactory();

	virtual Enemy* createEnemy(string attack, string defence) = 0;
};

#endif
