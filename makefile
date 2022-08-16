all: compile run clear

compile:
	g++ -c main.cpp
	g++ -c SquadMember.cpp
	g++ -c Enemy.cpp
	g++ -c Snake.cpp
	g++ -c Jaguar.cpp
	g++ -c Gorilla.cpp
	g++ -c Cannibal.cpp
	g++ -c EnemyFactory.cpp
	g++ -c SnakeFactory.cpp
	g++ -c JaguarFactory.cpp
	g++ -c GorillaFactory.cpp
	g++ -c CannibalFactory.cpp
	g++ -c AdventureIsland.cpp
	g++ -c Arena.cpp
	g++ -c EnemyState.cpp
	g++ -c SquadState.cpp
	g++ -c SquadMemberState.cpp
	g++ -c ArenaState.cpp
	g++ -c AdventureSave.cpp
	g++ -c AdventureSaveManager.cpp
	g++ -o main AdventureSaveManager.o AdventureSave.o ArenaState.o SquadMemberState.o SquadState.o EnemyState.o Enemy.o Snake.o Jaguar.o Gorilla.o Cannibal.o EnemyFactory.o SnakeFactory.o JaguarFactory.o GorillaFactory.o CannibalFactory.o SquadMember.o AdventureIsland.o Arena.o main.o

clear:
	rm *.o

run:
	./main