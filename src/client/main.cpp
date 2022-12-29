#include "config.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "GameStateStart.hpp"

using namespace std;

int main() 
{
  /*
  Game g;
  g.pushState(new GameStateStart(&g));
  g.gameLoop();

  */

  sf::RenderWindow window(sf::VideoMode(640, 480), "Game 1", sf::Style::Titlebar | sf::Style::Close);
  sf::Event ev;

  while (window.isOpen())
  {
    while (window.pollEvent(ev))
    {
      switch(ev.type)
      {
        case sf::Event::Closed:
          window.close();
          break;
      }
    }
  }


  return 0;
}
