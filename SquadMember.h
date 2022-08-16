#ifndef SQUADMEMBER_H
#define SQUADMEMBER_H

#include<string>
#include"SquadState.h"

class SquadMember {
public:

	SquadMember(std::string name);

	SquadMember* clone(std::string name);

	std::string getName();

	int getHp();

	int getDamage();

	void setHp(int newHp);

	void setDamage(int newDamage);

	int takeDamage(int damageDone);

	SquadMemberState* saveState();
private:
	int hp;
	int damage;
	std::string name;


};

#endif
