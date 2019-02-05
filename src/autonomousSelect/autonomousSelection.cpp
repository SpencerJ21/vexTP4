#include "main.h"
#include "autonomousSelect/screen.hpp"
#include "autonomousSelect/routines.hpp"
#include <vector>
/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */

int selection = 2;

void competition_initialize() {
  initialize_styles();

  const int number_of_routines = autonomousRoutines.size();


  lv_obj_t* scr = lv_obj_create(NULL, NULL);
  lv_scr_load(scr);


  lv_obj_t* main_list = lv_obj_create(scr, NULL);
  lv_obj_set_style(main_list, &list_style);
  lv_obj_set_pos(main_list, 0, 0);
  lv_obj_set_size(main_list, 240, 40 * number_of_routines);
  lv_obj_set_drag(main_list, true);


  lv_obj_t* field = lv_obj_create(scr, NULL);
  lv_obj_set_style(field, &field_style);
  lv_obj_set_pos(field, 240, 0);
  lv_obj_set_size(field, 240, 240);


  std::vector<lv_obj_t*> routine_buttons;
  std::vector<lv_obj_t*> routine_labels;
  routine_buttons.resize(number_of_routines);
  routine_labels.resize(number_of_routines);

  for(int i = 0; i < number_of_routines; i++){

    routine_buttons[i] = lv_btn_create(main_list, NULL);

    lv_obj_set_size(routine_buttons[i], 200, 40);

    lv_btn_set_style(routine_buttons[i], LV_BTN_STYLE_REL, &list_style);
    lv_btn_set_style(routine_buttons[i], LV_BTN_STYLE_PR, &pressed_button);

    if(i == 0){
      //first term only

      lv_obj_align(routine_buttons[i], NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);
    }else{

      lv_obj_align(routine_buttons[i], routine_buttons[i-1], LV_ALIGN_OUT_BOTTOM_MID , 0, 0);
    }


    routine_labels[i] = lv_label_create(routine_buttons[i], NULL);
    lv_obj_set_style(routine_labels[i], autonomousRoutines[i].textStyle);
    lv_label_set_text(routine_labels[i], autonomousRoutines[i].title);
    lv_obj_align(routine_labels[i], NULL, LV_ALIGN_IN_LEFT_MID, 0, 0);
  }

  lv_obj_t* confirm_button = lv_btn_create(main_list, NULL);
  lv_obj_set_style(confirm_button, &green_box);
  lv_obj_set_size(confirm_button, 40, 40);
  lv_obj_set_pos(confirm_button, 200, 40 * selection);

  autonomousRoutines.at(selection).print(field);


  while(lv_btn_get_state(confirm_button) != LV_BTN_STATE_PR){

    for(int i = 0; i < number_of_routines; i++){
      if(lv_btn_get_state(routine_buttons[i]) == LV_BTN_STATE_PR){
        selection = i;
        lv_obj_set_y(confirm_button, 40 * selection);

        lv_obj_clean(field);
        autonomousRoutines.at(selection).print(field);
      }
    }

    lv_obj_set_x(main_list, 0);
    pros::delay(1);
  }

  lv_obj_del(main_list);
  lv_obj_set_x(field, 120);

  pros::delay(10000);

  lv_obj_del(lv_scr_act());
}
