#ifndef GAME_STATE_TEST_HPP
#define GAME_STATE_TEST_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

#include "GameState.hpp"
#include "Game.hpp"

class GameStateTest : public GameState
{
public:
  virtual void draw(const float dt);
  virtual void update(const float dt);
  virtual void handleInput();
  GameStateTest(Game* game);
};

#endif /* GAME_STATE_START_HPP */
