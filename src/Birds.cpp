//
// Created by alexh on 3/23/2021.
//

#include "Birds.h"

Birds::Birds() {}
Birds::~Birds() {cout << "deleted to spawn" << endl;
}

void Birds::set(float Power)  //called when the player release the bird to give it the "power" from the sling shot
{
  this->base_speed *= Power;

  x_comp = x_comp * Power;
  y_comp = y_comp * Power;

}


Birds::Birds(std::string filename, float power, int type, int Weight, int x, int y, float xcomp, float ycomp)
{
  sprite = new sf::Sprite();

  x_comp = xcomp;
  y_comp = ycomp;

  if (!texture.loadFromFile(filename)){}

  this->weight = Weight;

  this->set(power);

  switch (type)
  {
    case 1:
      TOB = NORMAL;
      break;

    case 2:
      TOB = HEAVY;
      break;

    case 3:
      TOB = BOOMERANG;
      break;

    default:
      TOB = NORMAL;
      break;
  }

  sprite->setTexture(texture);
  sprite->setPosition(x - sprite->getGlobalBounds().width/2, y - sprite->getGlobalBounds().height/2);
}


bool Birds::changeTexture()  //for when the bird needs to be destroyed  this is called to turn the texture to a different one
{
  if (!destroy)
  {
    clock.restart();
    destroy = true;

    if (!texture.loadFromFile("Data/Images/kenney_physicspack/PNG/Other/starGold.png")){}

    sprite->setTexture(texture, true);
    sprite->setPosition(sprite->getPosition().x , sprite->getPosition().y );

  }
  else
  {
    sf::Time elapsed1 = clock.getElapsedTime();
    if (elapsed1 > second)
    {
      return true;
    }
  }
  return false;
}
