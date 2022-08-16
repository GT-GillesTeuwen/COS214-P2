#ifndef ADVENTURESAVE_H
#define ADVENTURESAVE_H

#include<string>
#include<vector>
#include "ArenaState.h"
#include "SquadState.h"

class AdventureSave {
public:

	AdventureSave(SquadState* squadSave,std::vector<ArenaState*> layoutSave,int ttlKeys,int numRooms,int numCleared);
    AdventureSave(std::string nameOfFile);
    void writeToFile();
    
    ~AdventureSave();   

private:
	friend class AdventureIsland;
    SquadState* squadSave;
    std::vector<ArenaState*> layoutSave;
    int ttlKeys;
    int numRooms;
    int numCleared;
};

#endif
