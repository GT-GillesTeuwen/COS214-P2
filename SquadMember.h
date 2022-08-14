#ifndef SQUADMEMBER_H
#define SQUADMEMBER_H

#include<string>

class SquadMember {
public:
	SquadMember* clone();

	std::string getName();

	int getHp();

	int getDamage();

	void setHp(int newHp);

	void setDamage(int newDamage);

	int takeDamage(int damageDone);
private:
	int hp;
	int damage;
	std::string name;


};

#endif
