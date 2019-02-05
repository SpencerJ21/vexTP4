#include "main.h"
#include "autonomousSelect/autonomousRoutine.hpp"
#include <functional>

autonomousRoutine::autonomousRoutine(const char* title_i,
                                     lv_style_t* style_i,
                                     std::function<void()> routine,
                                     std::function<void(lv_obj_t*)> printField):

                                     title(title_i),
                                     textStyle(style_i)
{
  run = routine;
  print = printField;
}
