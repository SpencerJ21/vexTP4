#ifndef AUTONOMOUSROUTINE_HPP_
#define AUTONOMOUSROUTINE_HPP_
#include "main.h"
#include <functional>
#include <string>


class autonomousRoutine{
public:
  const char* title;
  lv_style_t* textStyle;

  std::function<void()> run;
  std::function<void(lv_obj_t*)> print;

  autonomousRoutine(const char* title_i, lv_style_t* style_i, std::function<void()> routine, std::function<void(lv_obj_t*)> printField);
};

#endif
