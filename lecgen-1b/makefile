main: main.o code.o response.o mastermind.o
	g++ main.o code.o response.o mastermind.o -o main
code.o: code.cpp code.h
	g++ -g -Wall -c code.cpp
main.o: main.cpp code.h
	g++ -g -Wall -c main.cpp
response.o: response.cpp response.h
	g++ -g -Wall -c response.cpp
mastermind.o: mastermind.cpp mastermind.h #code.o response.o
	g++ -g -Wall -c mastermind.cpp

clean:
	rm main.o code.o response.o mastermind.o main
