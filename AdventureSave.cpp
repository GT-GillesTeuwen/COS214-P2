#include "AdventureSave.h"
#include <iostream>
#include <fstream>
#include <string>

AdventureSave::AdventureSave(SquadState *squadSave, std::vector<ArenaState *> layoutSave, int ttlKeys, int numRooms, int numCleared)
{
    this->squadSave = squadSave;
    this->layoutSave = layoutSave;
    this->ttlKeys = ttlKeys;
    this->numRooms = numRooms;
    this->numCleared = numCleared;
}

AdventureSave::AdventureSave(std::string nameOfFile)
{
    std::string filename(nameOfFile);
    std::vector<std::string> lines;
    std::string line;

    std::ifstream input_file(filename);

    while (getline(input_file, line))
    {
        lines.push_back(line);
    }

    for (int i = 0; i < lines.size(); i++)
        std::cout << lines.at(i) << std::endl;

    input_file.close();

    int fileIndex = 0;
    std::vector<std::string> parts={};

    int counter=1;
			int arrPos=0;
			std::string temp="";
			for (int i = 0; i < lines.at(fileIndex).length(); i++)
			{	
				if (lines.at(fileIndex).at(i)==',')
				{
					parts.push_back(temp);
					temp="";
					arrPos++;
				}else{
					temp+=(lines.at(fileIndex).at(i));
					if (i==lines.at(fileIndex).length()-1)
						{
							parts.push_back(temp);
							temp="";
							arrPos++;
						}
				}
			}
    this->ttlKeys = stoi(parts.at(0));
    this->numRooms = stoi(parts.at(1));std::cout<<"45"<<std::endl;
    this->numCleared = stoi(parts.at(2));
    std::vector<SquadMemberState*> squadMembersStates;
    fileIndex++;
    int numLine = fileIndex;

    fileIndex++;
    std::cout<<"52"<<std::endl;
    for (int i = 0; i < stoi(lines.at(numLine)); i++)
    {
        std::vector<std::string> parts={};

    int counter=1;
			int arrPos=0;
			std::string temp="";
			for (int i = 0; i < lines.at(fileIndex).length(); i++)
			{	
				if (lines.at(fileIndex).at(i)==',')
				{
					parts.push_back(temp);
					temp="";
					arrPos++;
				}else{
					temp+=(lines.at(fileIndex).at(i));
					if (i==lines.at(fileIndex).length()-1)
						{
							parts.push_back(temp);
							temp="";
							arrPos++;
						}
				}
			}
        
        SquadMemberState *s = new SquadMemberState(stoi(parts.at(0)), stoi(parts.at(1)), parts.at(2));
        squadMembersStates.push_back(s);
        fileIndex++;
    }

    SquadState *squadSave = new SquadState(stoi(lines.at(numLine)), squadMembersStates);
    this->squadSave=squadSave;
    std::vector<ArenaState*> layoutState;
    std::cout<<"72"<<std::endl;
    for (int k = 0; k < numRooms; k++)
    {
        std::string delimiter = ",";

        std::vector<std::string> parts={};

    int counter=1;
			int arrPos=0;
			std::string temp="";
			for (int i = 0; i < lines.at(fileIndex).length(); i++)
			{	
				if (lines.at(fileIndex).at(i)==',')
				{
					parts.push_back(temp);
					temp="";
					arrPos++;
				}else{
					temp+=(lines.at(fileIndex).at(i));
					if (i==lines.at(fileIndex).length()-1)
						{
							parts.push_back(temp);
							temp="";
							arrPos++;
						}
				}
			}
        fileIndex++;
        std::vector<EnemyState*> troopsStates;
        for (int j = 0; j < stoi(parts.at(3)); j++)
        {
            std::vector<std::string> innerParts{};

    int counter=1;
			int arrPos=0;
			std::string temp="";
			for (int l = 0; l < lines.at(fileIndex).length(); l++)
			{	
				if (lines.at(fileIndex).at(l)==',')
				{
					innerParts.push_back(temp);
					temp="";
					arrPos++;
				}else{
					temp+=(lines.at(fileIndex).at(l));
					if (l==lines.at(fileIndex).length()-1)
						{
							innerParts.push_back(temp);
							temp="";
							arrPos++;
						}
				}
                
			}

            troopsStates.push_back(new EnemyState(stoi(innerParts.at(0)),innerParts.at(1),stoi(innerParts.at(2)),innerParts.at(3),stoi(innerParts.at(4))));
        fileIndex++;

        }
        std::cout<<"DIFF "<<stoi(parts.at(3))<<std::endl;
        layoutState.push_back(new ArenaState(parts.at(0),stoi(parts.at(1))==1,stoi(parts.at(2))==1,stoi(parts.at(3)),troopsStates));
    }

    this->layoutSave=layoutState;
   

}

AdventureSave::~AdventureSave()
{
    delete squadSave;
    for (int i = 0; i < layoutSave.size(); i++)
    {
        delete layoutSave.at(i);
    }
}

void AdventureSave::writeToFile()
{
    std::ofstream saveFile("save.txt");
    std::string saveString;
    saveString += (std::to_string(ttlKeys) + "," + std::to_string(numRooms) + "," + std::to_string(numCleared) + "\n");
    saveString += squadSave->writeToFile();
    for (int i = 0; i < layoutSave.size(); i++)
    {
        saveString += layoutSave.at(i)->writeToFile();
    }

    saveFile << saveString;
    saveFile.close();
}
