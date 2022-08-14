#include "Snake.h"
#include <iostream>

Snake::Snake(int hp, std::string attackMove, int attackDamage, std::string defensiveMove):Enemy( hp, attackMove, attackDamage,defensiveMove){}

 void Snake::celebrate(){
	std::cout<<"Player tried strongly till the end."<<std::endl;
 }

 bool Snake::getHit(SquadMember *z){
	std::cout<<"Slithers rapidly searching forsafety and employs "<< defensiveMove<<"."<<std::endl;
	if (HP-(z->getDamage())<=0)
	{
		HP=0;
		return true;
	}

	HP-=(z->getDamage());
	return false;
	
 }

 void Snake::die(){
	std::cout<<"Hisses and curls up as he is defeated."<<std::endl;
 }

 bool Snake::hitSquadMember(SquadMember* z){
	std::cout<<"Snake wraps around "<< z->getName()<<" and uses "<< attackMove<<"."<<std::endl;
	if (z->takeDamage(attackDamage)==0)
	{
		return true;
	}

	return false;	
	
 }
