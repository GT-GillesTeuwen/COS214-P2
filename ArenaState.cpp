#include"ArenaState.h"

ArenaState::ArenaState(std::string name,bool hasKey,bool isLocked, int difficulty,std::vector<EnemyState*> stateOftroops){
 this->name=name;
 this->hasKey=hasKey;
 this->isLocked=isLocked;
 this->difficulty=difficulty;
 this->stateOftroops=stateOftroops;

}
ArenaState::~ArenaState(){
    for (int i = 0; i < stateOftroops.size(); i++)
    {
        delete stateOftroops.at(i);
    }
    
}

std::string ArenaState::writeToFile(){
    std::string saveString=name+","+std::to_string(hasKey)+","+std::to_string(isLocked)+","+std::to_string(difficulty)+"\n";
    for (int i = 0; i < stateOftroops.size(); i++)
    {
        saveString+=stateOftroops.at(i)->writeToFile();
    }
    
    return saveString;
}