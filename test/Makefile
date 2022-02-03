test: main.o Executive.o Board.o
	g++ -std=c++11 -g -Wall main.o Executive.o Board.o -o test

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o:  Executive.cpp Executive.h Board.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

Board.o: Board.cpp Board.h
	g++ -std=c++11 -g -Wall -c Board.cpp

clean:
	rm *.o test
