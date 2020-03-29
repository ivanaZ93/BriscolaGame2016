#ifndef _PRESENTATION_H_
#define _PRESENTATION_H_

#include "game.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

#define ScreenWidth 800
#define ScreenHeight 600

class Presentation{
    ALLEGRO_DISPLAY *display;
    ALLEGRO_SAMPLE *song;
    ALLEGRO_SAMPLE_INSTANCE *songInstance;

public:
    ~Presentation();

    int initAllegro();

    void displayScreen() const;
    void pause(double sec) const;

    int cleanScreen() const;
    void updateScreen(const Game& game) const;

    void presentationCardsTable(const Game& game) const;
    void presentationCardsUp(const Game& game) const;
    void presentationCardsFirstPlayer(const Game& game) const;
    void presentationCardsSecondPlayer(const Game& game) const;
    void presentationDeckTrump(const Game& game) const;
    int oneMore();

    void displayResults(Game& game) const;
};
#endif