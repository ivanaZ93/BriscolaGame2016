#ifndef _CARD_H_
#define _CARD_H_
#include <string>
#include <iostream>

using namespace std;

class Card
{

    string typeOfCard;
    string nameOfCard;
    int points;
    int strength;
    bool isTrump;

public:

    Card();
    ~Card();
    Card(string type, string name, int point, int strength);

    bool operator==(const Card& other);
    bool operator>(const Card& other);
    bool operator<(const Card& other);

    bool isItTrump() const;
    void setTrump(bool isTrump);

    void setTypeOfCard(string type);
    void setNameOfCard(string name);
    void setPoints(int point);
    void setStrength(int strength);

    string getTypeOfCard() const;
    string getNameOfCard() const;
    int getPoints() const;
    int getStrength() const;

    string createFullName() const;

    friend ostream& operator<<(ostream& os, const Card& card) {
        return os << card.getTypeOfCard() << ", " << card.getNameOfCard() << ", trump " <<  std::boolalpha << card.isItTrump() <<  endl;
    }
};

#endif