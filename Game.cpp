#include "Game.hpp"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

Game::Game()
{}
Game::~Game()
{}


void Game::init(const char* title, int x_pos, int y_pos, int width, int height, int fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "Failed to Initialise Subsystems...\n";
        is_running = false;
        return;
    }

    IMG_Init(IMG_INIT_PNG);

    window = SDL_CreateWindow(title, x_pos, y_pos, width, height, flags);
    if (window == NULL)
    {
        std::cout << "Window not created...\n";
        is_running = false;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL)
    {
        std::cout << "Renderer not created...\n";
        is_running = false;
        return;
    }
    image = IMG_Load("image.png");
    texture = SDL_CreateTextureFromSurface(renderer, image);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    is_running = true;

}

void Game::handle_events()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) 
    {
        case SDL_QUIT:
            is_running = false;
            break;

        default:
            break;
    }
}

void Game::update(int screen_width, int screen_height)
{
    // Set colour to white
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // Fill screen with white
    SDL_RenderClear(renderer);

    SDL_Rect rect = {screen_width/4, screen_height/4, screen_width/2, screen_height/2};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);

    // Render image
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Game::render()
{
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned\n";
}
