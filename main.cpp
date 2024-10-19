#include "Game.hpp"

#define SCREEN_WIDTH 640 
#define SCREEN_HEIGHT 480


Game *game = nullptr;

int main (int argc, char *argv[]) {

    game = new Game();

    game->init("Game",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            false);

    while (game->running())
    {
        game->handle_events();
        game->update(SCREEN_WIDTH, SCREEN_HEIGHT);
        game->render();
    }

    game->clean();

    return 0;
}
