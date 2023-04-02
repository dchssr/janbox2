#include <janet.h>


static Janet
cfun_hello_world
(int32_t argc,
 Janet *argv)
{
  janet_fixarity(argc, 0);
  printf("Hello, World!\n");
  return janet_wrap_nil();
}

static JanetReg cfuns[] = {
  {"hello-world", cfun_hello_world, "(hello-world)\n\nPrint your greeting."},
  {NULL, NULL, NULL},
};

JANET_MODULE_ENTRY(JanetTable *env) {
  janet_cfuns(env, "testing", cfuns);
}
