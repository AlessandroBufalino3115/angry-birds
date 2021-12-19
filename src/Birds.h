//
// Created by alexh on 3/23/2021.
//

#ifndef ANGRYBIRDSSFML_BIRDS_H
#define ANGRYBIRDSSFML_BIRDS_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cmath>
#include "PhysicsObject.h"
using namespace std;

class Birds : public PhysicsObject
{
 public:
  Birds();
  ~Birds();
  Birds(std::string filename, float power, int type, int weight, int x, int y, float xcomp, float ycomp);

  void set(float Power);
  bool changeTexture();

  bool ability_used = false;
  bool destroy = false;

  sf::Clock clock;
  sf::Time second = sf::seconds(0.5);

  enum TypeOfBird
  {
    NORMAL,
    HEAVY,
    BOOMERANG
  };

  TypeOfBird TOB;

 private:
  float base_speed = 30;

};

#endif // ANGRYBIRDSSFML_BIRDS_H
