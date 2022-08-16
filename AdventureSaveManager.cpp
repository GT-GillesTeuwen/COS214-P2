#include "AdventureSaveManager.h"
#include <iostream>
#include <fstream>

AdventureSaveManager::AdventureSaveManager()
{
    
    
}

void AdventureSaveManager::createSave(AdventureSave *newSave)
{
    adventures.push_back(newSave);
    newSave->writeToFile();

}
AdventureSave *AdventureSaveManager::loadSave()
{
    adventures.push_back(new AdventureSave("save.txt"));
    return adventures.back();

}
AdventureSaveManager::~AdventureSaveManager()
{
    for (int i = 0; i < adventures.size(); i++)
    {
        delete adventures.at(i);
    }
    
}