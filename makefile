all:	program1

program1:	program1.o Card.o
	g++  program1.o Card.o -o program1

program1.o:	program1.cpp
	g++ -c program1.cpp -o program1.o

Card.o: Card.cpp
	g++ -c Card.cpp -o Card.o

clean:
	rm -f *.o program1
