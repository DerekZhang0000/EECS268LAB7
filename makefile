Exercise1: main.o CeoOfBlob.o Map.o
	g++ -std=c++11 -g -Wall main.o CeoOfBlob.o Map.o -o Exercise1
main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
CeoOfBlob.o: CeoOfBlob.h CeoOfBlob.cpp
	g++ -std=c++11 -g -Wall -c CeoOfBlob.cpp
Map.o: Map.h Map.cpp
	g++ -std=c++11 -g -Wall -c Map.cpp