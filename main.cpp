#include<iostream>
#include "Enemy.h"
#include "Snake.h"
#include "SquadMember.h"

std::string currentTest;
int tests=0;
int passed=0;

void startTest(std::string name){
    std::cout<<"\n====================\nStarting test: "<<name<<"\n===================="<<std::endl;
    tests=0;
    passed=0;
    currentTest=name;
}

void testSummary(){
    std::cout<<"\n====================\nTest: "<<currentTest<<" --> Passed "<<passed<<"/"<<tests<<"\n===================="<<std::endl;
    tests=0;
    passed=0;
}


template <typename T>
void assertEquals(T actual,T exptected){
    tests++;
    if (actual==exptected)
    {
        passed++;
    }
     std::cout<<"Passed "<<passed<<"/"<<tests<<std::endl;
    
}

int main(){
    
    SquadMember* sq=new SquadMember("Angus");
    sq->setHp(3);
    sq->setDamage(1);

    

    startTest("Snake functions");
    Enemy* s=new Snake(2,"venom",2,"curl up");
    s->celebrate();
    assertEquals<bool>(s->getHit(sq),false);
    assertEquals<bool>(s->hitSquadMember(sq),false);
    assertEquals<bool>(s->hitSquadMember(sq),true);
    assertEquals<bool>(s->getHit(sq),true);
    
    s->die();
    testSummary();

    startTest("SquadMember functions");
    sq->setHp(10);
    assertEquals<int>(sq->getHp(),10);
    sq->takeDamage(2);
    assertEquals<int>(sq->getHp(),8);
    sq->takeDamage(7);
    assertEquals<int>(sq->getHp(),1);
    sq->takeDamage(20);
    assertEquals<int>(sq->getHp(),0);

    assertEquals<int>(sq->getDamage(),1);

    testSummary();

    delete sq;
    delete s;
    return 0;
}