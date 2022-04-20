#include "drivers/icp10125/icp10125.hpp"

#define MP_OBJ_TO_PTR2(o, t) ((t *)(uintptr_t)(o))

using namespace pimoroni;

extern "C" {
#include "breakout_icp10125.h"
#include "pimoroni_i2c.h"

/***** I2C Struct *****/
typedef struct _PimoroniI2C_obj_t {
    mp_obj_base_t base;
    I2C *i2c;
} _PimoroniI2C_obj_t;

/***** Variables Struct *****/
typedef struct _breakout_icp10125_BreakoutICP10125_obj_t {
    mp_obj_base_t base;
    ICP10125 *breakout;
} breakout_icp10125_BreakoutICP10125_obj_t;

/***** Print *****/
void BreakoutICP10125_print(const mp_print_t *print, mp_obj_t self_in, mp_print_kind_t kind) {
    (void)kind; //Unused input parameter
    (void)self_in;
    // breakout_icp10125_BreakoutICP10125_obj_t *self = MP_OBJ_TO_PTR2(self_in, breakout_icp10125_BreakoutICP10125_obj_t);
    // ICP10125* breakout = self->breakout;
    // TODO put something useful here? There's no point printing I2C info since that's handled by the I2C object now
    mp_print_str(print, "BreakoutICP10125()");
}

/***** Constructor *****/
mp_obj_t BreakoutICP10125_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *all_args) {
    breakout_icp10125_BreakoutICP10125_obj_t *self = nullptr;

    enum { ARG_i2c };
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_i2c, MP_ARG_OBJ, {.u_obj = nullptr} }
    };

    // Parse args.
    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all_kw_array(n_args, n_kw, all_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

    // Get I2C bus.
    if(!MP_OBJ_IS_TYPE(args[ARG_i2c].u_obj, &PimoroniI2C_type)) {
        mp_raise_ValueError(MP_ERROR_TEXT("BreakoutICP10125: Bad i2C object"));
        return mp_const_none;
    }

    _PimoroniI2C_obj_t *i2c = (_PimoroniI2C_obj_t *)MP_OBJ_TO_PTR(args[ARG_i2c].u_obj);

    self = m_new_obj(breakout_icp10125_BreakoutICP10125_obj_t);
    self->base.type = &breakout_icp10125_BreakoutICP10125_type;

    self->breakout = new ICP10125(i2c->i2c);

    if(!self->breakout->init()) {
        mp_raise_msg(&mp_type_RuntimeError, "BreakoutICP10125: breakout not found when initialising");
    }

    return MP_OBJ_FROM_PTR(self);
}

/***** Methods *****/

mp_obj_t BreakoutICP10125_measure(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args) {
    enum { ARG_self, ARG_command };
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_command, MP_ARG_INT, {.u_int = NORMAL} },
    };

    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all(n_args, pos_args, kw_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

    breakout_icp10125_BreakoutICP10125_obj_t *self = MP_OBJ_TO_PTR2(args[ARG_self].u_obj, breakout_icp10125_BreakoutICP10125_obj_t);
    auto reading = self->breakout->measure((ICP10125::meas_command)args[ARG_command].u_int);

    mp_obj_t tuple[3];
    tuple[0] = mp_obj_new_float(reading.temperature);
    tuple[1] = mp_obj_new_float(reading.pressure);
    tuple[2] = mp_obj_new_int(reading.status);
    return mp_obj_new_tuple(3, tuple);
}

mp_obj_t BreakoutICP10125_soft_reset(mp_obj_t self_in) {
    breakout_icp10125_BreakoutICP10125_obj_t *self = MP_OBJ_TO_PTR2(self_in, breakout_icp10125_BreakoutICP10125_obj_t);
    self->breakout->reset();

    return mp_const_none;
}

}