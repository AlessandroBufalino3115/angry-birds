#include "Game.h"

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}
Game::~Game(){}

bool Game::init()
{
  if (!font.loadFromFile("Data/Fonts/open-sans/OpenSans-BoldItalic.ttf")){}

  //----------------------set up of screens------------------------
                      //main menu screen
  if (!mainMenu_background_texture.loadFromFile("Data/Images/menu.jpg")){}

  mainMenu_background_sprite.setTexture(mainMenu_background_texture);
  mainMenu_background_sprite.setPosition(0,0);
  mainMenu_background_sprite.setScale(0.85f,0.9f);

  start_game_menuText.setString(" Start the Game here!!! ");
  start_game_menuText.setFillColor(sf::Color(255,255,255,255));
  start_game_menuText.setFont(font);
  start_game_menuText.setCharacterSize(30);
  start_game_menuText.setPosition(window.getSize().x/2 - (start_game_menuText.getGlobalBounds().width/2) + 20, 150);

  choose_level_menuText.setString(" Select Level here ");
  choose_level_menuText.setFillColor(sf::Color(255,255,255,255));
  choose_level_menuText.setFont(font);
  choose_level_menuText.setCharacterSize(30);
  choose_level_menuText.setPosition(window.getSize().x/1.5 + (choose_level_menuText.getGlobalBounds().width/2) + 15, 800);


  info_menuText.setString(" Info and controls ");
  info_menuText.setFillColor(sf::Color(255,255,255,255));
  info_menuText.setFont(font);
  info_menuText.setCharacterSize(30);
  info_menuText.setPosition(window.getSize().x/4 - (info_menuText.getGlobalBounds().width/2) + 15 , 800);


  //-----------------------------------------------------
                      //level select screen

  back_text_levelsel.setString(" Return to the main menu ");
  back_text_levelsel.setFillColor(sf::Color(255,255,255,255));
  back_text_levelsel.setFont(font);
  back_text_levelsel.setCharacterSize(30);
  back_text_levelsel.setPosition(window.getSize().x/2 - (back_text_levelsel.getGlobalBounds().width/2) + 15, window.getSize().y - back_text_levelsel.getGlobalBounds().height * 3);

  LV1_levelsel.setString(" Play level 1 ");
  LV1_levelsel.setFillColor(sf::Color(255,255,255,255));
  LV1_levelsel.setFont(font);
  LV1_levelsel.setCharacterSize(30);
  LV1_levelsel.setPosition(window.getSize().x/4 - (LV1_levelsel.getGlobalBounds().width/2) + 15 , 150);

  LV2_levelsel.setString(" Play level 2 ");
  LV2_levelsel.setFillColor(sf::Color(255,255,255,255));
  LV2_levelsel.setFont(font);
  LV2_levelsel.setCharacterSize(30);
  LV2_levelsel.setPosition(window.getSize().x/2 - (LV2_levelsel.getGlobalBounds().width/2) + 15, 150);

  LV3_levelsel.setString(" Play level 3 ");
  LV3_levelsel.setFillColor(sf::Color(255,255,255,255));
  LV3_levelsel.setFont(font);
  LV3_levelsel.setCharacterSize(30);
  LV3_levelsel.setPosition(window.getSize().x/1.5 + (LV3_levelsel.getGlobalBounds().width/2) + 15, 150);


  //-------------------------------------------------------
                      // Game screen
  if (!game_screen_LV1_background_texture.loadFromFile("Data/Images/lvl1.png")){}

  game_screen_LV1_background_sprite.setTexture(game_screen_LV1_background_texture);
  game_screen_LV1_background_texture.setRepeated(true);
  game_screen_LV1_background_sprite.setTextureRect(sf::IntRect(0,0,10000,1440));

  if (!game_screen_LV2_background_texture.loadFromFile("Data/Images/lvl2.png")){}

  game_screen_LV2_background_sprite.setTexture(game_screen_LV2_background_texture);
  game_screen_LV2_background_texture.setRepeated(true);
  game_screen_LV2_background_sprite.setTextureRect(sf::IntRect(0,0,10000,1440));

  if (!game_screen_LV3_background_texture.loadFromFile("Data/Images/lvl3.png")){}

  game_screen_LV3_background_sprite.setTexture(game_screen_LV3_background_texture);
  game_screen_LV3_background_texture.setRepeated(true);
  game_screen_LV3_background_sprite.setTextureRect(sf::IntRect(0,0,10000,1440));

  if (!texture_metal_sheet.loadFromFile(filename_metal_sheet)){}
  if (!texture_wood_sheet.loadFromFile(filename_wood_sheet)){}
  if (!texture_glass_sheet.loadFromFile(filename_glass_sheet)){}
  if (!texture_animal_sheet.loadFromFile(filename_animal_sheet)){}


  score_game.setString("0");
  score_game.setFillColor(sf::Color(255,255,255,255));
  score_game.setFont(font);
  score_game.setCharacterSize(30);
  score_game.setPosition(window.getSize().x/2 - (score_game.getGlobalBounds().width/2) + 15, window.getSize().y - score_game.getGlobalBounds().height * 3);


  restart_game_text_game.setString(" Restart by pressing R ");
  restart_game_text_game.setFillColor(sf::Color(255,255,255,255));
  restart_game_text_game.setFont(font);
  restart_game_text_game.setCharacterSize(30);
  restart_game_text_game.setPosition(window.getSize().x/2 - (restart_game_text_game.getGlobalBounds().width/2) + 15, window.getSize().y - restart_game_text_game.getGlobalBounds().height * 3);


  if (!sling_shot_texture.loadFromFile("Data/Images/resize.png")){}

  sling_shot_sprite.setTexture(sling_shot_texture);
  sling_shot_sprite.scale(0.9f,0.9f);
  sling_shot_sprite.setPosition(240,650);


  mainView.setViewport(sf::FloatRect(0,0,1.f,1.f));
  mainView.setSize(window.getSize().x , window.getSize().y);
  mainView.setCenter(window.getSize().x/2 , window.getSize().y/2);


  //--------------------------------------------------------
                      // lose screen

  game_ending_description.setString("this is a description ");
  game_ending_description.setFillColor(sf::Color(255,255,255,255));
  game_ending_description.setFont(font);
  game_ending_description.setCharacterSize(30);
  game_ending_description.setPosition(window.getSize().x/2 - (game_ending_description.getGlobalBounds().width/2) + 15, 150);


  back_ending_description.setString("Return to the main menu");
  back_ending_description.setFillColor(sf::Color(255,255,255,255));
  back_ending_description.setFont(font);
  back_ending_description.setCharacterSize(30);
  back_ending_description.setPosition(window.getSize().x/2 - (back_ending_description.getGlobalBounds().width/2) + 15, window.getSize().y - back_ending_description.getGlobalBounds().height * 3);


  //--------------------------------------------------------
                          // info screen

  back_info.setString(" Go Back to the Main Menu ");
  back_info.setFillColor(sf::Color(255,255,255,255));
  back_info.setFont(font);
  back_info.setCharacterSize(30);
  back_info.setPosition(window.getSize().x/2 - (back_info.getGlobalBounds().width/2) + 15, 100);

  description_info.setString("                      Eliminate all of the Aliens to go to the next level!\n "
                                   "            Destroy as many objects to get as many points as possible!\n\n"
                                   "                            Pull the bird back to fire the bird\n"
                                   "          Use the tracers from the last bird to fine tune your trajectory\n"
                                   "      different birds have different weights so the trajectory might differ\n\n"
                                   "        Use 'Space' to activate the different powers of each of the birds\n\n"
                                   " Use the arrow keys to move the camera and press 'enter' to re-center the camera\nUse 'R' to reset the level");
  description_info.setFillColor(sf::Color(255,255,255,255));
  description_info.setFont(font);
  description_info.setCharacterSize(25);
  description_info.setPosition(window.getSize().x/2 - (description_info.getGlobalBounds().width/2) + 100, 200);

  if (!bird1_desc_info_texture.loadFromFile(filename_bird_1)){}
  if (!bird2_desc_info_texture.loadFromFile(filename_bird_2)){}
  if (!bird3_desc_info_texture.loadFromFile(filename_bird_3)){}

  bird1_desc_info_sprite.setTexture(bird1_desc_info_texture);
  bird1_desc_info_sprite.setPosition(window.getSize().x/4 - (bird1_desc_info_sprite.getGlobalBounds().width/2) + 15 , 800);
  bird1_desc_info.setString("Double jumping bird\nActivate this to let\nthe bird gain some height");
  bird1_desc_info.setFillColor(sf::Color(255,255,255,255));
  bird1_desc_info.setFont(font);
  bird1_desc_info.setCharacterSize(20);
  bird1_desc_info.setPosition(window.getSize().x/4 - (bird1_desc_info.getGlobalBounds().width/2) + 15 , 700);


  bird2_desc_info_sprite.setTexture(bird2_desc_info_texture);
  bird2_desc_info_sprite.setPosition(window.getSize().x/2 - (bird2_desc_info_sprite.getGlobalBounds().width/2) + 15, 800);
  bird2_desc_info.setString("Heavy bird\nMakes the bird heavy for\nmaximum damage, but the trajectory\nwill change, be carefull");
  bird2_desc_info.setFillColor(sf::Color(255,255,255,255));
  bird2_desc_info.setFont(font);
  bird2_desc_info.setCharacterSize(20);
  bird2_desc_info.setPosition(window.getSize().x/2 - (bird2_desc_info.getGlobalBounds().width/2) + 15, 700);

  bird3_desc_info_sprite.setTexture(bird3_desc_info_texture);
  bird3_desc_info_sprite.setPosition(window.getSize().x/1.4 + (bird3_desc_info_sprite.getGlobalBounds().width/2)  + 30, 800);
  bird3_desc_info.setString("Boomerang bird\nMake the bird do a 180 in the air");
  bird3_desc_info.setFillColor(sf::Color(255,255,255,255));
  bird3_desc_info.setFont(font);
  bird3_desc_info.setCharacterSize(20);
  bird3_desc_info.setPosition(window.getSize().x/1.4 + 40, 700);

  //setting up the place for the minimap
  minimap.setViewport(sf::FloatRect(0.78,0.02,0.2,0.2f));
  minimap.setSize(1200 , 800);
  minimap.setCenter(2050, 500);

  return true;
}

