all: compile run clear

compile:
	g++ -c main.cpp
	g++ -c SquadMember.cpp
	g++ -c Enemy.cpp
	g++ -c Snake.cpp
	g++ -c Jaguar.cpp
	g++ -c Gorilla.cpp
	g++ -c Cannibal.cpp
	g++ -o main Enemy.o Snake.o Jaguar.o Gorilla.o Cannibal.o SquadMember.o main.o

clear:
	rm *.o

run:
	./main