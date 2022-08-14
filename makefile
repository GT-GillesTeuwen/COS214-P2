all: compile run clear

compile:
	g++ -c main.cpp
	g++ -c SquadMember.cpp
	g++ -c Enemy.cpp
	g++ -c Snake.cpp
	g++ -o main Enemy.o Snake.o SquadMember.o main.o

clear:
	rm *.o

run:
	./main