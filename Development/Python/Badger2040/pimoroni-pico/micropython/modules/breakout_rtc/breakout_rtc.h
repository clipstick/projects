// Include MicroPython API.
#include "py/runtime.h"
//#include "py/objstr.h"

/***** Constants *****/
enum TCR {
    MP_TCR_3K  = 0b00,     //Trickle Charge Resistor 3kOhm
    MP_TCR_5K  = 0b01,     //Trickle Charge Resistor 5kOhm
    MP_TCR_9K  = 0b10,     //Trickle Charge Resistor 9kOhm
    MP_TCR_15K = 0b11,     //Trickle Charge Resistor 15kOhm
};

/***** Extern of Class Definition *****/
extern const mp_obj_type_t breakout_rtc_BreakoutRTC_type;

/***** Extern of Class Methods *****/
extern void BreakoutRTC_print(const mp_print_t *print, mp_obj_t self_in, mp_print_kind_t kind);
extern mp_obj_t BreakoutRTC_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *all_args);

extern mp_obj_t BreakoutRTC_reset(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_setup(mp_obj_t self_in);

extern mp_obj_t BreakoutRTC_set_time(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
extern mp_obj_t BreakoutRTC_set_seconds(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
extern mp_obj_t BreakoutRTC_set_minutes(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
extern mp_obj_t BreakoutRTC_set_hours(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
extern mp_obj_t BreakoutRTC_set_weekday(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
extern mp_obj_t BreakoutRTC_set_date(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
extern mp_obj_t BreakoutRTC_set_month(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
extern mp_obj_t BreakoutRTC_set_year(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
extern mp_obj_t BreakoutRTC_set_to_compiler_time(mp_obj_t self_in);

extern mp_obj_t BreakoutRTC_update_time(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_string_date_usa(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_string_date(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_string_time(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_string_time_stamp(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_get_seconds(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_get_minutes(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_get_hours(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_get_weekday(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_get_date(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_get_month(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_get_year(mp_obj_t self_in);

extern mp_obj_t BreakoutRTC_is_12_hour(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_is_pm(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_set_12_hour(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_set_24_hour(mp_obj_t self_in);

extern mp_obj_t BreakoutRTC_set_unix(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
extern mp_obj_t BreakoutRTC_get_unix(mp_obj_t self_in);

extern mp_obj_t BreakoutRTC_enable_alarm_interrupt(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
extern mp_obj_t BreakoutRTC_disable_alarm_interrupt(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_read_alarm_interrupt_flag(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_clear_alarm_interrupt_flag(mp_obj_t self_in);

extern mp_obj_t BreakoutRTC_set_timer(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
extern mp_obj_t BreakoutRTC_get_timer_count(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_enable_timer(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_disable_timer(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_enable_timer_interupt(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_disable_timer_interrupt(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_read_timer_interrupt_flag(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_clear_timer_interrupt_flag(mp_obj_t self_in);

extern mp_obj_t BreakoutRTC_enable_periodic_update_interrupt(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
extern mp_obj_t BreakoutRTC_disable_periodic_update_interrupt(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_read_periodic_update_interrupt_flag(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_clear_periodic_update_interrupt_flag(mp_obj_t self_in);

extern mp_obj_t BreakoutRTC_enable_trickle_charge(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
extern mp_obj_t BreakoutRTC_disable_trickle_charge(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_set_backup_switchover_mode(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);

extern mp_obj_t BreakoutRTC_enable_clock_out(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
extern mp_obj_t BreakoutRTC_enable_interrupt_controlled_clockout(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
extern mp_obj_t BreakoutRTC_disable_clock_out(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_read_clock_output_interrupt_flag(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_clear_clock_output_interrupt_flag(mp_obj_t self_in);

extern mp_obj_t BreakoutRTC_status(mp_obj_t self_in);
extern mp_obj_t BreakoutRTC_clear_interrupts(mp_obj_t self_in);