void Game::update(float dt)
{
  switch (current_screen)
  {
    case GAME_SCREEN:

      score_game.setString(to_string(score));


      if(active_bird)
      {
        bool alive = false;
        for (auto & i : current_level_vector)
        {
          if (i->essential && !i->destroyd)
            alive = true;

          if (alive)
            break;
        }

        spawned_physics_bird->movement(dt);  //physics of the bird

        if ((spawned_physics_bird->x_comp >= -3 &&
           spawned_physics_bird->x_comp <= 3) && (spawned_physics_bird->y_comp >= -3 &&
           spawned_physics_bird->y_comp <= 3))
        {
          if (spawned_physics_bird->changeTexture())  // when first called it will start a timer, it will also return false untill that timer runs out
          {                               // when first called the texture changes as well
            delete spawned_physics_bird;              // after the timer runs out will return true, therefore delete the bird
            active_bird = false;
          }
        }

        if (!alive)
        {
          mainView.setCenter(window.getSize().x/2 , window.getSize().y/2);
          curr_level++;
          levelSetup(curr_level, false);
        }

        for (int i = 0; i <current_level_vector.size(); ++i)
        {
          if (current_level_vector[i]->destroyd)
            current_level_vector.erase(current_level_vector.begin() + i);
        }


        sf::Time tracer_Timer = tracer_clock.getElapsedTime();
        //when the timer is up draw a tracer on the screen to tell the player where to active_bird
        if (tracer_Timer > tracer_call && tracer_birds.size() < 11)
        {
          tracer_birds.push_back(new VisualBird(filename_tracer,3));
          tracer_birds[tracer_birds.size() -1]->getSprite()->setScale(0.4f,0.4f);
          tracer_birds[tracer_birds.size() -1]->getSprite()->setPosition((spawned_physics_bird->getSprite()->getPosition().x +
             spawned_physics_bird->getSprite()->getGlobalBounds().width/2) - tracer_birds[tracer_birds.size() -1]->getSprite()->getGlobalBounds().width/2,  (spawned_physics_bird->getSprite()->getPosition().y +
             spawned_physics_bird->getSprite()->getGlobalBounds().height/2) - tracer_birds[tracer_birds.size() -1]->getSprite()->getGlobalBounds().height/2);
          tracer_clock.restart();
        }
      }


      for (auto & i : current_level_vector) // call for the physics movement for all the world objects in the scene
      {
        i->movement(dt);
      }

      collisionCheck();
      cameraFollowSetting();

      break;
  }
}

