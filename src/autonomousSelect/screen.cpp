#include "main.h"
#include "autonomousSelect/screen.hpp"
#include <utility>

lv_style_t list_style;
lv_style_t field_style;
lv_style_t blue_alliance;
lv_style_t blue_alliance_highlighted;
lv_style_t blue_flag_highlighted;
lv_style_t red_alliance;
lv_style_t red_alliance_highlighted;
lv_style_t red_flag_highlighted;
lv_style_t blue_park;
lv_style_t blue_park_highlighted;
lv_style_t red_park;
lv_style_t red_park_highlighted;
lv_style_t yellow_park;
lv_style_t line_style;
lv_style_t blue_cap;
lv_style_t blue_cap_highlighted;
lv_style_t red_cap;
lv_style_t red_cap_highlighted;
lv_style_t ball_style;
lv_style_t pole_style;
lv_style_t white_text;
lv_style_t blue_text;
lv_style_t red_text;
lv_style_t green_box;
lv_style_t pressed_button;



void initialize_styles(){
  lv_style_copy(&list_style, &lv_style_plain);
  list_style.body.main_color = LV_COLOR_SILVER;
  list_style.body.grad_color = LV_COLOR_SILVER;
  list_style.body.border.width = 3;
  list_style.body.radius = 0;

  list_style.body.border.color = LV_COLOR_BLACK;
  list_style.body.border.width = 3;

  lv_style_copy(&field_style, &list_style);
  field_style.body.main_color = LV_COLOR_GRAY;
  field_style.body.grad_color = LV_COLOR_GRAY;

  lv_style_copy(&blue_alliance, &field_style);
  blue_alliance.body.main_color = LV_COLOR_BLUE;
  blue_alliance.body.grad_color = LV_COLOR_BLUE;
  blue_alliance.body.border.width = 0;

  lv_style_copy(&blue_alliance_highlighted, &blue_alliance);
  blue_alliance_highlighted.body.border.width = 3;
  blue_alliance_highlighted.body.border.color = LV_COLOR_WHITE;

  lv_style_copy(&red_alliance, &blue_alliance);
  red_alliance.body.main_color = LV_COLOR_RED;
  red_alliance.body.grad_color = LV_COLOR_RED;

  lv_style_copy(&red_alliance_highlighted, &red_alliance);
  red_alliance_highlighted.body.border.width = 3;
  red_alliance_highlighted.body.border.color = LV_COLOR_WHITE;

  lv_style_copy(&blue_park, &lv_style_plain);
  blue_park.body.main_color = LV_COLOR_SILVER;
  blue_park.body.grad_color = LV_COLOR_SILVER;
  blue_park.body.radius = 7;
  blue_park.body.border.width = 4;
  blue_park.body.border.color = LV_COLOR_BLUE;

  lv_style_copy(&blue_park_highlighted, &blue_park);
  blue_park_highlighted.body.main_color = LV_COLOR_WHITE;
  blue_park_highlighted.body.grad_color = LV_COLOR_WHITE;

  lv_style_copy(&red_park, &blue_park);
  red_park.body.border.color = LV_COLOR_RED;

  lv_style_copy(&red_park_highlighted, &blue_park_highlighted);
  red_park_highlighted.body.border.color = LV_COLOR_RED;

  lv_style_copy(&yellow_park, &blue_park);
  yellow_park.body.border.color = LV_COLOR_YELLOW;

  lv_style_copy(&line_style, &lv_style_plain);
  line_style.body.main_color = LV_COLOR_WHITE;
  line_style.body.grad_color = LV_COLOR_WHITE;
  line_style.line.color = LV_COLOR_WHITE;
  line_style.line.width = 3;

  lv_style_copy(&blue_cap, &blue_alliance);
  blue_cap.body.radius = 4;

  lv_style_copy(&blue_cap_highlighted, &blue_cap);
  blue_cap_highlighted.body.border.width = 2;
  blue_cap_highlighted.body.border.color = LV_COLOR_WHITE;

  lv_style_copy(&red_cap, &red_alliance);
  red_cap.body.radius = 4;

  lv_style_copy(&red_cap_highlighted, &red_cap);
  red_cap_highlighted.body.border.width = 2;
  red_cap_highlighted.body.border.color = LV_COLOR_WHITE;

  lv_style_copy(&ball_style, &lv_style_plain);
  ball_style.body.main_color = LV_COLOR_YELLOW;
  ball_style.body.grad_color = LV_COLOR_YELLOW;
  ball_style.body.radius = LV_RADIUS_CIRCLE;

  lv_style_copy(&blue_flag_highlighted, &blue_alliance_highlighted);
  blue_flag_highlighted.body.border.width = 1;

  lv_style_copy(&red_flag_highlighted, &red_alliance_highlighted);
  red_flag_highlighted.body.border.width = 1;

  lv_style_copy(&pole_style, &red_alliance);
  pole_style.body.main_color = LV_COLOR_BLACK;
  pole_style.body.grad_color = LV_COLOR_BLACK;

  lv_style_copy(&white_text, &lv_style_plain);
  white_text.text.color = LV_COLOR_WHITE;
  white_text.text.font = &lv_font_dejavu_20;
  white_text.text.letter_space = 2;
  white_text.text.line_space = 1;

  lv_style_copy(&blue_text, &white_text);
  blue_text.text.color = LV_COLOR_BLUE;

  lv_style_copy(&red_text, &white_text);
  red_text.text.color = LV_COLOR_RED;

  lv_style_copy(&green_box, &list_style);
  green_box.body.main_color = LV_COLOR_MAKE(0x00, 0xDD, 0x00);
  green_box.body.grad_color = LV_COLOR_MAKE(0x00, 0xDD, 0x00);

  lv_style_copy(&pressed_button, &list_style);
  pressed_button.body.main_color = LV_COLOR_GRAY;
  pressed_button.body.grad_color = LV_COLOR_GRAY;
}


