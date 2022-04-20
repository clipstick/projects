// Include MicroPython API.
#include "py/runtime.h"
#include "drivers/bme68x/src/bme68x_defs.h"

/***** Constants *****/

/***** Extern of Class Definition *****/
extern const mp_obj_type_t breakout_bme68x_BreakoutBME68X_type;

/***** Extern of Class Methods *****/
extern void BreakoutBME68X_print(const mp_print_t *print, mp_obj_t self_in, mp_print_kind_t kind);
extern mp_obj_t BreakoutBME68X_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *all_args);
extern mp_obj_t BreakoutBME68X_read(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
extern mp_obj_t BreakoutBME68X_configure(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);