#include "AdventureIsland.h"
#include "AdventureSave.h"
#include "Arena.h"
#include <string>
#include <iostream>

AdventureIsland::AdventureIsland(int rooms, int squadMembers)
{
    std::string name = "The OG Soldier";
    currentTeam.push_back(new SquadMember(name));
    currentTeam.at(0)->setDamage(1);
    currentTeam.at(0)->setHp(20);
    for (int i = 0; i < squadMembers-1; i++)
    {
        std::string name = "Soldier_" + std::to_string(i);
        currentTeam.push_back(currentTeam.at(0)->clone(name));
    }
    this->numRooms = rooms;
    this->ttlLocks = (rand() % (numRooms / 2));
    int keysLeft = ttlLocks - 1;
    this->ttlKeys = 1;
    for (int i = 0; i < numRooms; i++)
    {
        int locked = 1;
        if (ttlLocks != 0)
        {
            locked = (rand() % (((int)(numRooms - i)) / ttlLocks));
        }
        int key = 1;
        if (keysLeft != 0)
        {
            key = (rand() % (((int)(numRooms - i)) / keysLeft));
        }

        std::cout << i << std::endl;
        if (key == 0)
        {
            keysLeft--;
        }
        if (locked == 0)
        {
            ttlLocks--;
        }

        std::string roomName = "Arena " + std::to_string(i);
        layout.push_back(new Arena(roomName, key == 0, locked == 0));
    }
}

AdventureIsland::AdventureIsland(AdventureSave *oldAdventure)
{

    for (int i = 0; i < oldAdventure->squadSave->numMembers; i++)
    {
        currentTeam.push_back(new SquadMember(oldAdventure->squadSave->squadMembersave.at(i)->name));
        currentTeam.at(i)->setDamage(oldAdventure->squadSave->squadMembersave.at(i)->damage);
        currentTeam.at(i)->setHp(oldAdventure->squadSave->squadMembersave.at(i)->health);
    }

    this->numRooms = oldAdventure->numRooms;
    this->ttlKeys = oldAdventure->ttlKeys;
    for (int i = 0; i < numRooms; i++)
    {

        std::string roomName = "Arena " + std::to_string(i);
        std::cout<<oldAdventure->layoutSave.at(i)->difficulty<<std::endl;
        layout.push_back(new Arena(oldAdventure->layoutSave.at(i)->name, oldAdventure->layoutSave.at(i)->hasKey, oldAdventure->layoutSave.at(i)->isLocked,
                                   oldAdventure->layoutSave.at(i)->difficulty, oldAdventure->layoutSave.at(i)->stateOftroops));
    }
}

AdventureSave *AdventureIsland::saveAdventure()
{
    std::vector<SquadMemberState *> squadSave;
    for (size_t i = 0; i < currentTeam.size(); i++)
    {
        squadSave.push_back(currentTeam.at(i)->saveState());
    }

    std::vector<ArenaState *> layoutSave;
    for (int i = 0; i < numRooms; i++)
    {
        layoutSave.push_back(layout.at(i)->saveState());
    }

    SquadState *squadState = new SquadState(currentTeam.size(), squadSave);

    return new AdventureSave(squadState, layoutSave, ttlKeys, numRooms, numCleared);
}

void AdventureIsland::beginAdventure()
{
    std::cout << "You embark on a new journey" << std::endl;
}

void AdventureIsland::playLoop(bool &over)
{
    if (numCleared < numRooms)
    {
        std::cout << "\nPlayer Turn";
        std::cout << "\nKeys: " << ttlKeys << std::endl;
        listRooms();
        int chosen = chooseRoom();
        if (layout.at(chosen)->tryEnter(ttlKeys))
        {
            if (layout.at(chosen)->fight(currentTeam, ttlKeys) > 0)
            {
                this->numCleared++;
            }
            else
            {
                std::cout << "Your party has died, try again" << std::endl;
                over = true;
            }
        }
    }

    if (numCleared == numRooms)
    {
        std::cout << "\n===================\nWell done! You win\n===================\n"
                  << std::endl;
        over = true;
    }
}

void AdventureIsland::listRooms()
{
    std::cout << "You see a collection of tribal arenas" << std::endl;
    for (int i = 0; i < layout.size(); i++)
    {
        std::cout << "\t" << layout.at(i)->getName() << std::endl;
    }
}

int AdventureIsland::chooseRoom()
{
    int chosenRoom;
    std::cout << "Which arena would you like to enter?" << std::endl;
    std::cin >> chosenRoom;
    return chosenRoom;
}

AdventureIsland::~AdventureIsland()
{
    for (int i = 0; i < layout.size(); i++)
    {
        delete layout.at(i);
    }

    for (int i = 0; i < currentTeam.size(); i++)
    {
        delete currentTeam.at(i);
    }
}
