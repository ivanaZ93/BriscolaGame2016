#include "presentation.h"

Presentation::~Presentation()
{
    al_destroy_sample(song);
    al_destroy_sample_instance(songInstance);
    al_destroy_display(display);
}

int Presentation::initAllegro()
{
    if (!al_init()) {
        al_show_native_message_box(NULL, "Error", NULL, "Could not Initialize Allegro", "", 0);
        return -1;
    }

    display = al_create_display(ScreenWidth, ScreenHeight);

    if (!display) {
        al_show_native_message_box(NULL, "Error", NULL, "Could not create Allegro Display", "", 0);
        return -2;
    }
    al_set_window_position(display, 150, 50);

    al_install_mouse();
    al_install_keyboard();
    al_install_audio();
    al_init_image_addon();
    al_init_acodec_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    song = al_load_sample("music/godfather.ogg");
    songInstance = al_create_sample_instance(song);

    al_reserve_samples(1);
    al_set_sample_instance_playmode(songInstance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());

    al_play_sample_instance(songInstance);
    return 0;
}

void Presentation::displayScreen() const
{
    al_flip_display();
}

void Presentation::pause(double sec) const
{
    al_rest(sec);
}

int Presentation::cleanScreen() const
{
    ALLEGRO_BITMAP *bg = al_load_bitmap("images/back.png");
    ALLEGRO_FONT *options = al_load_font("font.ttf", 12, 0);
    ALLEGRO_FONT *message = al_load_font("font.ttf", 18, 0);
    if (!bg || !message) {
       return -1;
    }
    al_draw_bitmap(bg, 0,0, 0);
    al_draw_text(message, al_map_rgb(0,0,0), 760, 10, ALLEGRO_ALIGN_CENTRE, "RESET");
    al_draw_text(message, al_map_rgb(0,0,0), 400, 580, ALLEGRO_ALIGN_CENTRE, "BRISKULA by IVANA ZAPER");
    al_destroy_bitmap(bg);
    return 0;
}

void Presentation::updateScreen(const Game& game) const
{
    if (cleanScreen() == -1) {
        return;
    }
    presentationCardsSecondPlayer(game);
    presentationCardsFirstPlayer(game);

    if (!game.isLastHand()) {
        presentationDeckTrump(game);
    }

    if (!game.isEmptyTable()) {
        presentationCardsTable(game);
        if (!game.isEmptyUpper()) {
            presentationCardsUp(game);
        }
    }
    displayScreen();
}

void Presentation::presentationCardsTable(const Game& game) const
{
    int x = 350;
    int y = 200;

    ALLEGRO_BITMAP *imageUpTable;

    Hand hand = game.getHand();
    string fullName = hand.table.createFullName();

    imageUpTable = al_load_bitmap(fullName.c_str());

    al_draw_bitmap(imageUpTable, x, y, 0);
    al_destroy_bitmap(imageUpTable);
}

void Presentation::presentationCardsUp(const Game& game) const
{
    int x = 390;
    int y  = 220;
    ALLEGRO_BITMAP *imageUp;
    Hand hand = game.getHand();
    string fullName = hand.upper.createFullName();

    imageUp = al_load_bitmap(fullName.c_str());

    al_draw_bitmap(imageUp, x, y, 0);
    al_destroy_bitmap(imageUp);
}

void Presentation::presentationCardsFirstPlayer(const Game& game) const
{
    int x = 30;
    int y = 400;
    ALLEGRO_BITMAP *playerImages;
    vector<Card> Cards = game.getCardsFirstPlayer();
    for (vector <Card>::const_iterator itr = Cards.begin(); itr != Cards.end(); ++itr) {
        string fullName = itr->createFullName();
        playerImages = al_load_bitmap(fullName.c_str());
        al_draw_bitmap(playerImages, x, y, 0);
        x = x + 80;
    }
}

void Presentation::presentationCardsSecondPlayer(const Game& game) const
{
    int x = 30;
    int y = 30;
    ALLEGRO_BITMAP *images;
    vector<Card> Cards = game.getCardsSecondPlayer();
    for (vector <Card>::const_iterator itr = Cards.begin(); itr != Cards.end(); ++itr) {
        images = al_load_bitmap("cards/cover.png");
        al_convert_mask_to_alpha(images, al_map_rgb(163,73,164));
        al_draw_bitmap(images, x, y, 0);
        x = x + 80;
    }
}

void Presentation::presentationDeckTrump(const Game& game) const
{
    ALLEGRO_BITMAP *image;

    Card trump = game.getTrump();
    string fullName = trump.createFullName();

    image = al_load_bitmap(fullName.c_str());

    al_draw_rotated_bitmap(image, 0, 0, 700, 250, 1.57, 0);

    ALLEGRO_BITMAP *cover;
    cover = al_load_bitmap("cards/cover.png");
    al_convert_mask_to_alpha(cover, al_map_rgb(163,73,164));
    al_draw_bitmap(cover, 620, 220, 0);
    al_draw_bitmap(cover, 620, 221, 0);
    al_draw_bitmap(cover, 620, 221, 0);
    al_draw_bitmap(cover, 620, 223, 0);
    al_destroy_bitmap(image);
    al_destroy_bitmap(cover);

}

void Presentation::displayResults(Game& game) const
{
    ALLEGRO_FONT *message = al_load_font("font.ttf", 45, 0);

    int resultOfFirstPlayer = game.calculateResultFirstPlayer();
    int resultOfSecondPlayer = 120 - resultOfFirstPlayer;
    al_draw_text(message, al_map_rgb(250,0,0), 400, 200, ALLEGRO_ALIGN_CENTRE, "Your points:");
    string resultOfFirstPlayerString = to_string(resultOfFirstPlayer);
    al_draw_text(message, al_map_rgb(250,0,0), 650, 200, ALLEGRO_ALIGN_CENTRE, resultOfFirstPlayerString.c_str());

    al_draw_text(message, al_map_rgb(250,0,0), 400, 250, ALLEGRO_ALIGN_CENTRE, "Computer points:");
    string resultOfSecondPlayerString = to_string(resultOfSecondPlayer);
    al_draw_text(message, al_map_rgb(250,0,0), 650, 250, ALLEGRO_ALIGN_CENTRE, resultOfSecondPlayerString.c_str());

    if (resultOfFirstPlayer > resultOfSecondPlayer) {
        al_draw_text(message, al_map_rgb(250,0,0), 400, 300, ALLEGRO_ALIGN_CENTRE, "YOU WIN!");
    } else if (resultOfSecondPlayer > resultOfFirstPlayer) {
        al_draw_text(message, al_map_rgb(250,0,0), 400, 300, ALLEGRO_ALIGN_CENTRE, "YOU LOSE!");
    } else {
        al_draw_text(message, al_map_rgb(250,0,0), 400, 300, ALLEGRO_ALIGN_CENTRE, "TIE!");
    }
}

int Presentation::oneMore()
{
    return al_show_native_message_box(display, "Briscula by Ivana Zaper", "Do you want to play another one?", NULL, NULL, 8);
}