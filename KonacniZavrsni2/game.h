#ifndef _GAME_H_
#define _GAME_H_
#include <vector>
#include "deck.h"
#include "player.h"

class Game {
    // one game, one deck
    Deck current;
    Player firstPlayer;
    Player secondPlayer;
    Card trump;
    Hand hand;
    int currentCards;
public:

    Game(const Player& playerOne, const Player playerTwo);
    Card getNextCard();

    Player* getFirstPlayer() {return &firstPlayer;}
    Player* getSecondPlayer() {return &secondPlayer;}

    Hand& getHand() {return hand;}

    void firstDeal();
    void pickUpCard(Player& playerOne, Player& playerTwo);

    Card getTrump() const {return trump;}
    vector<Card> getCardsFirstPlayer() const {return firstPlayer.getCardsOfPlayer();}
    vector<Card> getCardsSecondPlayer() const {return secondPlayer.getCardsOfPlayer();}

    Hand getHand() const {return hand;}

    void clearHand();

    bool isEmptyTable() const {return hand.table.getNameOfCard() == "";}
    bool isEmptyUpper() const {return hand.upper.getNameOfCard() == "";}
    bool isLastHand() const {return currentCards >= 38;}

    void swapWinLoosePlayers(Player** playerOne, Player** playerTwo);

    int calculateResultFirstPlayer() const;
};
#endif