#include <gs/gs.h>

void init() {}

void update()
{
  if (gs_platform_key_pressed(GS_KEYCODE_ESC))
  {
    gs_quit();
  }
}

gs_app_desc_t gs_main(int32_t argc, char **argv)
{
  return (gs_app_desc_t){
      .init = init,
      .update = update,
      .window_title = "GST",
  };
}
