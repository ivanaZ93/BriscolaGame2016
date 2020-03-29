#include <iostream>
#include "presentation.h"
#include "game.h"

using namespace std;

int main() {
    beginning:
    string nameOfFirst("you"), nameOfSecond("computer");
    Player playerOne(nameOfFirst), playerTwo(nameOfSecond);
    Game game(playerOne, playerTwo);
    Hand& hand = game.getHand();

    // playerWinner is the first player - during the game playerWinner is changing
    Player* playerWinner = game.getFirstPlayer();
    Player* playerLooser = game.getSecondPlayer();

    Presentation presentation;
    bool reset = false;
    if (presentation.initAllegro() < 0) {
        return -1;
    }

    if (presentation.cleanScreen() == -1) {
        return -1;
    }
    presentation.displayScreen();
    presentation.pause(1.0);

    game.firstDeal();
    int cnt = 0;
    presentation.updateScreen(game);

    Card trump = game.getTrump();
    while (1) {
        if (reset) {
            goto beginning;
        }
        hand.clear();
        hand.table = playerWinner->game(true, trump, hand.table, reset);
        if (reset) {
            goto beginning;
        }
        cout << ++cnt << " first: " << playerWinner->getName() << endl;
        cout << hand.table << endl;
        presentation.updateScreen(game);

        hand.upper = playerLooser->game(false, trump, hand.table, reset);
        if (reset) {
            goto beginning;
        }
        presentation.updateScreen(game);
        cout << ++cnt << " second: " << playerLooser->getName() << endl;
        cout << hand.upper << endl;
        if (hand.table < hand.upper) {
            game.swapWinLoosePlayers(&playerWinner, &playerLooser);
        }

        playerWinner->addCardsToHand(hand);

        presentation.updateScreen(game);
        presentation.pause(1.0);

        hand.clear();
        presentation.updateScreen(game);

        if (playerWinner->handsEmpty() && playerLooser->handsEmpty()) {
            break;
        }

        game.pickUpCard(*playerWinner, *playerLooser);
        presentation.updateScreen(game);
    }
    presentation.cleanScreen();

    presentation.displayResults(game);
    presentation.displayScreen();
    presentation.pause(3.0);

    if (presentation.oneMore() == 1) {
        goto beginning;
    }
}