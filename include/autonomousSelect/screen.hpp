#ifndef SCREEN_H_
#define SCREEN_H_
#include "main.h"

void initialize_styles();

extern lv_style_t blank_style;
extern lv_style_t list_style;
extern lv_style_t field_style;
extern lv_style_t blue_alliance;
extern lv_style_t blue_alliance_highlighted;
extern lv_style_t blue_flag_highlighted;
extern lv_style_t red_alliance;
extern lv_style_t red_alliance_highlighted;
extern lv_style_t red_flag_highlighted;
extern lv_style_t blue_park;
extern lv_style_t blue_park_highlighted;
extern lv_style_t red_park;
extern lv_style_t red_park_highlighted;
extern lv_style_t yellow_park;
extern lv_style_t line_style;
extern lv_style_t blue_cap;
extern lv_style_t blue_cap_highlighted;
extern lv_style_t red_cap;
extern lv_style_t red_cap_highlighted;
extern lv_style_t ball_style;
extern lv_style_t pole_style;
extern lv_style_t white_text;
extern lv_style_t blue_text;
extern lv_style_t red_text;
extern lv_style_t green_box;
extern lv_style_t pressed_button;
extern lv_style_t sans_text_box;



void defaultLeftCaps(lv_obj_t* parent);
void defaultRightCaps(lv_obj_t* parent);
void defaultLeftFlags(lv_obj_t* parent);
void defaultMiddleFlags(lv_obj_t* parent);
void defaultRightFlags(lv_obj_t* parent);
void defaultParking(lv_obj_t* parent);
void defaultLeftBalls(lv_obj_t* parent);
void defaultRightBalls(lv_obj_t* parent);
void drawLines(lv_obj_t* parent);
void drawFlagPoles(lv_obj_t* parent);
void defaultField(lv_obj_t* parent);



//4 is farthest from audience, 1 is closest
enum class cap_position{
  left_1, left_2, left_3, left_4, right_1, right_2, right_3, right_4
};

enum class cap_state{
  blue, red, blue_slanted, red_slanted
};

class cap{
public:
  lv_obj_t* image;
  cap_position position;
  cap_state state;
  bool changed;

  cap(lv_obj_t* parent, cap_position position_i, cap_state state_i, bool changed_i = false);

  void print();
};



enum class flag_position{
  left_high, left_middle, left_low, center_high, center_middle, center_low, right_high, right_middle, right_low
};

enum class flag_state{
  blue, neutral, red
};

class flag{
public:
  lv_obj_t* image_blue;
  lv_obj_t* image_red;

  flag_position position;
  flag_state state;
  bool changed;

  flag(lv_obj_t* parent, flag_position position_i, flag_state state_i, bool changed_i = false);

  void print();
};



enum class platform_color{
  blue, red, yellow
};

class platform{
public:
  lv_obj_t* image;
  platform_color color;
  bool selected;

  platform(lv_obj_t* parent, platform_color color_i, bool selected_i = false);

  void print();
};



enum class starting_tile_position{
  far_red, near_red, far_blue, near_blue
};

class starting_tile{
public:
  lv_obj_t* image;
  starting_tile_position position;
  bool selected;

  starting_tile(lv_obj_t* parent, starting_tile_position position_i, bool selected_i = false);

  void print();
};

#endif //header guard
