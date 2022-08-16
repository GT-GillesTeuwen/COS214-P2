#include "SquadMember.h"
#include "SquadMemberState.h"
#include <iostream>

SquadMember::SquadMember(std::string name) {
	this->name=name;
}

SquadMember* SquadMember::clone(std::string name) {
	SquadMember* theClone= new SquadMember(name);
	theClone->setDamage(this->getDamage());
	theClone->setHp(this->getHp());
	return theClone;
}

SquadMemberState* SquadMember::saveState(){
	return new SquadMemberState(hp,damage,name);
}

std::string SquadMember::getName() {
	return this->name;
}

int SquadMember::getHp() {
	return this->hp;
}

int SquadMember::getDamage() {
	return this->damage;
}

void SquadMember::setHp(int newHp) {
	this->hp = newHp;
}

void SquadMember::setDamage(int newDamage) {
	this->damage = newDamage;
}

int SquadMember::takeDamage(int damageDone){
	if (hp-damageDone<=0)
	{
		hp=0;
		return hp;
	}

	hp-=damageDone;
	return hp;
}
