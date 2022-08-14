#include "SquadMember.h"

SquadMember* SquadMember::clone() {
	// TODO - implement SquadMember::clone
	throw "Not yet implemented";
}

string SquadMember::getName() {
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
