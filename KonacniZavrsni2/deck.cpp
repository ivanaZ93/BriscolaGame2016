#include <cstdlib>
#include <time.h>
#include "deck.h"

Deck::Deck() {
    inDeck();
    shuffleDeck();
}

Deck::~Deck() {
}

Card& Deck::operator[](int x) {
    return deck[x];
}

void Deck::inDeck() {

    int x = 1;

    for (int i = 0; i < 10; i++) {
        deck[i].setTypeOfCard("Dinari");
        deck[i].setStrength(x);
        ++x;
    }

    x = 1;
    for (int i = 10; i < 20; i++) {
        deck[i].setTypeOfCard("Bastoni");
        deck[i].setStrength(x);
        ++x;
    }

    x = 1;
    for (int i = 20; i < 30; i++) {
        deck[i].setTypeOfCard("Kupe");
        deck[i].setStrength(x);
        ++x;
    }

    x = 1;
    for (int i = 30; i < 40; i++) {
        deck[i].setTypeOfCard("Spade");
        deck[i].setStrength(x);
        ++x;
    }

    for (int i=0; i < 40; i++) {
        if (deck[i].getStrength() == 1) {
            deck[i].setNameOfCard("DUJA");
            deck[i].setPoints(0);
        } else if (deck[i].getStrength() == 2) {
            deck[i].setNameOfCard("CETVORKA");
            deck[i].setPoints(0);
        } else if (deck[i].getStrength() == 3) {
            deck[i].setNameOfCard("PETICA");
            deck[i].setPoints(0);
        } else if (deck[i].getStrength() == 4) {
            deck[i].setNameOfCard("SESTICA");
            deck[i].setPoints(0);
        } else if (deck[i].getStrength() == 5) {
            deck[i].setNameOfCard("SEDMICA");
            deck[i].setPoints(0);
        } else if (deck[i].getStrength() == 6) {
            deck[i].setNameOfCard("FANAT");
            deck[i].setPoints(2);
        } else if (deck[i].getStrength() == 7) {
            deck[i].setNameOfCard("KONJ");
            deck[i].setPoints(3);
        } else if (deck[i].getStrength() == 8) {
            deck[i].setNameOfCard("KRALJ");
            deck[i].setPoints(4);
        } else if (deck[i].getStrength() == 9) {
            deck[i].setNameOfCard("TRICA");
            deck[i].setPoints(10);
        } else if (deck[i].getStrength() == 10) {
            deck[i].setNameOfCard("AS");
            deck[i].setPoints(11);
        }
    }
}

void Deck::shuffleDeck() {

    srand(time(NULL));
    Card tmp;
    int x = 0;
    int y = 0;

    for (int i = 0; i < 80; i++) {
        x = rand() % 40;
        y = rand() % 40;
        tmp = deck[y];
        deck[y] = deck[x];
        deck[x] = tmp;
    }
}