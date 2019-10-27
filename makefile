output: main.o printBoard.o menu.o integerValidation.o inBounds.o Board.o Ant.o
	g++ -std=c++11 main.o printBoard.o menu.o integerValidation.o inBounds.o Board.o Ant.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

printBoard.o: printBoard.cpp printBoard.h
	g++ -std=c++11 -c printBoard.cpp

menu.o: menu.cpp menu.h
	g++ -std=c++11 -c menu.cpp

integerValidation.o: integerValidation.cpp integerValidation.h
	g++ -std=c++11 -c integerValidation.cpp

inBounds.o: inBounds.cpp inBounds.h
	g++ -std=c++11 -c inBounds.cpp

Board.o: Board.cpp Board.h
	g++ -std=c++11 -c Board.cpp

Ant.o: Ant.cpp Ant.h
	g++ -std=c++11 -c Ant.cpp

clean:
	rm *.o output
