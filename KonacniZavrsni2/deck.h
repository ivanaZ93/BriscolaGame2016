#ifndef _DECK_H_
#define _DECK_H_
#include <string.h>
#include "card.h"

using namespace std;

class Deck{

    Card deck[40];

public:

    Deck();
    ~Deck();

    Card& operator[](int x);

    void inDeck();
    void shuffleDeck();

};
#endif