void Game::render()
{

  window.setView(mainView);



  switch (current_screen)
  {
    case MAIN_MENU_SCREEN:

      window.draw(mainMenu_background_sprite);
      window.draw(choose_level_menuText);
      window.draw(start_game_menuText);
      window.draw(description_menuText);
      window.draw(info_menuText);

      break;

    case LEVEL_SELECTION_SCREEN:
      window.draw(mainMenu_background_sprite);
      window.draw(LV1_levelsel);
      window.draw(LV2_levelsel);
      window.draw(LV3_levelsel);
      window.draw(back_text_levelsel);

      break;

    case GAME_SCREEN:


      switch (curr_level)
      {
        case 1:
          window.draw(game_screen_LV1_background_sprite);
          break;

        case 2:
          window.draw(game_screen_LV2_background_sprite);
          break;

        case 3:
          window.draw(game_screen_LV3_background_sprite);
          break;

        default:
          window.draw(game_screen_LV1_background_sprite);
          break;
      }

      if (stack_of_birds.empty() && !active_bird)
        window.draw(restart_game_text_game);

      window.draw(score_game);

      window.draw(sling_shot_sprite);

      for (auto & tracer_bird : tracer_birds)
        window.draw(*tracer_bird->getSprite());

      if (active_bird)
        window.draw(*spawned_physics_bird->getSprite());

      for (auto & i : stack_of_birds)
        window.draw(*i->getSprite());

      if (ready_to_draw)
        for (auto & i : current_level_vector)
          if (!i->destroyd)
            window.draw(*i->getSprite());


      window.setView(minimap);  //re draw everything for the minimap


      switch (curr_level)  //draw the right background depending on the level the player is on
      {
        case 1:
          window.draw(game_screen_LV1_background_sprite);
          break;

        case 2:
          window.draw(game_screen_LV2_background_sprite);
          break;

        case 3:
          window.draw(game_screen_LV3_background_sprite);
          break;

        default:
          window.draw(game_screen_LV1_background_sprite);
          break;
      }

      for (auto & tracer_bird : tracer_birds)
        window.draw(*tracer_bird->getSprite());

      if (active_bird)
        window.draw(*spawned_physics_bird->getSprite());

      if (ready_to_draw)
        for (auto & i : current_level_vector)
          if (!i->destroyd)
            window.draw(*i->getSprite());

      break;

    case END_GAME_SCREEN:
      window.draw(mainMenu_background_sprite);
      window.draw(game_ending_description);
      break;


    case INFO_SCREEN:
      window.draw(game_screen_LV2_background_sprite);
      window.draw(back_info);
      window.draw(description_info);

      window.draw(bird1_desc_info_sprite);
      window.draw(bird2_desc_info_sprite);
      window.draw(bird3_desc_info_sprite);

      window.draw(bird1_desc_info);
      window.draw(bird2_desc_info);
      window.draw(bird3_desc_info);

      break;
  }
}

