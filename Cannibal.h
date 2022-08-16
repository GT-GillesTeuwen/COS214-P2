#ifndef CANNIBAL_H
#define CANNIBAL_H

#include "Enemy.h"
#include "EnemyState.h"

class Cannibal : public Enemy {


public:
	Cannibal(int hp, std::string attackMove, int attackDamage, std::string defensiveMove);

	virtual void celebrate();

	virtual bool getHit(SquadMember* z);

	virtual void die();

	virtual bool hitSquadMember(SquadMember* z);
	virtual EnemyState* saveState();
	
};

#endif
