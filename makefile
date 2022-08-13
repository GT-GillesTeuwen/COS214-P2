all: compile run clear

compile:
	g++ -c main.cpp
	g++ -o main main.o

clear:
	rm *.o

run:
	./main