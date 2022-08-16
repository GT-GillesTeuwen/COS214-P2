#ifndef SQUADMEMBERSTATE_H
#define SQUADMEMBERSTATE_H
#include<string>
#include<vector>

class SquadMemberState {
public:

	SquadMemberState(int inHealth,int damage,std::string name);
    std::string writeToFile();
    ~SquadMemberState();   

private:
    friend class AdventureIsland;
    int health;
    int damage;
    std::string name;
};

#endif
