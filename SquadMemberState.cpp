#include "SquadMemberState.h"
#include<string>
#include<iostream>

SquadMemberState::SquadMemberState(int inHealth, int damage, std::string name)
{
    this->health=inHealth;
    this->damage=damage;
    this->name=name;
}
SquadMemberState::~SquadMemberState()
{
}

std::string SquadMemberState::writeToFile(){
    std::cout<<std::to_string(health)<<std::endl;
    return std::to_string(health)+","+std::to_string(damage)+","+name+"\n";
}