void Game::collisionCheck()
{
  if (active_bird)
  {
    int x_max = spawned_physics_bird->getSprite()->getPosition().x +spawned_physics_bird->getSprite()->getGlobalBounds().width;
    int x_min = spawned_physics_bird->getSprite()->getPosition().x;
    int y_min = spawned_physics_bird->getSprite()->getPosition().y;
    int y_max = spawned_physics_bird->getSprite()->getPosition().y +spawned_physics_bird->getSprite()->getGlobalBounds().height;

    int mid_ball_x = round((x_max + x_min)/2);
    int mid_ball_y = round((y_max + y_min)/2);


    if (spawned_physics_bird->getSprite()->getPosition().y +spawned_physics_bird->getSprite()->getGlobalBounds().height > window.getSize().y)
    {
      if (spawned_physics_bird->CalculateForce() >= -5 &&spawned_physics_bird->CalculateForce() <= 5)
      {
        spawned_physics_bird->x_comp = 0;
      }
      else
      {
        spawned_physics_bird->x_comp = (spawned_physics_bird->x_comp * 0.8);
      }
      spawned_physics_bird->y_comp = (spawned_physics_bird->y_comp * 0.6) * -1;
      spawned_physics_bird->getSprite()->setPosition(
        spawned_physics_bird->getSprite()->getPosition().x, window.getSize().y -
          spawned_physics_bird->getSprite()->getGlobalBounds().height);
    }


      //bird collsion with world objects
    for (auto & i : current_level_vector)
    {

      if (
        spawned_physics_bird->getSprite()->getGlobalBounds().intersects(i->getSprite()->getGlobalBounds())  && !spawned_physics_bird->destroy )  //&&!i->destroyd
      {
        if (circleCheck(mid_ball_x,mid_ball_y,spawned_physics_bird->getSprite()->getGlobalBounds().width / 2,i->getSprite()->getPosition().x,i->getSprite()->getPosition().y,i->getSprite()->getGlobalBounds().width,i->getSprite()->getGlobalBounds().height))
        {

          i->impactCall(spawned_physics_bird->x_comp * i->smoothness,spawned_physics_bird->y_comp * i->bouncyness,spawned_physics_bird->CalculateForce(),true);
          if (side == 1)
          {
            if (i->destroyd)
            {
              spawned_physics_bird->y_comp = (spawned_physics_bird->y_comp * i->break_retention);
              if (i->essential)
              {
                score += 200;
                score_curr_session += 200;   // need to keep the score count of the current session, in case the player restarts the score achived in that session needs to be taken away
              }
              else
              {
                score += 100;
                score_curr_session += 100;
              }
            }
            else
            {
              spawned_physics_bird->x_comp = (spawned_physics_bird->x_comp * 0.8);
              spawned_physics_bird->y_comp = (spawned_physics_bird->y_comp * 0.6) * -1;
            }

            spawned_physics_bird->getSprite()->setPosition(spawned_physics_bird->getSprite()->getPosition().x,i->getSprite()->getPosition().y -spawned_physics_bird->getSprite()->getGlobalBounds().height);
          }

          else if (side == 2)
          {
            i->impactCall(spawned_physics_bird->x_comp * i->smoothness,spawned_physics_bird->y_comp * i->bouncyness,spawned_physics_bird->CalculateForce(),true);
            if (i->destroyd)
            {
              spawned_physics_bird->x_comp = (spawned_physics_bird->x_comp * i->break_retention);
              if (i->essential)
              {
                score += 200;
                score_curr_session += 200;
              }
              else
              {
                score += 100;
                score_curr_session += 100;
              }
            }
            else
            {
              spawned_physics_bird->x_comp = (spawned_physics_bird->x_comp * 0.6) * -1;
            }
            spawned_physics_bird->getSprite()->setPosition(i->getSprite()->getPosition().x +i->getSprite()->getGlobalBounds().width,
              spawned_physics_bird->getSprite()->getPosition().y);
          }
          else if (side == 3)
          {
            i->impactCall(spawned_physics_bird->x_comp * i->smoothness,spawned_physics_bird->y_comp * i->bouncyness,spawned_physics_bird->CalculateForce(),true);
            if (i->destroyd)
            {
              spawned_physics_bird->y_comp = (spawned_physics_bird->y_comp * i->break_retention); // bounce back value of the bird
              if (i->essential)
              {
                score += 200;
                score_curr_session += 200;
              }
              else
              {
                score += 100;
                score_curr_session += 100;
              }
            }
            else
            {
              spawned_physics_bird->x_comp = (spawned_physics_bird->x_comp * 0.8);
              spawned_physics_bird->y_comp = (spawned_physics_bird->y_comp * 0.6) * -1;
            }

          }
          else if (side == 4)
          {
            i->impactCall(spawned_physics_bird->x_comp * i->smoothness,spawned_physics_bird->y_comp * i->bouncyness,spawned_physics_bird->CalculateForce(),true);
            if (i->destroyd)
            {
              spawned_physics_bird->x_comp = (spawned_physics_bird->x_comp * i->break_retention); // bounce back value of the bird
              if (i->essential)
              {
                score += 200;
                score_curr_session += 200;
              }
              else
              {
                score += 100;
                score_curr_session += 100;
              }
            }
            else
            {
              spawned_physics_bird->x_comp = (spawned_physics_bird->x_comp * 0.6) * -1;
            }
            spawned_physics_bird->getSprite()->setPosition(i->getSprite()->getPosition().x -
                spawned_physics_bird->getSprite()->getGlobalBounds().width,
              spawned_physics_bird->getSprite()->getPosition().y);
          }
        }
      }
    }
  }

  //loop to calculate interaction in between objects
  for (int i = 0; i < current_level_vector.size(); ++i)
  {
    int x_max = current_level_vector[i]->getSprite()->getPosition().x + current_level_vector[i]->getSprite()->getGlobalBounds().width;
    int x_min = current_level_vector[i]->getSprite()->getPosition().x;
    int y_min = current_level_vector[i]->getSprite()->getPosition().y;
    int y_max = current_level_vector[i]->getSprite()->getPosition().y + current_level_vector[i]->getSprite()->getGlobalBounds().height;

    int mid_square_x = round((x_max + x_min)/2);
    int mid_square_y = round((y_max + y_min)/2);

    for (int j = 0; j < current_level_vector.size(); ++j)
    {
      // if the main obj hits the bottom of the screen
      if (current_level_vector[i]->getSprite()->getPosition().y + current_level_vector[i]->getSprite()->getGlobalBounds().height > window.getSize().y)
      {
        current_level_vector[i]->x_comp = (current_level_vector[i]->x_comp * current_level_vector[i]->smoothness);
        current_level_vector[i]->y_comp = (current_level_vector[i]->y_comp * 0.6) * -1;
        current_level_vector[i]->impactCall(0,0,current_level_vector[i]->CalculateForce(),false);
        current_level_vector[i]->getSprite()->setPosition(current_level_vector[i]->getSprite()->getPosition().x, window.getSize().y - current_level_vector[i]->getSprite()->getGlobalBounds().height);
      }

      if (current_level_vector[i]->x_comp >= -10 && current_level_vector[i]->x_comp <= 10)
      {
        current_level_vector[i]->x_comp = 0;
      }


      if (i != j && !current_level_vector[i]->destroyd && !current_level_vector[j]->destroyd)
      {
        // the main object                                                      other object
        if(current_level_vector[i]->getSprite()->getGlobalBounds().intersects(current_level_vector[j]->getSprite()->getGlobalBounds()))
        {
          //run the polygon check function only if a collision is sure to save on performance
          switch (polygonCheck(mid_square_x,mid_square_y,current_level_vector[j]->getSprite()->getPosition().x,current_level_vector[j]->getSprite()->getPosition().y,current_level_vector[j]->getSprite()->getGlobalBounds().width,current_level_vector[j]->getSprite()->getGlobalBounds().height))
          {

            case 1:

              if (current_level_vector[i]->CalculateForce() >= -5 && current_level_vector[i]->CalculateForce() <= 5) //if the resultant force of the main_obj is too low, dont calculate the physics anymore and make it stationary
              {
                current_level_vector[i]->x_comp = 0;
              }
              else
              {
                current_level_vector[j]->impactCall(0, current_level_vector[i]->y_comp * current_level_vector[j]->bouncyness, current_level_vector[i]->CalculateForce(),false);   //pass a portion of the impact force to the object collided with
                if (current_level_vector[j]->destroyd)
                {
                  if (current_level_vector[j])
                  {
                    score += 200;
                    score_curr_session += 200;
                  }
                  else
                  {
                    score += 100;
                    score_curr_session += 100;
                  }

                  current_level_vector[i]->y_comp = (current_level_vector[i]->y_comp * current_level_vector[j]->break_retention);
                }
                else
                {
                  current_level_vector[i]->x_comp = (current_level_vector[i]->x_comp * current_level_vector[i]->smoothness);    //take some "momentum" off the main object, to give it "physics"
                }
              }
              current_level_vector[i]->y_comp = (current_level_vector[i]->y_comp * current_level_vector[i]->bouncyness) * -1;   //make the obj bounce due to the nature of the collision
              current_level_vector[i]->getSprite()->setPosition(current_level_vector[i]->getSprite()->getPosition().x, current_level_vector[j]->getSprite()->getPosition().y - current_level_vector[i]->getSprite()->getGlobalBounds().height);   //make sure the obj doesnt go through other obj

              break;


            case 2:

              current_level_vector[j]->impactCall(current_level_vector[i]->x_comp * current_level_vector[j]->smoothness, 0, current_level_vector[i]->CalculateForce(),false);
              current_level_vector[i]->x_comp = (current_level_vector[i]->x_comp * current_level_vector[i]->smoothness) * -1;
              current_level_vector[i]->getSprite()->setPosition(current_level_vector[j]->getSprite()->getPosition().x + current_level_vector[j]->getSprite()->getGlobalBounds().width, current_level_vector[i]->getSprite()->getPosition().y);

              break;

            case 3:

              if (current_level_vector[i]->CalculateForce() >= -5 && current_level_vector[i]->CalculateForce() <= 5)
              {
                current_level_vector[i]->x_comp = 0;
              }
              else
              {
                current_level_vector[j]->impactCall(0, current_level_vector[i]->y_comp * current_level_vector[j]->bouncyness, current_level_vector[i]->CalculateForce(),false);

                if (current_level_vector[j]->destroyd)
                {
                  if (current_level_vector[j])
                  {
                    score += 200;
                    score_curr_session += 200;
                  }
                  else
                  {
                    score += 100;
                    score_curr_session += 100;
                  }

                  current_level_vector[i]->y_comp = (current_level_vector[i]->y_comp * current_level_vector[j]->break_retention);
                }
                else
                {
                  current_level_vector[i]->x_comp = (current_level_vector[i]->x_comp * current_level_vector[i]->smoothness);    //take some "momentum" off the main object, to give it "physics"
                }
              }
              current_level_vector[i]->y_comp = (current_level_vector[i]->y_comp * current_level_vector[i]->bouncyness) * -1;     //make the obj bounce due to the nature of the collision


              break;

            case 4:

              current_level_vector[j]->impactCall(current_level_vector[i]->x_comp * current_level_vector[j]->smoothness, 0, current_level_vector[i]->CalculateForce(),false);
              current_level_vector[i]->x_comp = (current_level_vector[i]->x_comp * current_level_vector[i]->smoothness) * -1;
              current_level_vector[i]->getSprite()->setPosition(current_level_vector[j]->getSprite()->getPosition().x - current_level_vector[i]->getSprite()->getGlobalBounds().width, current_level_vector[i]->getSprite()->getPosition().y);

              break;

          }
        }
      }
    }
  }
}


