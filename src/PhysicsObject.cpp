//
// Created by alexh on 4/6/2021.
//

#include "PhysicsObject.h"
sf::Sprite* PhysicsObject::getSprite()
{
  return this->sprite;
}

void PhysicsObject::movement(float dt)
{
  this->dt = dt;

  y_comp += 9.81f * dt * this->weight;   //continues pull down from "garvity"

  this->getSprite()->move(x_comp * dt * 10, y_comp * dt * 10 );
}

float PhysicsObject::CalculateForce()   //called to get the resultant force
{
  float force_x = weight * x_comp *dt;
  float force_y = weight * y_comp *dt;

  float res_force = hypot(force_x,force_y);

  return res_force;
}
