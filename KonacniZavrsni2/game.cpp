#include "game.h"

Game::Game(const Player& first, const Player second): firstPlayer(first), secondPlayer(second), currentCards(-1)
{
    trump = current[39];
}

Card Game::getNextCard()
{
    return current[++currentCards];
}

void Game::clearHand()
{
    hand.clear();
}

void Game::swapWinLoosePlayers(Player** playerOne, Player** playerTwo)
{
    Player* tmpPlayer;
    tmpPlayer = *playerOne;
    *playerOne = *playerTwo;
    *playerTwo = tmpPlayer;
}

void Game::firstDeal()
{
    for (int i = 0; i < 3; i++) {
        firstPlayer.addPickedUpCard(getNextCard());
        secondPlayer.addPickedUpCard(getNextCard());
    }
}

void Game::pickUpCard(Player& first, Player& second)
{
    if (first.numberOfCardsInHand() == 2 && second.numberOfCardsInHand() == 2 && currentCards < 39) {
        first.addPickedUpCard(getNextCard());
        second.addPickedUpCard(getNextCard());
    }
}

int Game::calculateResultFirstPlayer() const
{
    return firstPlayer.calculateResult();
}