#ifndef ARENA_H
#define ARENA_H

#include <string>
#include <vector>
#include "EnemyFactory.h"
#include "Enemy.h"
#include"ArenaState.h"

class Arena
{
public:
    Arena(std::string name, bool hasKey, bool isLocked);
    Arena(std::string name, bool hasKey, bool isLocked, int difficulty, std::vector<EnemyState *> stateOftroops);
    ~Arena();
    bool tryEnter(int &numKeys);
    bool lookAround();
    int fight(std::vector<SquadMember *> team, int &numkeys);
    std::string getName();
    ArenaState* saveState();

private:
    
    void initArena();
    void initArena(std::vector<EnemyState *> stateOftroops);
    bool listEnemies();
    bool tpk(std::vector<SquadMember *> team);
    void clearArena();

private:
    bool hasKey;
    bool isLocked;
    int difficulty;
    std::string name;
    std::vector<EnemyFactory *> spawner;
    std::vector<Enemy *> troops;
};

#endif