void Game::mouseClicked(sf::Event event)
{
  click = sf::Mouse::getPosition(window);

  switch (current_screen)
  {
    case MAIN_MENU_SCREEN:
      if ((click.x >= start_game_menuText.getPosition().x && click.x <= start_game_menuText.getPosition().x + start_game_menuText.getGlobalBounds().width) && (click.y >= start_game_menuText.getPosition().y && click.y <= start_game_menuText.getPosition().y + start_game_menuText.getGlobalBounds().height))
      {
        current_screen = GAME_SCREEN;
        score = 0;

        levelSetup(1, false);
      }

      if ((click.x >= choose_level_menuText.getPosition().x && click.x <= choose_level_menuText.getPosition().x + choose_level_menuText.getGlobalBounds().width) && (click.y >= choose_level_menuText.getPosition().y && click.y <= choose_level_menuText.getPosition().y + choose_level_menuText.getGlobalBounds().height))
        current_screen = LEVEL_SELECTION_SCREEN;

      if ((click.x >= info_menuText.getPosition().x && click.x <= info_menuText.getPosition().x + info_menuText.getGlobalBounds().width) && (click.y >= info_menuText.getPosition().y && click.y <= info_menuText.getPosition().y + info_menuText.getGlobalBounds().height))
        current_screen = INFO_SCREEN;

      break;

    case LEVEL_SELECTION_SCREEN:
      if ((click.x >= back_text_levelsel .getPosition().x && click.x <= back_text_levelsel.getPosition().x + back_text_levelsel.getGlobalBounds().width) && (click.y >= back_text_levelsel.getPosition().y && click.y <= back_text_levelsel.getPosition().y + back_text_levelsel.getGlobalBounds().height))
        current_screen = MAIN_MENU_SCREEN;

      if ((click.x >= LV1_levelsel .getPosition().x && click.x <= LV1_levelsel.getPosition().x + LV1_levelsel.getGlobalBounds().width) && (click.y >= LV1_levelsel.getPosition().y && click.y <= LV1_levelsel.getPosition().y + LV1_levelsel.getGlobalBounds().height))
      {
        current_screen = GAME_SCREEN;
        levelSetup(1, false);
      }

      if ((click.x >= LV2_levelsel .getPosition().x && click.x <= LV2_levelsel.getPosition().x + LV2_levelsel.getGlobalBounds().width) && (click.y >= LV2_levelsel.getPosition().y && click.y <= LV2_levelsel.getPosition().y + LV2_levelsel.getGlobalBounds().height))
      {
        current_screen = GAME_SCREEN;
        levelSetup(2, false);
      }

      if ((click.x >= LV3_levelsel .getPosition().x && click.x <= LV3_levelsel.getPosition().x + LV3_levelsel.getGlobalBounds().width) && (click.y >= LV3_levelsel.getPosition().y && click.y <= LV3_levelsel.getPosition().y + LV3_levelsel.getGlobalBounds().height))
      {
        current_screen = GAME_SCREEN;
        levelSetup(3, false);
      }

      break;


    case GAME_SCREEN:
      if (!stack_of_birds.empty())  // if the player has clicked the bird that is ready to be fired
      {
        if ((click.x >= stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getPosition().x &&click.x<= stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getPosition().x + stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getGlobalBounds().width)&& (click.y >= stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getPosition().y  &&click.y <= stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getPosition().y + stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getGlobalBounds().height))
        {
          active_bird   = false;
          mouse_clicked = true;
        }
      }

      break;


    case END_GAME_SCREEN:
      if ((click.x >= back_ending_description .getPosition().x && click.x <= back_ending_description.getPosition().x + back_ending_description.getGlobalBounds().width) && (click.y >= back_ending_description.getPosition().y && click.y <= back_ending_description.getPosition().y + back_ending_description.getGlobalBounds().height))
        current_screen  = MAIN_MENU_SCREEN;

      break;


    case INFO_SCREEN:
      if ((click.x >= back_info.getPosition().x && click.x <=back_info.getPosition().x + back_info.getGlobalBounds().width) && (click.y >= back_info.getPosition().y && click.y <=back_info.getPosition().y + back_info.getGlobalBounds().height))
        current_screen  = MAIN_MENU_SCREEN;

      break;
  }
}
void Game::mousePos(sf::Event event)
{ //changing text depending if the cursor is on top of it
  curr_mouse_pos_pos = sf::Mouse::getPosition(window);

  switch (current_screen)
  {
    case MAIN_MENU_SCREEN:

      if ((curr_mouse_pos_pos.x >= start_game_menuText.getPosition().x && curr_mouse_pos_pos.x <= start_game_menuText.getPosition().x + start_game_menuText.getGlobalBounds().width) && (curr_mouse_pos_pos.y >= start_game_menuText.getPosition().y && curr_mouse_pos_pos.y <= start_game_menuText.getPosition().y + start_game_menuText.getGlobalBounds().height))
        start_game_menuText.setString("<Start the Game here!!!>");
      else
        start_game_menuText.setString(" Start the Game here!!! ");

      if ((curr_mouse_pos_pos.x >= choose_level_menuText.getPosition().x && curr_mouse_pos_pos.x <= choose_level_menuText.getPosition().x + choose_level_menuText.getGlobalBounds().width) && (curr_mouse_pos_pos.y >= choose_level_menuText.getPosition().y && curr_mouse_pos_pos.y <= choose_level_menuText.getPosition().y + choose_level_menuText.getGlobalBounds().height))
        choose_level_menuText.setString("<Select Level here>");
      else
        choose_level_menuText.setString(" Select Level here ");

      if ((curr_mouse_pos_pos.x >= info_menuText.getPosition().x && curr_mouse_pos_pos.x <= info_menuText.getPosition().x + info_menuText.getGlobalBounds().width) && (curr_mouse_pos_pos.y >= info_menuText.getPosition().y && curr_mouse_pos_pos.y <= info_menuText.getPosition().y + info_menuText.getGlobalBounds().height))
        info_menuText.setString("<Info and controls>");
      else
        info_menuText.setString(" Info and controls ");

      break;


    case LEVEL_SELECTION_SCREEN:
      if ((curr_mouse_pos_pos.x >= back_text_levelsel.getPosition().x && curr_mouse_pos_pos.x <= back_text_levelsel.getPosition().x + back_text_levelsel.getGlobalBounds().width) && (curr_mouse_pos_pos.y >= back_text_levelsel.getPosition().y && curr_mouse_pos_pos.y <= back_text_levelsel.getPosition().y + back_text_levelsel.getGlobalBounds().height))
        back_text_levelsel.setString("<Return to the main menu>");
      else
        back_text_levelsel.setString(" Return to the main menu ");

      if ((curr_mouse_pos_pos.x >= LV1_levelsel .getPosition().x && curr_mouse_pos_pos.x <= LV1_levelsel.getPosition().x + LV1_levelsel.getGlobalBounds().width) && (curr_mouse_pos_pos.y >= LV1_levelsel.getPosition().y && curr_mouse_pos_pos.y <= LV1_levelsel.getPosition().y + LV1_levelsel.getGlobalBounds().height))
        LV1_levelsel.setString("<Play level 1>");
      else
        LV1_levelsel.setString(" Play level 1 ");

      if ((curr_mouse_pos_pos.x >= LV2_levelsel .getPosition().x && curr_mouse_pos_pos.x <= LV2_levelsel.getPosition().x + LV2_levelsel.getGlobalBounds().width) && (curr_mouse_pos_pos.y >= LV2_levelsel.getPosition().y && curr_mouse_pos_pos.y <= LV2_levelsel.getPosition().y + LV2_levelsel.getGlobalBounds().height))
        LV2_levelsel.setString("<Play level 2>");
      else
        LV2_levelsel.setString(" Play level 2 ");

      if ((curr_mouse_pos_pos.x >= LV3_levelsel .getPosition().x && curr_mouse_pos_pos.x <= LV3_levelsel.getPosition().x + LV3_levelsel.getGlobalBounds().width) && (curr_mouse_pos_pos.y >= LV3_levelsel.getPosition().y && curr_mouse_pos_pos.y <= LV3_levelsel.getPosition().y + LV3_levelsel.getGlobalBounds().height))
        LV3_levelsel.setString("<Play level 3>");
      else
        LV3_levelsel.setString(" Play level 3 ");

      break;


    case INFO_SCREEN:
      if ((curr_mouse_pos_pos.x >= back_info.getPosition().x && curr_mouse_pos_pos.x <=back_info.getPosition().x + back_info.getGlobalBounds().width) && (curr_mouse_pos_pos.y >= back_info.getPosition().y && curr_mouse_pos_pos.y <=back_info.getPosition().y + back_info.getGlobalBounds().height))
        back_info.setString("<Go Back to the Main Menu>");
      else
        back_info.setString(" Go Back to the Main Menu ");

      break;
  }
}
void Game::mouseMoved(sf::Event event)
{
  curr_mouse_pos_move = sf::Mouse::getPosition(window);

  if (mouse_clicked)
  {
    if (curr_mouse_pos_move.x <= 300 && power < 1)  //change the position of the sprite depending on the pos of the mouse and if it is in range
      stack_of_birds[stack_of_birds.size() - 1]->getSprite()->setPosition(curr_mouse_pos_move.x - stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getGlobalBounds().width/2  ,curr_mouse_pos_move.y - stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getGlobalBounds().height/2   );

    circlePowerCalculations();    //calculate the value for the power
  }
}
void Game::mouseReleased(sf::Event event)
{
  if (mouse_clicked)
  {
    mouse_clicked = false;
    switch (stack_of_birds[stack_of_birds.size() - 1]->TOB)  // once the player releases the bird, spawn a bird of the same type that is being dragged
    {
      case VisualBird::NORMAL:
        spawned_physics_bird = new Birds(filename_bird_1,
          power,1,5, stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getPosition().x  + stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getGlobalBounds().width/2 , stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getPosition().y  + stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getGlobalBounds().height/2, x_comp,y_comp);
        break;

      case VisualBird::HEAVY:
        spawned_physics_bird = new Birds(filename_bird_2,
          power,2, 8, stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getPosition().x  + stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getGlobalBounds().width/2 , stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getPosition().y  + stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getGlobalBounds().height/2, x_comp,y_comp);
        break;

      case VisualBird::BOOMERANG:
        spawned_physics_bird = new Birds(filename_bird_3,
          power,3, 5, stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getPosition().x  + stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getGlobalBounds().width/2 , stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getPosition().y  + stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getGlobalBounds().height/2, x_comp,y_comp);
        break;

      default:
        break;
    }

    stack_of_birds.pop_back();     //get rid of the bird that has just been dragged
    active_bird = true;     //set the state to active_bird to calculate all of the interactions


    if (!stack_of_birds.empty()) //if the vector is not empty, then that means that the player still has birds he can use, set the next bird in the scene ready to be fired
      stack_of_birds[stack_of_birds.size() - 1]->getSprite()->setPosition(300 - stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getGlobalBounds().width/2  , 700 - stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getGlobalBounds().height/2   );


    //tracer birds
    if (!tracer_birds.empty()) //if not empty then clear the vector by deleting the objects from memory ready to for new ones to be stored
    {
      int size = tracer_birds.size();

      for (int i = 0; i < size; ++i)
      {
        delete tracer_birds[size - 1];
      }
      tracer_birds.clear();
    }
    //start the first tracer bird with a red one to signal where the player released the mouse
    tracer_birds.push_back(new VisualBird(filename_beginner_tracer,3));    //spawn the initial tracer
    tracer_birds[tracer_birds.size() -1]->getSprite()->setScale(0.2f,0.2f);
    tracer_birds[tracer_birds.size() -1]->getSprite()->setPosition((spawned_physics_bird->getSprite()->getPosition().x +
       spawned_physics_bird->getSprite()->getGlobalBounds().width/2) - tracer_birds[tracer_birds.size() -1]->getSprite()->getGlobalBounds().width/2,  (spawned_physics_bird->getSprite()->getPosition().y +
       spawned_physics_bird->getSprite()->getGlobalBounds().height/2) - tracer_birds[tracer_birds.size() -1]->getSprite()->getGlobalBounds().height/2);
    tracer_clock.restart();
  }
}