//=================================================================================================================//
//default screen setting

void defaultLeftCaps(lv_obj_t* parent){
  cap blue_cap_1(parent, cap_position::left_1, cap_state::blue);
  cap red_cap_2(parent, cap_position::left_2, cap_state::red_slanted);
  cap red_cap_3(parent, cap_position::left_3, cap_state::red_slanted);
  cap blue_cap_4(parent, cap_position::left_4, cap_state::blue);
}

void defaultRightCaps(lv_obj_t* parent){
  cap red_cap_1(parent, cap_position::right_1, cap_state::red);
  cap blue_cap_2(parent, cap_position::right_2, cap_state::blue_slanted);
  cap blue_cap_3(parent, cap_position::right_3, cap_state::blue_slanted);
  cap red_cap_4(parent, cap_position::right_4, cap_state::red);
}

void defaultLeftFlags(lv_obj_t* parent){
  flag left_top(parent, flag_position::left_high, flag_state::blue);
  flag left_mid(parent, flag_position::left_middle, flag_state::blue);
  flag left_low(parent, flag_position::left_low, flag_state::blue);
}

void defaultMiddleFlags(lv_obj_t* parent){
  flag center_top(parent, flag_position::center_high, flag_state::neutral);
  flag center_mid(parent, flag_position::center_middle, flag_state::neutral);
  flag center_low(parent, flag_position::center_low, flag_state::neutral);
}

void defaultRightFlags(lv_obj_t* parent){
  flag right_top(parent, flag_position::right_high, flag_state::red);
  flag right_mid(parent, flag_position::right_middle, flag_state::red);
  flag right_low(parent, flag_position::right_low, flag_state::red);
}

void defaultParking(lv_obj_t* parent){
  platform red_platform(parent, platform_color::red);
  platform blue_platform(parent, platform_color::blue);
  platform yellow_platform(parent, platform_color::yellow);
}

void defaultLeftBalls(lv_obj_t* parent){
  lv_obj_t* ball_1 = lv_obj_create(parent, NULL);
  lv_obj_set_style(ball_1, &ball_style);
  lv_obj_set_pos(ball_1, 54, 54);
  lv_obj_set_size(ball_1, 5,5);

  lv_obj_t* ball_2 = lv_obj_create(parent, ball_1);
  lv_obj_set_pos(ball_2, 60, 60);

  lv_obj_t* ball_5 = lv_obj_create(parent, ball_1);
  lv_obj_set_pos(ball_5, 66, 122);

  lv_obj_t* ball_6 = lv_obj_create(parent, ball_1);
  lv_obj_set_pos(ball_6, 66, 153);

  lv_obj_t* ball_9 = lv_obj_create(parent, ball_1);
  lv_obj_set_pos(ball_9, 97, 212);

  lv_obj_t* ball_10 = lv_obj_create(parent, ball_1);
  lv_obj_set_pos(ball_10, 97, 222);
}

void defaultRightBalls(lv_obj_t* parent){
  lv_obj_t* ball_3 = lv_obj_create(parent, NULL);
  lv_obj_set_style(ball_3, &ball_style);
  lv_obj_set_pos(ball_3, 174, 60);
  lv_obj_set_size(ball_3, 5,5);

  lv_obj_t* ball_4 = lv_obj_create(parent, ball_3);
  lv_obj_set_pos(ball_4, 180, 54);

  lv_obj_t* ball_7 = lv_obj_create(parent, ball_3);
  lv_obj_set_pos(ball_7, 170, 122);

  lv_obj_t* ball_8 = lv_obj_create(parent, ball_3);
  lv_obj_set_pos(ball_8, 170, 153);

  lv_obj_t* ball_11 = lv_obj_create(parent, ball_3);
  lv_obj_set_pos(ball_11, 137, 212);

  lv_obj_t* ball_12 = lv_obj_create(parent, ball_3);
  lv_obj_set_pos(ball_12, 137, 222);
}

