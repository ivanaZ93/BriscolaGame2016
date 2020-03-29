#include "player.h"

Player::Player(string& name)
{
    this->name = name;
    playerTypeComp = name == "computer" ? true : false;
}

string Player::getName() const
{
    return name;
}

bool Player::isPlayerComp() const
{
    return playerTypeComp;
}

Card Player::game(bool first, Card& trump, Card& table, bool& reset)
{
    Card selectedCard;
    if (isPlayerComp()) {
        if (first) {
            selectedCard = Strategy::computerPlaysFirst(cardsOfPlayer, trump, table);
        } else {
            selectedCard = Strategy::computerPlaysSecond(cardsOfPlayer, trump, table);
        }
    } else {
        if (first) {
            selectedCard = Event::selectCardToPlay(this->cardsOfPlayer, reset);
        } else {
            selectedCard = Event::selectCardToPlay(this->cardsOfPlayer, reset);
        }
    }

    if (selectedCard.getTypeOfCard() == trump.getTypeOfCard()) {
        selectedCard.setTrump(true);
    } else {
        selectedCard.setTrump(false);
    }
    eraseCard(selectedCard);

    return selectedCard;
}

bool Player::handsEmpty() const
{
    return cardsOfPlayer.empty();
}

void Player::eraseCard(const Card& card)
{
    cardsOfPlayer.erase(std::remove(cardsOfPlayer.begin(), cardsOfPlayer.end(), card), cardsOfPlayer.end());
}

void Player::addPickedUpCard(const Card& card)
{
    cardsOfPlayer.push_back(card);
}

void Player::addCardsToHand(const Hand& hand)
{
    wonCardsOfPlayer.push_back(hand.table);
    wonCardsOfPlayer.push_back(hand.upper);
}

int Player::calculateResult() const
{
    int result = 0;
    for (vector<Card>::const_iterator itr = wonCardsOfPlayer.begin(); itr != wonCardsOfPlayer.end(); ++itr) {
        result += itr->getPoints();
    }
    return result;
}