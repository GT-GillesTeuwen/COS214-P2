#include "Gorilla.h"
#include <iostream>

Gorilla::Gorilla(int hp, std::string attackMove, int attackDamage, std::string defensiveMove):Enemy( hp, attackMove, attackDamage,defensiveMove) {
	
}

void Gorilla::celebrate(){
	std::cout<<"Player tried in vain to save himself."<<std::endl;
 }

 bool Gorilla::getHit(SquadMember *z){
	std::cout<<"Roars and hits his chest with anger."<<std::endl;
	if (HP-(z->getDamage())<=0)
	{
		HP=0;
		return true;
	}

	HP-=(z->getDamage());
	return false;
	
 }

 void Gorilla::die(){
	std::cout<<"The earth shakes as the gorilla falls to the ground."<<std::endl;
 }

 bool Gorilla::hitSquadMember(SquadMember* z){
	std::cout<<"Gorilla slams his fists to the ground, growls and hits "<< z->getName()<<" with "<< attackMove<<"."<<std::endl;
	if (z->takeDamage(attackDamage)==0)
	{
		return true;
	}

	return false;	
	
 }
