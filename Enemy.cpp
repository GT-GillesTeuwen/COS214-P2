#include "Enemy.h"
#include <string>
#include <iostream>

Enemy::Enemy(int hp, std::string attackMove, int attackDamage, std::string defensiveMove,std::string name) {
	this->HP=hp;
	this->attackMove=attackMove;
	this->attackDamage=attackDamage;
	this->defensiveMove=defensiveMove;
	this->name=name;
}

void Enemy::attack(SquadMember* squadMember) {
	std::cout<<squadMember->getName()<<"("<<squadMember->getHp()<<") is fighting"<<std::endl;
	while (squadMember->getHp()>0 && HP>0)
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

int Enemy::getHealth(){
	return this->HP;
}
