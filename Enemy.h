#ifndef ENEMY_H
#define ENEMY_H

#include<string>
#include "SquadMember.h"

class Enemy {

protected:
	int HP;
	std::string attackMove;
	int attackDamage;
	std::string defensiveMove;

public:
	Enemy(int hp, std::string attackMove, int attackDamage, std::string defensiveMove);

	void attack(SquadMember* squadMember);

	virtual void celebrate() = 0;

	virtual bool getHit(SquadMember* z) = 0;

	virtual void die() = 0;

	virtual bool hitSquadMember(SquadMember* z)=0;
};

#endif