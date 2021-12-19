#ifndef ANGRYBIRDSSFML_WORLDOBJ_H
#define ANGRYBIRDSSFML_WORLDOBJ_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "PhysicsObject.h"

using namespace  std;


class WorldObj : public PhysicsObject
{

 public:
  WorldObj();
  ~WorldObj();
  WorldObj(sf::Texture* texture, int pos_x, int pos_y, int weight, int *arr, int health, float smooth, float bounce, float break_ret, bool essential);
  void impactCall(float force_x, float force_y, float res_force, bool player);
  void calculateHealth(int res_force);

  void resetObj();


  bool destroyd = false;
  bool essential = false;
  float smoothness = 0;
  float bouncyness = 0;
  float break_retention= 0;

 private:

  int health = 0;
  int saved_pos_x;
  int saved_pos_y;
  int max_health = 0;
  int *arr_copy;

  sf::IntRect texture_rectangle;

};

#endif // ANGRYBIRDSSFML_WORLDOBJ_H
