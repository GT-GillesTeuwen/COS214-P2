#ifndef JAGUARFACTORY_H
#define JAGUARFACTORY_H

class JaguarFactory : EnemyFactory {


public:
	JaguarFactory();

	virtual Enemy* createEnemy(string attack, string defence) = 0;
};

#endif
