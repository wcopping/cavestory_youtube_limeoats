#include "SDL.h"
#include "game.h"
#include "graphics.h"
#include "input.h"


/* Game class
 * Holds all the information for the main game loop
 */

namespace {
  const int FPS = 50;
  const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}


Game::Game()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  this->gameLoop();
}

Game::~Game()
{
  ;
}

void Game::gameLoop()
{
  Graphics graphics;
  Input input;
  SDL_Event event;

  this->_player = Sprite(graphics, "/home/wyatt/Projects/cavestory_youtube_limeoats/content/sprites/MyChar.png", 0, 0, 16, 16, 100, 100);

  int LAST_UPDATE_TIME = SDL_GetTicks();
  // Start the game loop
  while (true) {
    input.beginNewFrame();
    if (SDL_PollEvent(&event)) {
      if (event.type == SDL_KEYDOWN) {
        if (event.key.repeat == 0) {
          input.keyDownEvent(event);
        }
      } else if (event.type == SDL_KEYUP) {
        input.keyUpEvent(event);
      } else if (event.type == SDL_QUIT) {
        return;
      }
    }
    if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
      return;
    }


    // The time after all input checked for
    const int CURRENT_TIME_MS = SDL_GetTicks();
    // The time it took to go through the current frame?
    int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
    this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
    LAST_UPDATE_TIME = CURRENT_TIME_MS;

    this->draw(graphics);
  }
}

void Game::draw(Graphics &graphics)
{
  graphics.clear();

  this->_player.draw(graphics, 100, 100);

  graphics.flip();
}

void Game::update(float elapsedTime)
{
  ;
}
