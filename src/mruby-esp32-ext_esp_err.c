#include <mruby.h>
#include <esp_err.h>

void mrb_esp32_ext_esp_err_gem_init(mrb_state* mrb) {
  struct RClass *mrb_esp32, *mrb_esp32_i2c, *mrb_esp32_intr, *mrb_i2c_intr_handle, *mrb_esp32_i2c_config, *mrb_esp32_i2c_cmd_handle;

  /* ESP32 */
  mrb_esp32 = mrb_define_module(mrb, "ESP32");

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
