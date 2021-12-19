#include "WorldObj.h"
WorldObj::~WorldObj() {}

WorldObj::WorldObj(sf::Texture* texture, int pos_x, int pos_y, int weight, int *arr, int health, float smooth, float bounce, float break_ret, bool essential)
{
  sprite = new sf::Sprite();
  this->weight = weight;
  this->arr_copy = arr;
  this->health = health;
  this->saved_pos_x = pos_x;
  this->saved_pos_y = pos_y;
  this->max_health = health;
  this->smoothness = smooth;
  this->bouncyness = bounce;
  this->break_retention = break_ret;
  this->essential = essential;

  sprite->setTexture(*texture); //this turn it bak into a value which is usable
  calculateHealth(0);
  sprite->setPosition(pos_x - sprite->getGlobalBounds().width/2, pos_y - sprite->getGlobalBounds().height/2);
}

void WorldObj::impactCall(float force_x, float force_y, float res_force, bool player) //on impact call
{
  this->y_comp += force_y;
  this->x_comp += force_x;

    if (player)
    {
      if (res_force < 3 && res_force >-3){}
      else
        this->calculateHealth(round(res_force));
    }
    else
    {
      if (force_y < 5 && force_y >-5){}
      else
        this->calculateHealth(round(res_force));
    }
}

void WorldObj::calculateHealth(int res_force)  //change the texture depending on the percentage of the health remaining
{
  this->health -= res_force;

  if (this->health <= 0)
    this->destroyd = true;

  if (this->health == max_health)
  {
    texture_rectangle.left = *(arr_copy);
    texture_rectangle.top = *(arr_copy + 1);
    texture_rectangle.width = *(arr_copy + 2);
    texture_rectangle.height = *(arr_copy + 3);
  }
  else if (this->max_health*0.7 > this->health)
  {
    texture_rectangle.left = *(arr_copy+4);
    texture_rectangle.top = *(arr_copy + 5);
    texture_rectangle.width = *(arr_copy + 6);
    texture_rectangle.height = *(arr_copy + 7);
  }
  if (this->max_health*0.4 > this->health)
  {
    texture_rectangle.left = *(arr_copy+8);
    texture_rectangle.top = *(arr_copy + 9);
    texture_rectangle.width = *(arr_copy + 10);
    texture_rectangle.height = *(arr_copy + 11);
  }

  sprite->setTextureRect(texture_rectangle);

}

void WorldObj::resetObj()   //reset the object ready to be used again
{
  this->sprite->setPosition(this->saved_pos_x, this->saved_pos_y);
  x_comp = 0;
  y_comp = 0;
  this->health = this->max_health;
  this->destroyd = false;
  this->calculateHealth(0);
}
