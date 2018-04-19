#include <mruby.h>
#include <mruby/error.h>
#include <mruby/variable.h>
#include <esp_err.h>

#define mrb_esp32_eError(mrb) (mrb_class_get_under(mrb, mrb_module_get(mrb, "ESP32"), "Error"))

MRB_API mrb_noreturn void mrb_raise_esp32_err(mrb_state *mrb, esp_err_t code) {
  char err_msg[20];
  mrb_value exc = mrb_exc_new_str(mrb, mrb_esp32_eError(mrb), mrb_str_new_cstr(mrb, esp_err_to_name_r(code, err_msg, sizeof(err_msg))));
  mrb_iv_set(mrb, exc, mrb_intern_lit(mrb, "code"), mrb_fixnum_value((mrb_int)code));
  mrb_exc_raise(mrb, exc);
}

MRB_API mrb_value mrb_esp32_err_code(mrb_state *mrb, mrb_value self) {
  return mrb_iv_get(mrb, self, mrb_intern_lit(mrb, "code"));
}

void mrb_esp32_ext_esp_err_gem_init(mrb_state *mrb) {
  struct RClass *mrb_esp32, *mrb_esp32_err;

  /* ESP32 */
  mrb_esp32 = mrb_define_module(mrb, "ESP32");

  /* ESP32::Error */
  mrb_esp32_err = mrb_define_class_under(mrb, mrb_esp32, "Error", mrb->eStandardError_class);
  mrb_define_method(mrb, mrb_esp32_err, "code", mrb_esp32_err_code, MRB_ARGS_NONE());

  /* esp_err_t */
  mrb_define_const(mrb, mrb_esp32, "OK", mrb_fixnum_value(ESP_OK));
  mrb_define_const(mrb, mrb_esp32, "FAIL", mrb_fixnum_value(ESP_FAIL));
  mrb_define_const(mrb, mrb_esp32, "ERR_NO_MEM", mrb_fixnum_value(ESP_ERR_NO_MEM));
  mrb_define_const(mrb, mrb_esp32, "ERR_INVALID_ARG", mrb_fixnum_value(ESP_ERR_INVALID_ARG));
  mrb_define_const(mrb, mrb_esp32, "ERR_INVALID_STATE", mrb_fixnum_value(ESP_ERR_INVALID_STATE));
  mrb_define_const(mrb, mrb_esp32, "ERR_INVALID_SIZE", mrb_fixnum_value(ESP_ERR_INVALID_SIZE));
  mrb_define_const(mrb, mrb_esp32, "ERR_NOT_FOUND", mrb_fixnum_value(ESP_ERR_NOT_FOUND));
  mrb_define_const(mrb, mrb_esp32, "ERR_NOT_SUPPORTED", mrb_fixnum_value(ESP_ERR_NOT_SUPPORTED));
  mrb_define_const(mrb, mrb_esp32, "ERR_TIMEOUT", mrb_fixnum_value(ESP_ERR_TIMEOUT));
  mrb_define_const(mrb, mrb_esp32, "ERR_INVALID_RESPONSE", mrb_fixnum_value(ESP_ERR_INVALID_RESPONSE));
  mrb_define_const(mrb, mrb_esp32, "ERR_INVALID_CRC", mrb_fixnum_value(ESP_ERR_INVALID_CRC));
  mrb_define_const(mrb, mrb_esp32, "ERR_INVALID_VERSION", mrb_fixnum_value(ESP_ERR_INVALID_VERSION));
  mrb_define_const(mrb, mrb_esp32, "ERR_INVALID_MAC", mrb_fixnum_value(ESP_ERR_INVALID_MAC));
  mrb_define_const(mrb, mrb_esp32, "ERR_WIFI_BASE", mrb_fixnum_value(ESP_ERR_WIFI_BASE));
}

void mrb_esp32_ext_esp_err_gem_final(mrb_state* mrb) {
}