void Game::keyPressed(sf::Event event)
{
  cout
  if (current_screen == GAME_SCREEN)
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  //move camera controls
      mainView.setCenter(mainView.getCenter().x - 10 , window.getSize().y/2);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      mainView.setCenter(mainView.getCenter().x + 10 , window.getSize().y/2);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
      mainView.setCenter(window.getSize().x/2 , window.getSize().y/2);


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))  //reset level
      levelSetup(curr_level, true);


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))  //activate ability of the bird
    {
      if (active_bird && !spawned_physics_bird->ability_used)
      {
        switch (spawned_physics_bird->TOB)
        {
          case Birds::NORMAL:

            if (spawned_physics_bird->y_comp >0)
              spawned_physics_bird->y_comp *= -1;
            else
              spawned_physics_bird->y_comp -= 40;

            break;

          case Birds::HEAVY:
            spawned_physics_bird->weight = 30;
            break;

          case Birds::BOOMERANG:
            spawned_physics_bird->x_comp *= -1;
            break;
        }
        spawned_physics_bird->ability_used = true;
      }
    }
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))   // player returns to the main menu
  {
    if (active_bird)
    {
      delete spawned_physics_bird;
      active_bird = false;
    }

    score = 0;

    current_screen = MAIN_MENU_SCREEN;
    mainView.setCenter(window.getSize().x/2 , window.getSize().y/2);
  }
}


