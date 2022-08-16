#ifndef SQUADSTATE_H
#define SQUADSTATE_H

#include <string>
#include <vector>
#include "SquadMemberState.h"

class SquadState
{
public:
    SquadState(int numMembers, std::vector<SquadMemberState *> squadSave);
    std::string writeToFile(); 
    ~SquadState();

private:
    friend class AdventureIsland;
    int numMembers;
   std::vector<SquadMemberState *> squadMembersave;
};

#endif
