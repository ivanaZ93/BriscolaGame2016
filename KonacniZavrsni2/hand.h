#ifndef _HAND_H_
#define _HAND_H_
#include "card.h"

struct Hand {
    Card table, upper;
    Card trump;
    void clear();
};
#endif