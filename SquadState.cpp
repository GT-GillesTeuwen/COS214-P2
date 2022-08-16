#include "SquadState.h"

SquadState::SquadState(int numMembers, std::vector<SquadMemberState *> squadSave)
{
    this->numMembers=numMembers;
    this->squadMembersave=squadSave;
}
SquadState::~SquadState()
{
}

std::string SquadState::writeToFile(){
    std::string squadString=std::to_string(numMembers)+"\n";
    for (int i = 0; i < squadMembersave.size(); i++)
    {
        squadString+=squadMembersave.at(i)->writeToFile();
    }
    
    return squadString;
}