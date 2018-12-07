cheater: main.o hashTable.o directory.o
	g++ -o cheater main.o hashTable.o directory.o
main.o: main.cpp
	g++ -c main.cpp
hashTable.o: hashTable.cpp hashTable.h
	g++ -c hashTable.cpp
directory.o: directory.cpp directory.h
	g++ -c directory.cpp
