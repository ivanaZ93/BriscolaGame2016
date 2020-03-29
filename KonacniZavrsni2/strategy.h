#ifndef _STRATEGY_H_
#define _STRATEGY_H_
#include <vector>
#include "card.h"

using namespace std;

class Strategy
{
public:
    static Card computerPlaysFirst(const vector<Card>& Cards, const Card& trump, const Card& table);
    static Card computerPlaysSecond(const vector<Card>& Cards, const Card& trump, const Card& table);
};
#endif