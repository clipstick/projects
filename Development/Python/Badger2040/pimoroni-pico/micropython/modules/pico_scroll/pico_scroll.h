// Include MicroPython API.
#include "py/runtime.h"

// Declare the functions we'll make available in Python
extern mp_obj_t picoscroll_init();
extern mp_obj_t picoscroll_get_width();
extern mp_obj_t picoscroll_get_height();
extern mp_obj_t picoscroll_update();
extern mp_obj_t picoscroll_set_pixel(mp_obj_t x_obj, mp_obj_t y_obj, mp_obj_t v_obj);
extern mp_obj_t picoscroll_set_pixels(mp_obj_t image_obj);
extern mp_obj_t picoscroll_show_text(mp_obj_t text_obj, mp_obj_t brightness, mp_obj_t offset);
extern mp_obj_t picoscroll_scroll_text(mp_obj_t text_obj, mp_obj_t brightness, mp_obj_t delay);
extern mp_obj_t picoscroll_show_bitmap_1d(mp_obj_t bitmap_obj, mp_obj_t brightness, mp_obj_t offset);
extern mp_obj_t picoscroll_clear();
extern mp_obj_t picoscroll_is_pressed(mp_obj_t button_obj);
