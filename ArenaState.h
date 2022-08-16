#ifndef ARENASTATE_H
#define ARENASTATE_H

#include<string>
#include<vector>
#include "EnemyState.h"

class ArenaState {
public:

	ArenaState(std::string name,bool hasKey,bool isLocked, int difficulty,std::vector<EnemyState*> stateOftroops);
    
    std::string writeToFile();
    ~ArenaState();   

private:
	friend class AdventureIsland;
    bool hasKey;
    bool isLocked;
    int difficulty;
    std::string name;
    std::vector<EnemyState*> stateOftroops;
};

#endif
