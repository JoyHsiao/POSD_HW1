INC_DIR = include

all: hw1

hw1: main.o Shapes.o Media.o Sort.o
ifeq (${OS}, Windows_NT)
	g++ -g3 -o hw1 main.o Shapes.o Media.o Sort.o -lgtest
else
	g++ -g3 -o hw1 main.o Shapes.o Media.o Sort.o -lgtest -lpthread
endif
	
main.o: main.cpp utSort.h
	g++ -g3 -std=gnu++0x -c main.cpp
Sort.o: $(INC_DIR)/Sort.h Sort.cpp
	g++ -g3 -std=gnu++0x -c Sort.cpp
Shapes.o: $(INC_DIR)/Shapes.h Shapes.cpp
	g++ -g3 -std=gnu++0x -c Shapes.cpp
Media.o: $(INC_DIR)/Media.h Media.cpp
	g++ -g3 -std=gnu++0x -c Media.cpp

clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw1
endif