void drawLines(lv_obj_t* parent){
  lv_obj_t* middle_line_1 = lv_obj_create(parent, NULL);
  lv_obj_set_style(middle_line_1, &line_style);
  lv_obj_set_pos(middle_line_1, 115, 3);
  lv_obj_set_size(middle_line_1, 3, 234);
  lv_obj_t* middle_line_2 = lv_obj_create(parent, middle_line_1);
  lv_obj_set_x(middle_line_1, 122);


  lv_obj_t* expansion_line = lv_line_create(parent, NULL);
  lv_line_set_style(expansion_line, &line_style);
  static lv_point_t expansion_points[6] = {{3,120}, {40,120}, {40,200}, {200,200}, {200,120}, {237,120}};
  lv_line_set_points(expansion_line, expansion_points, 6);
}

void drawFlagPoles(lv_obj_t* parent){
  lv_obj_t* flag_pole_1 = lv_obj_create(parent, NULL);
  lv_obj_set_style(flag_pole_1, &pole_style);
  lv_obj_set_size(flag_pole_1, 3, 37);
  lv_obj_set_pos(flag_pole_1, 39, 3);

  lv_obj_t* flag_pole_2 = lv_obj_create(parent, flag_pole_1);
  lv_obj_set_x(flag_pole_2, 119);

  lv_obj_t* flag_pole_3 = lv_obj_create(parent, flag_pole_1);
  lv_obj_set_x(flag_pole_3, 199);
}

void defaultField(lv_obj_t* parent){
  starting_tile top_red_starting_tile(parent, starting_tile_position::far_red);
  starting_tile bottom_red_starting_tile(parent, starting_tile_position::near_red);
  starting_tile top_blue_starting_tile(parent, starting_tile_position::far_blue);
  starting_tile bottom_blue_starting_tile(parent, starting_tile_position::near_blue);

  drawLines(parent);

  defaultLeftCaps(parent);
  defaultRightCaps(parent);

  defaultLeftFlags(parent);
  defaultMiddleFlags(parent);
  defaultRightFlags(parent);
  drawFlagPoles(parent);

  defaultParking(parent);

  defaultLeftBalls(parent);
  defaultRightBalls(parent);
}



//=================================================================================================================//
//screen classes


//caps
cap::cap(lv_obj_t* parent, cap_position position_i, cap_state state_i, bool changed_i):
                                                        position(position_i),
                                                        state(state_i),
                                                        changed(changed_i)
{
  image = lv_obj_create(parent, NULL);

  print();
}

void cap::print(){
  std::pair<int, int> coordinates;

  switch(position){
    case cap_position::left_1:
      coordinates = std::pair(92 ,212);
      break;
    case cap_position::left_2:
      coordinates = std::pair(92 ,172);
      break;
    case cap_position::left_3:
      coordinates = std::pair(92 ,92 );
      break;
    case cap_position::left_4:
      coordinates = std::pair(52 ,52 );
      break;
    case cap_position::right_1:
      coordinates = std::pair(132,212);
      break;
    case cap_position::right_2:
      coordinates = std::pair(132,172);
      break;
    case cap_position::right_3:
      coordinates = std::pair(132,92 );
      break;
    case cap_position::right_4:
      coordinates = std::pair(172,52 );
      break;
  };

  bool slanted = (state == cap_state::red_slanted) || (state == cap_state::blue_slanted);

  if(slanted){
    coordinates.first += 3;
    lv_obj_set_size(image, 10, 15);
  }else{
    lv_obj_set_size(image, 15, 15);
  }

  if(state == cap_state::red || state == cap_state::red_slanted){
    if(changed){
      lv_obj_set_style(image, &red_cap_highlighted);
    }else{
      lv_obj_set_style(image, &red_cap);
    }
  }else{
    if(changed){
      lv_obj_set_style(image, &blue_cap_highlighted);
    }else{
      lv_obj_set_style(image, &blue_cap);
    }
  }

  lv_obj_set_pos(image, coordinates.first, coordinates.second);
}

//=================================================================================================================//


//flags
flag::flag(lv_obj_t* parent, flag_position position_i, flag_state state_i, bool changed_i):
                                                        position(position_i),
                                                        state(state_i),
                                                        changed(changed_i)
{
  image_blue = lv_obj_create(parent, NULL);
  image_red = lv_obj_create(parent, NULL);

  print();
}


