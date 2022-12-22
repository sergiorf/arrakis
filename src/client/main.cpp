#include "config.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "GameStateStart.hpp"

using namespace std;

int main() 
{
  Game g;
  g.pushState(new GameStateStart(&g));
  g.gameLoop();

  return 0;
}
