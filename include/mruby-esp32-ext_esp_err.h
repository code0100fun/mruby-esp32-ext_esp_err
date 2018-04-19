#include <mruby.h>

MRB_API mrb_noreturn void mrb_raise_esp32_err(mrb_state *mrb, esp_err_t code);