bool Game::circleCheck(float center_x, float center_y, float radius, float square_x, float square_y, float square_width, float square_heigth)
{
  float edge_of_square_X = center_x;
  float edge_of_square_Y = center_y;

  // which edge is closest? the side is in respect of the obj
  if (center_x < square_x)
  {        // is ont  the left?  if the circle x is smaller then the pos x of obj
    edge_of_square_X = square_x;        // compare to left edge
    side=4;
  }
  else if (center_x > square_x + square_width)
  {  // right?   if the circle x is bigger then the pos of x plus the widht
    edge_of_square_X = square_x + square_width;     // right edge
    side=2;
  }

  if (center_y < square_y)
  {      // top?  if center of cirlce is smaller then pos of the obj y
    edge_of_square_Y = square_y;        // top edge
    side=1;
  }
  else if (center_y > square_y + square_heigth) {    // is the circle beneath the square
    edge_of_square_Y = square_y + square_heigth;     // get the distance from the middle of the circle to the closest edge to the bottom
    side=3;
  }

  // get distance from closest edges
  float distX = center_x - edge_of_square_X;
  float distY = center_y - edge_of_square_Y;
  float distance = sqrt( (distX*distX) + (distY*distY));   //find the disatnce from the center of the circle to the closest edge

  if (distance <= radius)
  {// distance from the edge is lower then the radius the its a hit
    return true;  //return true to the intersect
  }
  return false;

}//                          this is the middle
int Game::polygonCheck(float main_x_pos, float main_y_pos, float square_x, float square_y, float square_width, float rh)
{
  int side_touched = 0;

  // which edge is closest? the side is in respect of the obj
  if (main_x_pos < square_x) //left?
    side_touched = 4;
  else if (main_x_pos > square_x + square_width)    // right?
    side_touched = 2;

  if (main_y_pos < square_y)  // top?
    side_touched = 1;
  else if (main_y_pos > square_y + rh) // bottom ?
    side_touched = 3;

  return side_touched;
}

