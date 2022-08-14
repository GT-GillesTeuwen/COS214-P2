#include "Cannibal.h"
#include <iostream>

Cannibal::Cannibal(int hp, std::string attackMove, int attackDamage, std::string defensiveMove):Enemy( hp, attackMove, attackDamage,defensiveMove) {
	
}

void Cannibal::celebrate(){
	std::cout<<"Shakes his "<<attackMove<<" at the player's remains"<<std::endl;
 }

 bool Cannibal::getHit(SquadMember *z){
	std::cout<<"The other villagers come running deploying "<<defensiveMove<<"."<<std::endl;
	if (HP-(z->getDamage())<=0)
	{
		HP=0;
		return true;
	}

	HP-=(z->getDamage());
	return false;
	
 }

 void Cannibal::die(){
	std::cout<<"Screams with his last breath, \"I am your father\"."<<std::endl;
 }

 bool Cannibal::hitSquadMember(SquadMember* z){
	std::cout<<"Cannibal rushes towards "<< z->getName()<<" with a "<< attackMove<<"."<<std::endl;
	if (z->takeDamage(attackDamage)==0)
	{
		return true;
	}

	return false;	
	
 }
