#include "Enemy.h"
#include <string>
#include <iostream>

Enemy::Enemy(int hp, std::string attackMove, int attackDamage, std::string defensiveMove) {
	this->HP=hp;
	this->attackMove=attackMove;
	this->attackDamage=attackDamage;
	this->defensiveMove=defensiveMove;
}

void Enemy::attack(SquadMember* squadMember) {
	while (squadMember->getHp()>0)
	{
		if (hitSquadMember(squadMember))
		{
			std::cout<<squadMember->getName()<<" died"<<std::endl;
			celebrate();
		}else{
			if (getHit(squadMember))
			{
				die();
			}
			
		}
		
	}
	
}
