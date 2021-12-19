
#ifndef ANGRYBIRDS_GAME_H
#define ANGRYBIRDS_GAME_H


#include <SFML/Graphics.hpp>
#include "VisualBird.h"
#include "Birds.h"
#include "WorldObj.h"
#include <iostream>
#include <cmath>
using namespace std;

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void collisionCheck();

  void cameraFollowSetting();
  void circlePowerCalculations();
  void levelSetup(int level,bool restart);
  bool circleCheck(float center_x, float center_y, float radius, float square_x, float square_y, float square_width, float square_heigth);
  int polygonCheck(float main_x_pos, float main_y_pos, float square_x, float square_y, float square_width, float rh);
   /**
   *  The "circleCheck" function comes from a modified version of the function called "circleRect"
   *  from the source code below, for interaction of circles to polygons
   *  https://openprocessing.org/sketch/533102//
   *
   *  The "polygonCheck" function is a modified version of the "circleCheck" for the interactions of polygons to polygons
   */


  void keyPressed(sf::Event event);
  void mousePos(sf::Event event);
  void mouseMoved(sf::Event event);
  void mouseReleased(sf::Event event);
  void mouseClicked(sf::Event event);


 private:
  sf::RenderWindow& window;
  sf::Font font;

  //menu stuff
  sf::Texture mainMenu_background_texture;
  sf::Sprite mainMenu_background_sprite;

  sf::Text start_game_menuText;
  sf::Text info_menuText;
  sf::Text choose_level_menuText;
  sf::Text description_menuText;


  //choose level screen stuff
  sf::Text back_text_levelsel;
  sf::Text LV1_levelsel;
  sf::Text LV2_levelsel;
  sf::Text LV3_levelsel;

  //game screen stuff
  sf::Text game_ending_description;
  sf::Text back_ending_description;

  //info screen stuff
  sf::Text back_info;
  sf::Text description_info;
  sf::Text bird1_desc_info;
  sf::Text bird2_desc_info;
  sf::Text bird3_desc_info;

  sf::Texture bird1_desc_info_texture;
  sf::Texture bird2_desc_info_texture;
  sf::Texture bird3_desc_info_texture;
  sf::Sprite bird1_desc_info_sprite;
  sf::Sprite bird2_desc_info_sprite;
  sf::Sprite bird3_desc_info_sprite;

  //game screen stuff
  sf::Texture game_screen_LV1_background_texture;
  sf::Sprite game_screen_LV1_background_sprite;

  sf::Texture sling_shot_texture;
  sf::Sprite sling_shot_sprite;

  sf::Text restart_game_text_game;
  sf::Text score_game;

  sf::Texture game_screen_LV2_background_texture;
  sf::Sprite game_screen_LV2_background_sprite;

  sf::Texture game_screen_LV3_background_texture;
  sf::Sprite game_screen_LV3_background_sprite;

  sf::View minimap;
  sf::View mainView;



  std::string filename_bird_1 = "Data/Images/kenney_physicspack/PNG/Aliens/alienBlue_round.png";
  std::string filename_bird_2 = "Data/Images/kenney_physicspack/PNG/Aliens/alienGreen_round.png";
  std::string filename_bird_3 = "Data/Images/kenney_physicspack/PNG/Aliens/alienBeige_round.png";

  std::string filename_metal_sheet = "Data/Images/kenney_physicspack/Spritesheet/spritesheet_metal.png";
  sf::Texture texture_metal_sheet;
  sf::Texture* metal_texture_ref = &texture_metal_sheet;

  std::string filename_animal_sheet = "Data/Images/kenney_animalpackredux/Spritesheet/square_nodetails.png";
  sf::Texture texture_animal_sheet;
  sf::Texture* animal_texture_ref = &texture_animal_sheet;

  std::string filename_wood_sheet = "Data/Images/kenney_physicspack/Spritesheet/spritesheet_wood.png";
  sf::Texture texture_wood_sheet;
  sf::Texture* wood_texture_ref = &texture_wood_sheet;

  std::string filename_glass_sheet = "Data/Images/kenney_physicspack/Spritesheet/spritesheet_glass.png";
  sf::Texture texture_glass_sheet;
  sf::Texture* glass_texture_ref = &texture_glass_sheet;


  //tracer bird logic setup
  sf::Clock tracer_clock;
  sf::Time tracer_call = sf::seconds(0.1f);
  std::vector<VisualBird*> tracer_birds;

  std::string filename_tracer = "Data/Images/kenney_physicspack/PNG/Aliens/alienBlue_round.png";
  std::string filename_beginner_tracer = "Data/Images/kenney_animalpackredux/PNG/Round/duck.png";


  //variables dealing with mouse functions
  bool mouse_clicked = false;

  sf::Vector2i click;
  sf::Vector2i curr_mouse_pos_move;
  sf::Vector2i curr_mouse_pos_pos;

  float power;
  float x_comp = 0;
  float y_comp = 0;

  //the actual "physics" bird
  Birds* spawned_physics_bird;

  bool active_bird = false;

  int score = 0;
  int score_curr_session = 0;


  //dealing with the visual representation of the birds
  std::vector<VisualBird*> stack_of_birds;

  //array containing the types of birds to be used per levels to then be copied
  VisualBird stack_of_birds_LV1[3] = {VisualBird(filename_bird_2,2), VisualBird(filename_bird_1,1),
                                       VisualBird(filename_bird_2,2)};

  VisualBird stack_of_birds_LV3[6] = {VisualBird(filename_bird_1,1), VisualBird(filename_bird_3,4),
                                      VisualBird(filename_bird_1,1), VisualBird(filename_bird_2,2),VisualBird(filename_bird_3,4),VisualBird(filename_bird_1,1)};

  VisualBird stack_of_birds_LV2[4] = {VisualBird(filename_bird_2,2), VisualBird(filename_bird_3,4),
                                      VisualBird(filename_bird_2,2), VisualBird(filename_bird_2,2)};











  int curr_level;

  int side = 0;    //side of collision, circle to polygon interaction

  bool ready_to_draw = false;     //load the level, then true when game is ready


  //coordinates of the object textures from the sprite-sheet
  int box_filled_metal_text_coords[3][4] = {{500,0,140,140},{500,430,140,140},{220,70,140,140}};
  int rec_upright_hollow_metal_text_coords[3][4] = {{640,0,70,220},{640,0,70,220},{710,0,70,220}};

  int rec_upright_filled_glass_text_coords[3][4] = {{710,210,70,220},{500,640,70,220},{640,430,70,220}};
  int rec_liying_hollow_glass_text_coords[3][4] = {{0,140,220,70},{0,490,220,70},{0,560,220,70}};
  int box_filled_glass_text_coords[3][4] = {{220,360,140,140},{220,360,140,140},{220,360,140,140}};

  int rec_liying_full_wood_text_coords[3][4] = {{0,70,220,70},{0,280,220,70},{0,0,220,70}};
  int rec_upright_full_wood_text_coords[3][4] = {{710,710,70,220},{640,0,70,220},{640,360,70,220}};

  int animal_LV1_text_coords[3][4] = {{257,128,128,128},{257,128,128,128},{257,128,128,128}};
  int animal_LV2_text_coords[3][4] = {{129,384,128,128},{129,384,128,128},{129,384,128,128}};
  int animal_LV3_text_coords[3][4] = {{257,384,128,128},{257,384,128,128},{257,384,128,128}};


  std::vector<WorldObj*> current_level_vector;

  //array containing the types of objects and all of the stats to be used per levels to then be copied
  WorldObj LV2[9] =   {
                      WorldObj(metal_texture_ref, 1600, 600, 10,(int *)rec_upright_hollow_metal_text_coords,220,0.2f,0.2,0.3f, false),
                      WorldObj(glass_texture_ref, 1700, 100, 7,(int *)rec_liying_hollow_glass_text_coords ,20,0.2f,0.2,0.8f, false),
                      WorldObj(glass_texture_ref, 1850, 100, 7,(int *)rec_liying_hollow_glass_text_coords,20,0.2f,0.2,0.8f, false),
                      WorldObj(metal_texture_ref, 2050, 600, 10,(int *)rec_upright_hollow_metal_text_coords,220,0.2f,0.2,0.3f, false),
                      WorldObj(animal_texture_ref, 1800, 600, 3,(int *)animal_LV2_text_coords,10,0.2f,0.2,0.3f, true),
                      WorldObj(glass_texture_ref, 2080, 100, 7,(int *)rec_liying_hollow_glass_text_coords ,20,0.2f,0.2,0.8f, false),
                      WorldObj(glass_texture_ref, 2300, 100, 7,(int *)rec_liying_hollow_glass_text_coords,20,0.2f,0.2,0.8f, false),
                      WorldObj(metal_texture_ref, 2480, 600, 10,(int *)rec_upright_hollow_metal_text_coords,220,0.2f,0.2,0.3f, false),
                      WorldObj(animal_texture_ref, 2250, 600, 3,(int *)animal_LV2_text_coords,10,0.2f,0.2,0.3f, true)
                      };

  WorldObj LV3[14] = {
    WorldObj(metal_texture_ref, 1600, 600, 10,(int *)rec_upright_hollow_metal_text_coords,250,0.2f,0.2,0.3f, false),
    WorldObj(wood_texture_ref, 1700, 400, 7,(int *)rec_liying_full_wood_text_coords ,30,0.2f,0.2,0.9f, false),
    WorldObj(wood_texture_ref, 1850, 400, 7,(int *)rec_liying_full_wood_text_coords,200,0.4f,0.5,0.7f, false),
    WorldObj(metal_texture_ref, 2050, 600, 10,(int *)rec_upright_hollow_metal_text_coords,250,0.2f,0.2,0.3f, false),
    WorldObj(animal_texture_ref, 1800, 250, 3,(int *)animal_LV3_text_coords,10,0.2f,0.2,0.3f, true),
    WorldObj(wood_texture_ref, 2080, 400, 7,(int *)rec_liying_full_wood_text_coords,200,0.4f,0.5,0.7f, false),
    WorldObj(wood_texture_ref, 2300, 400, 7,(int *)rec_liying_full_wood_text_coords,200,0.4f,0.5,0.7f, false),
    WorldObj(metal_texture_ref, 2480, 600, 10,(int *)rec_upright_hollow_metal_text_coords,250,0.2f,0.2,0.3f, false),
    WorldObj(animal_texture_ref, 2250, 250, 3,(int *)animal_LV3_text_coords,10,0.2f,0.2,0.3f, true),

    WorldObj(glass_texture_ref, 1600, 0, 7,(int *)rec_upright_filled_glass_text_coords,30,0.2f,0.2,0.8f, false),
    WorldObj(metal_texture_ref, 2050, 0, 10,(int *)rec_upright_hollow_metal_text_coords,220,0.2f,0.2,0.3f, false),

    WorldObj(wood_texture_ref, 1700, -200, 7,(int *)rec_liying_full_wood_text_coords ,120,0.4f,0.5,0.7f, false),
    WorldObj(wood_texture_ref, 1850, -200, 7,(int *)rec_liying_full_wood_text_coords,120,0.4f,0.5,0.7f, false),
    WorldObj(wood_texture_ref, 2080, -200, 7,(int *)rec_liying_full_wood_text_coords ,120,0.4f,0.5,0.7f, false),
  };

  WorldObj LV1[10] =
    {
      WorldObj(metal_texture_ref, 1710, 600, 10,(int *)rec_upright_hollow_metal_text_coords,220,0.2f,0.2,0.3f, false),
      WorldObj(wood_texture_ref, 1640, 400, 7,(int *)rec_liying_full_wood_text_coords ,150,0.2f,0.2,0.4f, false),
      WorldObj(wood_texture_ref, 1790, 300, 7,(int *)rec_liying_full_wood_text_coords ,150,0.2f,0.2,0.4f, false),
      WorldObj(wood_texture_ref, 1910, 200, 7,(int *)rec_liying_full_wood_text_coords ,150,0.2f,0.2,0.4f, false),
      WorldObj(wood_texture_ref, 2030, 100, 7,(int *)rec_liying_full_wood_text_coords ,150,0.2f,0.2,0.4f, false),
      WorldObj(wood_texture_ref, 2150, 0, 7,(int *)rec_liying_full_wood_text_coords ,150,0.2f,0.2,0.4f, false),
      WorldObj(glass_texture_ref, 2280, -100, 7,(int *)rec_liying_hollow_glass_text_coords,40,0.2f,0.2,0.8f, false),
      WorldObj(metal_texture_ref, 2450, -350, 10,(int *)rec_upright_hollow_metal_text_coords,220,0.2f,0.2,0.3f, false),
      WorldObj(metal_texture_ref, 2450, -650, 10,(int *)rec_upright_hollow_metal_text_coords,220,0.2f,0.2,0.3f, false),
      WorldObj(animal_texture_ref, 2450, 600, 3,(int *)animal_LV2_text_coords,10,0.2f,0.2,0.1f, true)
    };


  //showing screen management
  enum CurrentScreen
  {
    MAIN_MENU_SCREEN = 0,
    LEVEL_SELECTION_SCREEN,
    INFO_SCREEN,
    GAME_SCREEN,
    END_GAME_SCREEN
  };

  CurrentScreen current_screen = MAIN_MENU_SCREEN;

};

#endif // ANGRYBIRDS_GAME_H
