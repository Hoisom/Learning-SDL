#include "Game.hpp"

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

void Game::update()
{}

void Game::render()
{
    SDL_RenderClear(renderer);
    // Add stuff to render
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned\n";
}
