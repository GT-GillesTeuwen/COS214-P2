#include "Arena.h"
#include "Snake.h"
#include "Jaguar.h"
#include "Gorilla.h"
#include "Cannibal.h"
#include "EnemyFactory.h"
#include "SnakeFactory.h"
#include "JaguarFactory.h"
#include "GorillaFactory.h"
#include "CannibalFactory.h"
#include "EnemyState.h"
#include"ArenaState.h"
#include <iostream>

Arena::Arena(std::string name, bool hasKey, bool isLocked)
{
    this->name = name;
    this->difficulty = (rand() % 5 + 1);
    this->isLocked = isLocked;
    this->hasKey = hasKey;
    spawner.push_back(new SnakeFactory());
    spawner.push_back(new JaguarFactory());
    spawner.push_back(new GorillaFactory());
    spawner.push_back(new CannibalFactory());

    initArena();
}

Arena::Arena(std::string name, bool hasKey, bool isLocked, int difficulty, std::vector<EnemyState *> stateOftroops)
{
    this->name = name;
    this->difficulty = difficulty;
    this->isLocked = isLocked;
    this->hasKey = hasKey;
    spawner.push_back(new SnakeFactory());
    spawner.push_back(new JaguarFactory());
    spawner.push_back(new GorillaFactory());
    spawner.push_back(new CannibalFactory());

    initArena(stateOftroops);
}

ArenaState* Arena::saveState(){

    std::vector<EnemyState*> stateOftroops;
    for (int i = 0; i < troops.size(); i++)
    {
        stateOftroops.push_back(troops.at(i)->saveState());
    }

    return new ArenaState(name,hasKey,isLocked,difficulty,stateOftroops);
}

bool Arena::tryEnter(int &numKeys)
{
    if (isLocked && numKeys <= 0)
    {
        std::cout << "The door is locked, you cannot enter" << std::endl;
        return false;
    }
    else
    {
        if (isLocked)
        {
            std::cout << "The party uses their key to unlock the door" << std::endl;
            numKeys--;
        }
        isLocked = false;
        return lookAround();
    }
}

bool Arena::lookAround()
{
    std::string input;

    if (listEnemies())
    {
        std::cout << "Do you engage (Y/N)" << std::endl;
        std::cin >> input;

        if (input == "Y")
        {
            std::cout << "You ready your weapons" << std::endl;
            return true;
        }
        else
        {
            std::cout << "You flee out the door" << std::endl;
            return false;
        }
    }
    std::cout << "The arena is empty" << std::endl;
    return false;
}

void Arena::initArena()
{
    for (int i = 0; i < difficulty; i++)
    {
        int enemyType = rand() % 3;
        if (difficulty > 4)
        {
            enemyType = rand() % 4;
        }
        troops.push_back(spawner.at(enemyType)->createEnemy("weapon", "defence"));
    }
}

void Arena::initArena(std::vector<EnemyState *> stateOftroops)
{
    std::cout<<difficulty<<std::endl;
    for (int i = 0; i < difficulty; i++)
    {
        if (stateOftroops.at(i)->type == 0)
        {
            troops.push_back(new Snake(stateOftroops.at(i)->health, stateOftroops.at(i)->weapon, stateOftroops.at(i)->damage, stateOftroops.at(i)->defence));
        }
        else if (stateOftroops.at(i)->type == 1)
        {
            troops.push_back(new Jaguar(stateOftroops.at(i)->health, stateOftroops.at(i)->weapon, stateOftroops.at(i)->damage, stateOftroops.at(i)->defence));
        }
        else if (stateOftroops.at(i)->type == 2)
        {
            troops.push_back(new Gorilla(stateOftroops.at(i)->health, stateOftroops.at(i)->weapon, stateOftroops.at(i)->damage, stateOftroops.at(i)->defence));
        }
        else if (stateOftroops.at(i)->type == 3)
        {
            troops.push_back(new Cannibal(stateOftroops.at(i)->health, stateOftroops.at(i)->weapon, stateOftroops.at(i)->damage, stateOftroops.at(i)->defence));
        }
    }
}

bool Arena::listEnemies()
{
    std::cout << "You look around and see " << troops.size() << " enemies, waiting to fight" << std::endl;
    return troops.size() > 0;
}

int Arena::fight(std::vector<SquadMember *> team, int &numkeys)
{
    for (int i = 0; i < troops.size() && !tpk(team); i++)
    {

        int attacked = rand() % team.size();
        while (team.at(attacked)->getHp() <= 0)
        {
            attacked = rand() % team.size();
        }
        troops.at(i)->attack(team.at(attacked));
    }

    if (tpk(team))
    {
        return 0;
    }

    clearArena();
    this->difficulty=0;
    std::cout << "Level " << difficulty << " arena conquered" << std::endl;
    if (hasKey)
    {
        std::cout << "Key Obtained" << std::endl;
        numkeys++;
    }

    return difficulty;
}

std::string Arena::getName()
{
    return name;
}

Arena::~Arena()
{
    for (int i = 0; i < spawner.size(); i++)
    {
        delete spawner.at(i);
    }

    for (int i = 0; i < troops.size(); i++)
    {
        delete troops.at(i);
    }
}

bool Arena::tpk(std::vector<SquadMember *> team)
{

    for (int i = 0; i < team.size(); i++)
    {
        if (team.at(i)->getHp() > 0)
        {
            return false;
        }
    }

    return true;
}

void Arena::clearArena()
{
    int size = troops.size();
    for (int i = size - 1; i >= 0; i--)
    {
        delete troops.at(i);
        troops.pop_back();
    }
}

