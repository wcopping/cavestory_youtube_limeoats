/* Input class
 * Keeps track of keyboard state
 */


#include "input.h"

// Called at beginning of each new frame to reset the keys that are no longer
// relevant
void Input::beginNewFrame()
{
  // It doesn't matter what was in the last frame so we can reset pressed and
  // released keys
  this->_pressedKeys.clear();
  this->_releasedKeys.clear();
}

// Is called when a key is pressed
void Input::keyDownEvent(const SDL_Event& event)
{
  this->_pressedKeys[event.key.keysym.scancode] = true;
  this->_heldKeys[event.key.keysym.scancode] = true;
}

// Is called when a key is released
void Input::keyUpEvent(const SDL_Event& event)
{
  this->_releasedKeys[event.key.keysym.scancode] = true;
  this->_heldKeys[event.key.keysym.scancode] = false;
}

// Checks if a certain key was pressed during the current frame
bool Input::wasKeyPressed(SDL_Scancode key)
{
  return this->_pressedKeys[key];
}

// Checks if a certain key was released during the current frame
bool Input::wasKeyReleased(SDL_Scancode key)
{
  return this->_releasedKeys[key];
}

// Checks if a certain key is currently being held
bool Input::isKeyHeld(SDL_Scancode key)
{
  return this->_heldKeys[key];
}
