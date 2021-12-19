//
// Created by alexh on 4/6/2021.
//

#ifndef ANGRYBIRDSSFML_PHYSICSOBJECT_H
#define ANGRYBIRDSSFML_PHYSICSOBJECT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class PhysicsObject
{
 public:
  sf::Sprite* getSprite();
  void movement(float dt);
  float CalculateForce();

  float x_comp;
  float y_comp;

  float dt;

  sf::Sprite *sprite;
  sf::Texture texture;
  int weight;

};

#endif // ANGRYBIRDSSFML_PHYSICSOBJECT_H
