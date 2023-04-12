#include <janet.h>
#include "termbox2/termbox2.h"


static Janet
cfun_tb_init
(int32_t argc, Janet *argv) {
  janet_fixarity(argc, 0);
  return janet_wrap_integer(tb_init());
}

static Janet
cfun_tb_shutdown
(int32_t argc, Janet *argv) {
  janet_fixarity(argc, 0);
  return janet_wrap_integer(tb_shutdown());
}

static JanetReg cfuns[] = {
  {"init"    , cfun_tb_init    , "(init)\n\nInitialize Termbox."},
  {"shutdown", cfun_tb_shutdown, "(shutdown)\n\nShut down Termbox."},
  {NULL, NULL, NULL},
};

JANET_MODULE_ENTRY(JanetTable *env) {
  janet_cfuns(env, "janbox2", cfuns);
}
