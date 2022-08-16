#include"EnemyState.h"


EnemyState::EnemyState(int health,std::string weapon, int damage,std::string defence,int type){
    this->health=health;
    this->weapon=weapon;
    this->damage=damage;
    this->defence=defence;
    this->type=type;
}
    EnemyState::~EnemyState(){

    }

    std::string EnemyState::writeToFile(){
        return std::to_string(health)+","+(weapon)+","+std::to_string(damage)+","+defence+","+std::to_string(type)+"\n";
    }