void flag::print(){
  std::pair<int, int> coordinates;

  switch(position){
    case flag_position::left_high:
      coordinates = std::pair(40 ,3 );
      break;
    case flag_position::left_middle:
      coordinates = std::pair(40 ,12);
      break;
    case flag_position::left_low:
      coordinates = std::pair(40 ,21);
      break;
    case flag_position::center_high:
      coordinates = std::pair(120,3 );
      break;
    case flag_position::center_middle:
      coordinates = std::pair(120,12);
      break;
    case flag_position::center_low:
      coordinates = std::pair(120,21);
      break;
    case flag_position::right_high:
      coordinates = std::pair(200,3 );
      break;
    case flag_position::right_middle:
      coordinates = std::pair(200,12);
      break;
    case flag_position::right_low:
      coordinates = std::pair(200,21);
      break;
  };

  switch(state){
    case flag_state::blue:
      lv_obj_set_hidden(image_blue, false);
      lv_obj_set_hidden(image_red, true);

      lv_obj_set_size(image_blue, 12, 7);

      if(changed){
        lv_obj_set_style(image_blue, &blue_flag_highlighted);
      }else{
        lv_obj_set_style(image_blue, &blue_alliance);
      }

      lv_obj_set_pos(image_blue, coordinates.first - 12, coordinates.second);

      break;
    case flag_state::neutral:

      lv_obj_set_hidden(image_red, false);
      lv_obj_set_hidden(image_blue, false);

      lv_obj_set_style(image_blue, &blue_alliance);
      lv_obj_set_style(image_red, &red_alliance);

      lv_obj_set_size(image_blue, 8, 7);
      lv_obj_set_size(image_red, 8, 7);

      lv_obj_set_pos(image_blue, coordinates.first - 8, coordinates.second);
      lv_obj_set_pos(image_red, coordinates.first, coordinates.second);

      break;
    case flag_state::red:

      lv_obj_set_hidden(image_red, false);
      lv_obj_set_hidden(image_blue, true);

      lv_obj_set_size(image_red, 12, 7);

      if(changed){
        lv_obj_set_style(image_red, &red_flag_highlighted);
      }else{
        lv_obj_set_style(image_red, &red_alliance);
      }

      lv_obj_set_pos(image_red, coordinates.first, coordinates.second);

      break;
  }
}

//=================================================================================================================//


//parking platforms
platform::platform(lv_obj_t* parent, platform_color color_i, bool selected_i):
                                                            color(color_i),
                                                            selected(selected_i)
{
  image = lv_obj_create(parent, NULL);

  print();
}

void platform::print(){
  std::pair<int, int> coordinates;

  switch(color){
  case platform_color::red:
    coordinates = std::pair(64, 120);

    if(selected){
      lv_obj_set_style(image, &red_park_highlighted);
    }else{
      lv_obj_set_style(image, &red_park);
    }

    break;
  case platform_color::blue:
    coordinates = std::pair(138, 120);

    if(selected){
      lv_obj_set_style(image, &blue_park_highlighted);
    }else{
      lv_obj_set_style(image, &blue_park);
    }

    break;
  case platform_color::yellow:
    coordinates = std::pair(100, 120);
    lv_obj_set_style(image, &yellow_park);
    break;
  }

  if(color == platform_color::yellow){
    lv_obj_set_size(image, 40, 40);
  }else{
    lv_obj_set_size(image, 38, 40);
  }

  lv_obj_set_pos(image, coordinates.first, coordinates.second);
}

//=================================================================================================================//


//starting tiles
starting_tile::starting_tile(lv_obj_t* parent, starting_tile_position position_i, bool selected_i):
                            position(position_i), selected(selected_i)
{
  image = lv_obj_create(parent, NULL);
  lv_obj_set_size(image, 37, 40);

  print();
}

void starting_tile::print(){
  std::pair<int, int> coordinates;

  switch(position){
    case starting_tile_position::far_red:
      coordinates = std::pair(3, 80);

      if(selected){
        lv_obj_set_style(image, &red_alliance_highlighted);
      }else{
        lv_obj_set_style(image, &red_alliance);
      }

      break;
    case starting_tile_position::near_red:
      coordinates = std::pair(3, 160);

      if(selected){
        lv_obj_set_style(image, &red_alliance_highlighted);
      }else{
        lv_obj_set_style(image, &red_alliance);
      }

      break;
    case starting_tile_position::far_blue:
      coordinates = std::pair(200, 80);

      if(selected){
        lv_obj_set_style(image, &blue_alliance_highlighted);
      }else{
        lv_obj_set_style(image, &blue_alliance);
      }

      break;
    case starting_tile_position::near_blue:
      coordinates = std::pair(200, 160);

      if(selected){
        lv_obj_set_style(image, &blue_alliance_highlighted);
      }else{
        lv_obj_set_style(image, &blue_alliance);
      }

      break;
  }

  lv_obj_set_pos(image, coordinates.first, coordinates.second);
}
