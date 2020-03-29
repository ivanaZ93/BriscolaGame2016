#include "event.h"

Card Event::selectCardToPlay(const vector<Card>& cardsInHand, bool& reset)
{
    Card i;

    bool pressed = false;
    int x1 = 30;
    int x2 = 110;
    int y1 = 400;
    int y2 = 544;

    vector<Card>::const_iterator itr = cardsInHand.begin();
    ALLEGRO_EVENT_QUEUE *eventQueue = al_create_event_queue();
    al_register_event_source(eventQueue, al_get_mouse_event_source());

    do {
        ALLEGRO_EVENT eventQueues;
        al_wait_for_event(eventQueue, &eventQueues);
        int x = eventQueues.mouse.x;
        int y = eventQueues.mouse.y;
        if (eventQueues.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                if (eventQueues.mouse.button &1) {
                    if (x > x1 && x < x2 && y > y1 && y < y2) {
                        i = *itr;
                        pressed = true;
                    } else if (x > (x1 + 80) && x < (x2 + 80) && y > y1 && y < y2 && cardsInHand.size() > 1) {
                        ++itr;
                        i = *itr;
                        pressed = true;
                    } else if (x > (x1 + 160) && x < (x2 + 160) && y > y1 && y < y2 && cardsInHand.size() > 2) {
                        itr += 2;
                        i = *itr;
                        pressed = true;
                    } else if (x > 740 && x < 780 && y > 10 && y < 30) {
                        reset = true;
                        pressed = true;
                    }
                }
        }
    } while (!pressed);

    return i;
}