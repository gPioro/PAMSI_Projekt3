
CXXFLAGS= -Wall 


main: main.o AI.o 
	g++ -Wall -o main main.o AI.o 

main.o: main.cpp AI.h
	g++ -c ${CXXFLAGS} -o main.o main.cpp

AI.o: AI.cpp AI.h
	g++ -c ${CXXFLAGS} -o AI.o AI.cpp