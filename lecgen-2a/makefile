main: main.o deck.o card.o
	g++ main.o deck.o card.o -o main
code.o: card.cpp card.h
	g++ -g -Wall -c card.cpp
main.o: main.cpp card.h deck.h
	g++ -g -Wall -c main.cpp
response.o: deck.cpp deck.h
	g++ -g -Wall -c deck.cpp

clean:
	rm main.o card.o deck.o main
