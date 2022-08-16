#include "Jaguar.h"
#include"EnemyState.h"
#include <iostream>

Jaguar::Jaguar(int hp, std::string attackMove, int attackDamage, std::string defensiveMove):Enemy( hp, attackMove, attackDamage,defensiveMove) {
	
}

void Jaguar::celebrate(){
	std::cout<<"Should have fought harder soldier."<<std::endl;
 }

 bool Jaguar::getHit(SquadMember *z){
	std::cout<<"Growls in pain as he is maimed. Jaguar turns around and delivers "<< defensiveMove<<" agains "<< z->getName()<<"."<<std::endl;
	if (HP-(z->getDamage())<=0)
	{
		HP=0;
		return true;
	}

	HP-=(z->getDamage());
	return false;
	
 }

 void Jaguar::die(){
	std::cout<<"Gives one last growl before falling over."<<std::endl;
 }

 bool Jaguar::hitSquadMember(SquadMember* z){
	std::cout<<"Jaguar leaps toward the "<< z->getName()<<" and delivers a forceful "<< attackMove<<"."<<std::endl;
	if (z->takeDamage(attackDamage)==0)
	{
		return true;
	}

	return false;	
	
 }

 EnemyState* Jaguar::saveState(){
	return new EnemyState(HP,attackMove,attackDamage,defensiveMove,1);
 }