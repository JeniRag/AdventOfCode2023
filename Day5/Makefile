CC := g++

CLASS := AlmanacList

Functions.o : Functions.cpp Functions.hpp $(CLASS).hpp Category.hpp
	g++ -c -O Functions.cpp
	
$(CLASS).o: $(CLASS).cpp $(CLASS).hpp Category.hpp
	g++ -c -O $(CLASS).cpp

main.o: main.cpp Functions.hpp $(CLASS).hpp
	g++ -c -O main.cpp

main: main.o Functions.o $(CLASS).o 
	g++ -O -o main main.o Functions.o $(CLASS).o

tests.cpp: TestSuite.hpp Functions.hpp $(CLASS).hpp
	cxxtestgen --error-printer -o tests.cpp TestSuite.hpp

tests.o: tests.cpp
	g++ -c -O tests.cpp

tests: Functions.o $(CLASS).o tests.o 
	g++ -O -o tests tests.o Functions.o $(CLASS).o

all: main tests

clean: 	
	rm -f main.o Functions.o tests.o tests.cpp $(CLASS).o