#ifndef _EVENT_H_
#define _EVENT_H_
#include "card.h"
#include <vector>
#include <allegro5/allegro5.h>

class Event
{
public:
    static Card selectCardToPlay(const vector<Card>& cardsInHand, bool &reset);
};
#endif