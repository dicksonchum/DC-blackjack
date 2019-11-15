all: blackjack

blackjack: main.o Card.o Deck.o Player.o Dealer.o Hand.o
	g++ main.o Card.o Deck.o Player.o Dealer.o Hand.o -o blackjack

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

Card.o: Card.cpp Card.hpp
	g++ -c -std=c++11 Card.cpp

Deck.o: Deck.cpp Deck.hpp
	g++ -c -std=c++11 Deck.cpp

Player.o: Player.cpp Player.hpp
	g++ -c -std=c++11 Player.cpp

Dealer.o: Dealer.cpp Dealer.cpp
	g++ -c -std=c++11 Dealer.cpp

Hand.o: Hand.cpp Hand.hpp
	g++ -c -std=c++11 Hand.cpp

clean:
	rm -f *o blackjack