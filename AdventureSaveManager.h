#ifndef ADVENTURESAVEMANAGER_H
#define ADVENTURESAVEMANAGER_H

#include<string>
#include<vector>
#include "AdventureSave.h"

class AdventureSaveManager {
public:

	AdventureSaveManager();
    void createSave(AdventureSave* newSave);
    
    AdventureSave* loadSave();
    ~AdventureSaveManager();   

private:


private:
    std::vector<AdventureSave*> adventures;

};

#endif