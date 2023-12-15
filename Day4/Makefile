Functions.o : Functions.cpp Functions.hpp
	g++ -c -O Functions.cpp

main.o: main.cpp Functions.hpp
	g++ -c -O main.cpp

main: main.o Functions.o 
	g++ -O -o main main.o Functions.o

tests.cpp: TestSuite.hpp Functions.hpp
	cxxtestgen --error-printer -o tests.cpp TestSuite.hpp

tests.o: tests.cpp
	g++ -c -O tests.cpp

tests: Functions.o tests.o 
	g++ -O -o tests tests.o Functions.o

all: main tests

clean: 	
	rm -f main.o Functions.o tests.o tests.cpp