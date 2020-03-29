#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include <vector>
#include <algorithm>
#include "card.h"
#include "hand.h"
#include "strategy.h"
#include "event.h"


using namespace std;

class Player
{
    string name;
    bool playerTypeComp;
    int points;

    vector<Card> cardsOfPlayer;
    vector<Card> wonCardsOfPlayer;

public:

    Player(string& str);
    string getName() const;
    bool isPlayerComp() const;
    bool handsEmpty() const;

    Card game(bool first, Card& trump, Card& table, bool& reset);
    void addPickedUpCard(const Card& card);
    void addCardsToHand(const Hand& hand);

    int numberOfCardsInHand() {return cardsOfPlayer.size();}

    const vector<Card>& getCardsOfPlayer() const {return cardsOfPlayer;}


    void eraseCard(const Card& card);
    int calculateResult() const;
    friend ostream& operator<<(ostream& os, const Player& player)
    {
        return os << player.getName() << " " << player.calculateResult() << endl;
    }
};
#endif