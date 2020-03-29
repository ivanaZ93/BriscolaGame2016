#include "card.h"

Card::Card(string type, string name, int point, int strengthNumber) {
    typeOfCard = type;
    nameOfCard = name;
    points = point;
    strength = strengthNumber;
    isTrump = false;
}

Card::Card(): typeOfCard(""), nameOfCard(""), points(0), strength(0) {
}

Card::~Card() {
}

void Card::setTypeOfCard(string type) {
    typeOfCard = type;
}

void Card::setNameOfCard(string name) {
    nameOfCard = name;
}

void Card::setPoints(int point) {
    points = point;
}

void Card::setStrength(int strengthNumber) {
    strength = strengthNumber;
}

string Card::getTypeOfCard() const
{
    return typeOfCard;
}

string Card::getNameOfCard() const
{
    return nameOfCard;
}

int Card::getPoints() const
{
    return points;
}

int Card::getStrength() const
{
    return strength;
}

bool Card::operator==(const Card& other)
{
    return (typeOfCard == other.typeOfCard && nameOfCard == other.nameOfCard);
}

bool Card::isItTrump() const
{
    return isTrump;
}

void Card::setTrump(bool isTrump)
{
    this->isTrump = isTrump;
}

bool Card::operator>(const Card& other)
{
    return (
        ((getStrength() > other.getStrength()) && (getTypeOfCard() == other.getTypeOfCard()))
        || (isItTrump() && !other.isItTrump())
        || ((isItTrump() && other.isItTrump()) && (getStrength() > other.getStrength()))
        || ((!isItTrump() && !other.isItTrump()) && (getTypeOfCard() != other.getTypeOfCard()))
    );
}

bool Card::operator<(const Card& other)
{
    return !(*this > other);
}

string Card::createFullName() const
{
    string tmpNameOfCard = getNameOfCard();
    string tmpTypeOfCard = getTypeOfCard();
    string fullName = "cards/" + tmpNameOfCard + "_" + tmpTypeOfCard + ".png";
    if (tmpNameOfCard == "" || tmpTypeOfCard == "") {
        return "";
    }
    return fullName;
}