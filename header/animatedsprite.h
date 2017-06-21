#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <map>
#include <string>
#include <vector>

#include "sprite.h"
#include "globals.h"

class Graphics;

/* AnimatedSprite class
 * Holds logic for animating sprites
 */

class AnimatedSprite : public Sprite
{
public:
  AnimatedSprite();
  AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX,
      int sourceY, int width, int height, float posX, float posY, float timeToUpdate);

  /* void playAnimation
   * We will store animation by name
   * bool once = false is the "optional parameter"
   * it means you can pass a second parameter (bool) or not, but it's default
   * is set to false (the animation defaults looping but you can set it to only
   * play one time)
   */
  void playAnimation(std::string animation, bool once = false);
  
  /* void update
   * Updates the animated sprite (timer)
   */
  void update(int elapsedTime);
  
  /* void draw
   * Draws the sprite to the screen
   */
  void draw(Graphics &graphics, int x, int y);

protected:
  double _timeToUpdate;
  bool _currentAnimationOnce;
  std::string _currentAnimation;

  /* void addAnimation
   * Adds an animation to the map of animations for the sprite
   */
  void addAnimation(int frames, int x, int y, std::string name, int width,
      int height, Vector2 offset);

  /* void resetAnimation
   * Resets all animations associated with this sprite
   */
  void resetAnimations();

  /* void stopAnimation
   * Stops the current animation
   */
  void stopAnimation();

  /* void setVisible
   * Changes the visibility of the animated sprite
   */
  void setVisible(bool visible);

  /* void animationDone
   * Logic that happens when an animation ends
   */
  virtual void animationDone(std::string currentAnimation) = 0;

  /* void setupAnimations
   * A required function that sets up all animations for a sprite
   */
  virtual void setupAnimations() = 0;

private:
  // map with a name of the animation and a vector of rectangles (the frames
  // in each of the animations)
  std::map<std::string, std::vector<SDL_Rect> > _animations;
  // What does this do???
  std::map<std::string, Vector2> _offsets;

  int _frameIndex;
  double _timeElapsed;
  bool _visible;
};



#endif
