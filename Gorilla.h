#ifndef GORILLA_H
#define GORILLA_H

#include "Enemy.h"

class Gorilla : public Enemy {


public:
	Gorilla(int hp, std::string attackMove, int attackDamage, std::string defensiveMove);

	virtual void celebrate();

	virtual bool getHit(SquadMember* z);

	virtual void die();

	virtual bool hitSquadMember(SquadMember* z);
};

#endif