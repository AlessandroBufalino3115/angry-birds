//
// Created by alexh on 3/28/2021.
//

#ifndef ANGRYBIRDSSFML_VISUALBIRD_H
#define ANGRYBIRDSSFML_VISUALBIRD_H
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class VisualBird
{
 public:
  VisualBird();
  ~VisualBird();

  VisualBird(std::string filename, int type);

  sf::Sprite* getSprite();

  sf::Sprite *sprite;
  sf::Texture texture;

  enum TypeOfBird
  {
    NORMAL,
    HEAVY,
    TRACER,
    BOOMERANG
  };

  TypeOfBird TOB;

};

#endif // ANGRYBIRDSSFML_VISUALBIRD_H