void Game::cameraFollowSetting()
{
  if(mainView.getCenter().x < window.getSize().x/2)
  {
    mainView.setCenter(window.getSize().x/2 , window.getSize().y/2);
  }

  if (active_bird)  // main camera follows the bird once it passes the middle of the screen
  {
    if ((spawned_physics_bird->getSprite()->getPosition().x +
           spawned_physics_bird->getSprite()->getGlobalBounds().width/2 > window.getSize().x/2))
    {
      mainView.setCenter(
        spawned_physics_bird->getSprite()->getPosition().x +
          spawned_physics_bird->getSprite()->getGlobalBounds().width/2 , window.getSize().y/2);
    }
  }

  score_game.setPosition(mainView.getCenter().x - (score_game.getGlobalBounds().width/2) + 15, window.getSize().y - score_game.getGlobalBounds().height * 3);

}
void Game::circlePowerCalculations()
{
  power = hypot(click.x - curr_mouse_pos_move.x, click.y - curr_mouse_pos_move.y);

  power = power /150;

  if (power > 1)
  {
    power = 1;
  }
  else if (power < 1)
  {
    x_comp = click.x - curr_mouse_pos_move.x;
    y_comp = click.y - curr_mouse_pos_move.y;
  }
}
void Game::levelSetup(int level, bool restart)
{

  if (restart)  // if restarted then take away the score from that session
  {
    score -= score_curr_session;
  }
  score_curr_session = 0;


  curr_level = level;
  ready_to_draw = false;

  mainView.setCenter(window.getSize().x/2 , window.getSize().y/2);

  if (active_bird)
  {
    delete spawned_physics_bird;
    active_bird = false;
  }

  float height = 0;
  stack_of_birds.clear();
  current_level_vector.clear();

  if (!tracer_birds.empty())
  {
    int size = tracer_birds.size();

    for (int i = 0; i < size; ++i)
    {
      delete tracer_birds[size - 1];
    }
    tracer_birds.clear();
  }


  switch(level)
  {
    case 1:

      for (auto & i : LV1) //taking the address
      {
        i.resetObj();
        current_level_vector.push_back(&i);   //saving it in a pointer variable
      }

      for (auto & i : stack_of_birds_LV1) // for every element in the main level array
      {
        stack_of_birds.push_back(&i);  // add that item to the vector with the
        stack_of_birds[stack_of_birds.size()-1]->getSprite()->setPosition(0, window.getSize().y - stack_of_birds[stack_of_birds.size()-1]->getSprite()->getGlobalBounds().height - height);

        height += stack_of_birds[stack_of_birds.size()-1]->getSprite()->getGlobalBounds().height;
      }

      break;

    case 2:
      for (auto & i : LV2)
      {
        i.resetObj();
        current_level_vector.push_back(&i);
      }

      for (auto & i : stack_of_birds_LV2)
      {
        stack_of_birds.push_back(&i);
        stack_of_birds[stack_of_birds.size()-1]->getSprite()->setPosition(0, window.getSize().y - stack_of_birds[stack_of_birds.size()-1]->getSprite()->getGlobalBounds().height - height);

        height += stack_of_birds[stack_of_birds.size()-1]->getSprite()->getGlobalBounds().height;
      }

      break;

    case 3:
      for (auto & i : LV3)
      {
        i.resetObj();
        current_level_vector.push_back(&i);
      }

      for (auto & i : stack_of_birds_LV3)
      {
        stack_of_birds.push_back(&i);  // add that item to the vector with the
        stack_of_birds[stack_of_birds.size()-1]->getSprite()->setPosition(0, window.getSize().y - stack_of_birds[stack_of_birds.size()-1]->getSprite()->getGlobalBounds().height - height);

        height += stack_of_birds[stack_of_birds.size()-1]->getSprite()->getGlobalBounds().height;
      }


      break;

    case 4: // one of the cases is an overflow for when there are no more levels, therefore the game ends with a victory
      game_ending_description.setString("You have won WOWWOWO! You beat all of the levels\n                  Press Esc to return to the menu to\n   choose a specific level or start from the beginning\n\n                        Your final score was " + to_string(score));
      game_ending_description.setPosition(window.getSize().x/2 - game_ending_description.getGlobalBounds().width/2, window.getSize().y/6);

      current_screen = END_GAME_SCREEN;
      break;
  }

  if (curr_level != 4)
    stack_of_birds[stack_of_birds.size() - 1]->getSprite()->setPosition( 300 - stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getGlobalBounds().width/2  , 700 - stack_of_birds[stack_of_birds.size() - 1]->getSprite()->getGlobalBounds().height/2   );

  ready_to_draw = true;
}