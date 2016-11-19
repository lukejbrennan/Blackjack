all: main

main: main.o CardDeck.o
	g++ main.o CardDeck.o -o main

CardDeck.o: CardDeck.cpp
	g++ -c CardDeck.cpp

clean:
	rm -f *.o *~ main

