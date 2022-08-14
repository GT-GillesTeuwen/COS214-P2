#ifndef JAGUAR_H
#define JAGUAR_H

#include "Enemy.h"

class Jaguar : public Enemy {


public:
	Jaguar(int hp, std::string attackMove, int attackDamage, std::string defensiveMove);

	virtual void celebrate();

	virtual bool getHit(SquadMember* z);

	virtual void die();

	virtual bool hitSquadMember(SquadMember* z);
};

#endif
