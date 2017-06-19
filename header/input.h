#ifndef INPUT_H
#define INPUT_H

#include "SDL.h"
#include <map>

class Input
{
public:
private:
  std::map<SDL_Scancode, bool> _heldKeys;
};


#endif
