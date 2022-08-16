#ifndef ENEMYSTATE_H
#define ENEMYSTATE_H

#include<string>
#include<vector>

class EnemyState {
public:

	EnemyState(int health,std::string weapon, int damage,std::string defence,int type);
    std::string writeToFile();
    ~EnemyState();   

private:
	friend class Arena;
    int health;
    std::string weapon;
    int damage;
    std::string defence;
    int type;
};

#endif