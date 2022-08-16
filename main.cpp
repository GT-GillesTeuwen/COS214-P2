#include <iostream>
#include <string>
#include "Enemy.h"
#include "Snake.h"
#include "Jaguar.h"
#include "Gorilla.h"
#include "Cannibal.h"
#include "EnemyFactory.h"
#include "SnakeFactory.h"
#include "JaguarFactory.h"
#include "GorillaFactory.h"
#include "CannibalFactory.h"
#include "SquadMember.h"
#include "AdventureIsland.h"
#include "AdventureSaveManager.h"

std::string currentTest;
int tests = 0;
int passed = 0;

void startTest(std::string name)
{
    std::cout << "\n====================\nStarting test: " << name << "\n====================" << std::endl;
    tests = 0;
    passed = 0;
    currentTest = name;
}

void testSummary()
{
    std::cout << "\n====================\nTest: " << currentTest << " --> Passed " << passed << "/" << tests << "\n====================" << std::endl;
    tests = 0;
    passed = 0;
}

template <typename T>
void assertEquals(T actual, T exptected)
{
    tests++;
    if (actual == exptected)
    {
        passed++;
    }
    std::cout << "Passed " << passed << "/" << tests << std::endl;
}

void testFactory(std::string type)
{
    EnemyFactory *factory;
    if (type == "S")
    {
        factory = new SnakeFactory();
        startTest("Snake Factory");
    }
    else if (type == "J")
    {
        factory = new JaguarFactory();
        startTest("Jaguar Factory");
    }
    else if (type == "G")
    {
        factory = new GorillaFactory();
        startTest("Gorilla Factory");
    }
    else if (type == "C")
    {
        factory = new CannibalFactory();
        startTest("Cannibal Factory");
    }

    int healths2[32] = {};
    for (int i = 0; i < 20000; i++)
    {
        Enemy *newDude = factory->createEnemy("bite", "growl");
        healths2[newDude->getHealth()] += 1;
        delete newDude;
    }
    delete factory;

    for (int i = 0; i < 32; i++)
    {
        std::cout << i << ":\t";
        for (int j = 0; j < healths2[i] / 100; j++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

void testTask1()
{
    SquadMember *sq = new SquadMember("Angus");
    sq->setHp(3);
    sq->setDamage(1);

    startTest("Snake functions");
    Enemy *s = new Snake(2, "venom", 2, "curl up");
    s->celebrate();
    assertEquals<bool>(s->getHit(sq), false);
    assertEquals<bool>(s->hitSquadMember(sq), false);
    assertEquals<bool>(s->hitSquadMember(sq), true);
    assertEquals<bool>(s->getHit(sq), true);
    s->die();
    testSummary();

    startTest("SquadMember functions");
    sq->setHp(10);
    assertEquals<int>(sq->getHp(), 10);
    sq->takeDamage(2);
    assertEquals<int>(sq->getHp(), 8);
    sq->takeDamage(7);
    assertEquals<int>(sq->getHp(), 1);
    sq->takeDamage(20);
    assertEquals<int>(sq->getHp(), 0);
    assertEquals<int>(sq->getDamage(), 1);
    testSummary();

    startTest("Enemy array");
    sq->setHp(10);
    Enemy **gang = new Enemy *[4];
    gang[0] = new Snake(2, "venom", 2, "curl up");
    gang[1] = new Jaguar(2, "bite", 2, "growl");
    gang[2] = new Gorilla(2, "pound", 2, "hands up");
    gang[3] = new Cannibal(2, "spear", 2, "shield wall");

    for (int i = 0; i < 4; i++)
    {
        gang[i]->celebrate();
    }
    std::cout << std::endl;
    for (int i = 0; i < 4; i++)
    {
        assertEquals<bool>(gang[i]->hitSquadMember(sq), false);
    }
    std::cout << std::endl;
    for (int i = 0; i < 4; i++)
    {
        assertEquals<bool>(gang[i]->getHit(sq), false);
    }
    std::cout << std::endl;
    for (int i = 0; i < 4; i++)
    {
        gang[i]->die();
    }

    startTest("Cannibal Attack");
    Enemy *e1 = new Cannibal(5, "stick", 2, "shriek");
    sq->setHp(5);
    e1->attack(sq);

    startTest("Jaguar Attack");
    Enemy *e2 = new Jaguar(5, "claw", 4, "hiss");
    sq->setHp(50);
    e2->attack(sq);

    /////////////////
    // Deletes
    ////////////////
    for (int i = 0; i < 4; i++)
    {
        delete gang[i];
    }
    delete gang;
    delete sq;
    delete s;
    delete e1;
    delete e2;
}

void testTask2()
{

    testFactory("S");
    testFactory("J");
    testFactory("G");
    testFactory("C");
}

int main()
{
    // testTask1();
     testTask2();
    AdventureSaveManager *manager = new AdventureSaveManager();
    AdventureIsland *adventure;
    std::string load;
    std::cout << "Do you want to load(L) or start a new game(N)?";
    std::cin >> load;
    if (load == "L")
    {
       adventure=new AdventureIsland(manager->loadSave());
    }
    else
    {
        adventure = new AdventureIsland(5, 10);
    }

    adventure->beginAdventure();
    bool over = false;
    while (!over)
    {
        adventure->playLoop(over);

        std::string ans;
        std::cout << "Do you want to save? (Y/N)";
        std::cin >> ans;
        if (ans == "Y")
        {
            manager->createSave(adventure->saveAdventure());
        }
    }
    delete adventure;
    delete manager;
    return 0;
}