#include "libraries/breakout_matrix11x7/breakout_matrix11x7.hpp"
#include <cstdio>

#define MP_OBJ_TO_PTR2(o, t) ((t *)(uintptr_t)(o))

// SDA/SCL on even/odd pins, I2C0/I2C1 on even/odd pairs of pins.
#define IS_VALID_SCL(i2c, pin) (((pin) & 1) == 1 && (((pin) & 2) >> 1) == (i2c))
#define IS_VALID_SDA(i2c, pin) (((pin) & 1) == 0 && (((pin) & 2) >> 1) == (i2c))


using namespace pimoroni;

extern "C" {
#include "breakout_matrix11x7.h"
#include "pimoroni_i2c.h"

/***** I2C Struct *****/
typedef struct _PimoroniI2C_obj_t {
    mp_obj_base_t base;
    I2C *i2c;
} _PimoroniI2C_obj_t;

/***** Variables Struct *****/
typedef struct _breakout_matrix11x7_BreakoutMatrix11x7_obj_t {
    mp_obj_base_t base;
    BreakoutMatrix11x7 *breakout;
} breakout_matrix11x7_BreakoutMatrix11x7_obj_t;

/***** Print *****/
void BreakoutMatrix11x7_print(const mp_print_t *print, mp_obj_t self_in, mp_print_kind_t kind) {
    (void)kind; //Unused input parameter    
    breakout_matrix11x7_BreakoutMatrix11x7_obj_t *self = MP_OBJ_TO_PTR2(self_in, breakout_matrix11x7_BreakoutMatrix11x7_obj_t);
    BreakoutMatrix11x7* breakout = self->breakout;
    mp_print_str(print, "BreakoutMatrix11x7(");

    mp_print_str(print, "i2c = ");
    mp_obj_print_helper(print, mp_obj_new_int((breakout->get_i2c() == i2c0) ? 0 : 1), PRINT_REPR);

    mp_print_str(print, ", address = 0x");
    char buf[3];
    sprintf(buf, "%02X", breakout->get_address());
    mp_print_str(print, buf);

    mp_print_str(print, ", sda = ");
    mp_obj_print_helper(print, mp_obj_new_int(breakout->get_sda()), PRINT_REPR);

    mp_print_str(print, ", scl = ");
    mp_obj_print_helper(print, mp_obj_new_int(breakout->get_scl()), PRINT_REPR);

    mp_print_str(print, ")");
}

/***** Constructor *****/
mp_obj_t BreakoutMatrix11x7_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *all_args) {
    breakout_matrix11x7_BreakoutMatrix11x7_obj_t *self = nullptr;

    enum { ARG_i2c, ARG_address };
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_i2c, MP_ARG_OBJ, {.u_obj = nullptr} },
        { MP_QSTR_address, MP_ARG_INT, {.u_int = BreakoutMatrix11x7::DEFAULT_I2C_ADDRESS} }
    };

    // Parse args.
    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all_kw_array(n_args, n_kw, all_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

    // Get I2C bus.
    if(!MP_OBJ_IS_TYPE(args[ARG_i2c].u_obj, &PimoroniI2C_type)) {
        mp_raise_ValueError(MP_ERROR_TEXT("BreakoutMatrix11x7: Bad i2C object"));
        return mp_const_none;
    }

    _PimoroniI2C_obj_t *i2c = (_PimoroniI2C_obj_t *)MP_OBJ_TO_PTR(args[ARG_i2c].u_obj);

    self = m_new_obj(breakout_matrix11x7_BreakoutMatrix11x7_obj_t);
    self->base.type = &breakout_matrix11x7_BreakoutMatrix11x7_type;

    self->breakout = new BreakoutMatrix11x7(i2c->i2c, args[ARG_address].u_int);

    if(!self->breakout->init()) {
        mp_raise_msg(&mp_type_RuntimeError, "BreakoutMatrix11x7: breakout not found when initialising");
    }

    return MP_OBJ_FROM_PTR(self);
}

/***** Methods *****/
mp_obj_t BreakoutMatrix11x7_set_pixel(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args) {
    enum { ARG_self, ARG_x, ARG_y, ARG_val };
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_col, MP_ARG_REQUIRED | MP_ARG_INT },
        { MP_QSTR_row, MP_ARG_REQUIRED | MP_ARG_INT },
        { MP_QSTR_val, MP_ARG_REQUIRED | MP_ARG_INT },
    };

    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all(n_args, pos_args, kw_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);
    
    breakout_matrix11x7_BreakoutMatrix11x7_obj_t *self = MP_OBJ_TO_PTR2(args[ARG_self].u_obj, breakout_matrix11x7_BreakoutMatrix11x7_obj_t);

    int x = args[ARG_x].u_int;
    int y = args[ARG_y].u_int;
    int val = args[ARG_val].u_int;

    if(x < 0 || x >= BreakoutMatrix11x7::WIDTH || y < 0 || y >= BreakoutMatrix11x7::HEIGHT)
        mp_raise_ValueError("x or y out of range.");
    else {
        if(val < 0 || val > 255)
            mp_raise_ValueError("val out of range. Expected 0 to 255");
        else
            self->breakout->set_pixel(x, y, val);
    }

    return mp_const_none;
}

mp_obj_t BreakoutMatrix11x7_update(mp_obj_t self_in) {
    breakout_matrix11x7_BreakoutMatrix11x7_obj_t *self = MP_OBJ_TO_PTR2(self_in, breakout_matrix11x7_BreakoutMatrix11x7_obj_t);
    self->breakout->update();

    return mp_const_none;
}

mp_obj_t BreakoutMatrix11x7_clear(mp_obj_t self_in) {
    breakout_matrix11x7_BreakoutMatrix11x7_obj_t *self = MP_OBJ_TO_PTR2(self_in, breakout_matrix11x7_BreakoutMatrix11x7_obj_t);
    self->breakout->clear();

    return mp_const_none;
}
}