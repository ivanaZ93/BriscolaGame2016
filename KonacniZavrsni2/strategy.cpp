#include "strategy.h"

Card Strategy::computerPlaysFirst(const vector<Card>& Cards, const Card& trump, const Card& table) {
    Card throwCard;

    vector<Card>::const_iterator t = Cards.begin();
    int m = 20;
    int j = 0;
    for (vector<Card>::const_iterator itr = Cards.begin(); itr != Cards.end(); ++itr) {
        if (itr->getTypeOfCard() != trump.getTypeOfCard() && itr->getPoints() == 0) {
            throwCard = *itr;
            return throwCard;
        }
    }
    for (vector<Card>::const_iterator itr = Cards.begin(); itr != Cards.end(); ++itr) {
        if (itr->getTypeOfCard() == trump.getTypeOfCard() && itr->getPoints() == 0) {
            throwCard = *itr;
            return throwCard;
        }
    }
    for (vector<Card>::const_iterator itr = Cards.begin(); itr != Cards.end(); ++itr) {
        if (itr->getTypeOfCard() == trump.getTypeOfCard()) {
            j = itr->getStrength() + 10;
        } else {
            j = itr->getStrength();
        }
        if (j <= m) {
            m = j;
            throwCard = *itr;
            t = itr;
        }
    }
    return throwCard;
}

Card Strategy::computerPlaysSecond(const vector<Card>& Cards, const Card& trump, const Card& table)
{
    Card throwCard;
    vector<Card>::const_iterator t = Cards.begin();
    int strength = table.getStrength();
    int currentStrength = 11;
    int currentMove = 0;

    if (table.getTypeOfCard() != trump.getTypeOfCard()) {
        for (vector<Card>::const_iterator itr = Cards.begin(); itr != Cards.end(); ++itr) {
            if (table.getTypeOfCard() == itr->getTypeOfCard() && itr->getStrength() > strength) {
                strength = itr->getStrength();
                currentMove = 4;
                t = itr;
                throwCard = *itr;
            } else if (table.getPoints() != 0 && itr->getTypeOfCard() == trump.getTypeOfCard() && itr->getStrength() < currentStrength && currentMove < 4) {
                currentStrength = itr->getStrength();
                currentMove = 3;
                t = itr;
                throwCard = *itr;
            } else if (table.getPoints() == 0 && itr->getPoints() == 0 && itr->getStrength() < currentStrength && currentMove < 3) {
                currentStrength = itr->getStrength();
                currentMove = 2;
                t = itr;
                throwCard = *itr;
            } else if (itr->getStrength() < currentStrength && currentMove == 0) {
                currentStrength = itr->getStrength();
                t = itr;
                throwCard = *itr;
            }
        }
    }


    if (table.getTypeOfCard() == trump.getTypeOfCard()) {
        for (vector<Card>::const_iterator itr = Cards.begin(); itr != Cards.end(); ++itr) {
            if (itr->getPoints() == 0 && itr->getTypeOfCard() != trump.getTypeOfCard()) {
                currentMove = 4;
                t = itr;
                throwCard = *itr;
            } else if (itr->getPoints() == 0 && itr->getTypeOfCard() == trump.getTypeOfCard() && itr->getStrength() < currentStrength && currentMove < 4) {
                currentMove = 3;
                currentStrength = itr->getStrength();
                t = itr;
                throwCard = *itr;
            } else if (itr->getTypeOfCard() != trump.getTypeOfCard() && itr->getStrength() < currentStrength && currentMove < 3) {
                currentMove = 2;
                currentStrength = itr->getStrength();
                t = itr;
                throwCard = *itr;
            } else if (itr->getStrength() < currentStrength && currentMove == 0) {
                currentStrength = itr->getStrength() ;
                t = itr;
                throwCard = *itr;
            }
        }
    }
    return throwCard;
}
