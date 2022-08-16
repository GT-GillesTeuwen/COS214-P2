#ifndef JAGUAR_H
#define JAGUAR_H

#include "Enemy.h"
#include "EnemyState.h"

class Jaguar : public Enemy {


public:
	Jaguar(int hp, std::string attackMove, int attackDamage, std::string defensiveMove,std::string name);

	virtual void celebrate();

	virtual bool getHit(SquadMember* z);

	virtual void die();

	virtual bool hitSquadMember(SquadMember* z);
	virtual EnemyState* saveState();
	
};

#endif
