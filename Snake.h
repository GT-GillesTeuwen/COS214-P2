#ifndef SNAKE_H
#define SNAKE_H

#include "Enemy.h"

class Snake : public Enemy {


public:
	Snake(int hp, std::string attackMove, int attackDamage, std::string defensiveMove);

	virtual void celebrate();

	virtual bool getHit(SquadMember* z);

	virtual void die();
	
	virtual bool hitSquadMember(SquadMember* z);
};

#endif
