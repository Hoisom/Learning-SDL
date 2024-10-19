#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Game
{
public:
    Game();
    ~Game();

    void init(const char* title, int x_pos, int y_pos, int width, int height, int fullscreen);

    void handle_events();
    void update(int screen_width, int screen_height);
    void render();
    void clean();

    bool running() {return is_running;}

private:
    bool is_running;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *image;
    SDL_Texture *texture;
    
};

#endif // !Game_hpp
