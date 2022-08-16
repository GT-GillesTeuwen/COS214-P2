#ifndef ADVENTUREISLAND_H
#define ADVENTUREISLAND_H

#include<string>
#include<vector>
#include "SquadMember.h"
#include "Arena.h"
#include "AdventureSave.h"

class AdventureIsland {
public:

	AdventureIsland(int rooms,int squadMembers);
    AdventureIsland(AdventureSave* oldAdventure);
    ~AdventureIsland();
	void beginAdventure();
    void listRooms();
    int chooseRoom();
    void playLoop(bool &over);
    AdventureSave* saveAdventure();
    void loadAdventure(AdventureSave* oldAdventure);



private:
	
    std::vector<SquadMember*> currentTeam;
    std::vector<Arena*> layout;
    int ttlLocks;
    int ttlKeys;
    int numRooms;
    int numCleared;


};

#endif
