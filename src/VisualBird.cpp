//
// Created by alexh on 3/28/2021.
//

#include "VisualBird.h"
VisualBird::~VisualBird() {}

VisualBird::VisualBird(std::string filename, int type)
{
  sprite = new sf::Sprite();

  if (!texture.loadFromFile(filename)){}

  sprite->setTexture(texture);

  switch (type)
  {
    case 1:
      TOB = NORMAL;
      break;


    case 2:
      TOB  = HEAVY;
      break;


    case 3:
      TOB = TRACER;
      break;


    case 4:
      TOB =   BOOMERANG;

    default:
      break;

  }
}

sf::Sprite* VisualBird::getSprite()
{
  return sprite;
}
