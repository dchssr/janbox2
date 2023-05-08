#include <janet.h>
#include "termbox2/termbox2.h"


void jb2_error_check(int result) {
  switch (result) {
  case TB_ERR_INIT_ALREADY:
    janet_panic("termbox is already initialized");
    break;
  case TB_ERR_NOT_INIT:
    janet_panic("termbox is not initialized");
    break;
  }
}

static Janet
cfun_tb_init
(int32_t argc, Janet *argv) {
  janet_fixarity(argc, 0);

  int result = tb_init();
  jb2_error_check(result);

  return janet_wrap_integer(result);
}

static Janet
cfun_tb_shutdown
(int32_t argc, Janet *argv) {
  janet_fixarity(argc, 0);

  int result = tb_shutdown();
  jb2_error_check(result);

  return janet_wrap_integer(result);
}

static JanetReg cfuns[] = {
  {"init"    , cfun_tb_init    , "(init)\n\nInitialize Termbox."},
  {"shutdown", cfun_tb_shutdown, "(shutdown)\n\nShut down Termbox."},
  {NULL, NULL, NULL},
};

JANET_MODULE_ENTRY(JanetTable *env) {
  janet_cfuns(env, "janbox2", cfuns);
}
