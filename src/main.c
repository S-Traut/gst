/*================================================================
    * Copyright: 2020 John Jackson
    * gs_static_lib

    This example compiles gunslinger as a static library then
    links it against the example program to run.

    Press `esc` to exit the application.
================================================================*/

#include <gs/gs.h>
#include <gs/util/gs_idraw.h>

gs_command_buffer_t cb = {0};
gs_immediate_draw_t gsi = {0};

void init() {
  cb = gs_command_buffer_new();
  gsi = gs_immediate_draw_new(gs_platform_main_window());
}

void update() {
  if (gs_platform_key_pressed(GS_KEYCODE_ESC)) {
    gs_quit();
  }

  gs_vec2 ws = gs_platform_window_sizev(gs_platform_main_window());

  const float t = gs_platform_elapsed_time() * 0.0001f;
  gsi_camera3D(&gsi, ws.x, ws.y);
  gsi_rotatefv(&gsi, gs_deg2rad(90.f), GS_ZAXIS);
  gsi_rotatefv(&gsi, t, GS_YAXIS);
  gsi_sphere(&gsi, 0.f, 0.f, 0.f, 1.f, 50, 150, 200, 50,
             GS_GRAPHICS_PRIMITIVE_LINES);
  gsi_camera2D(&gsi, ws.x, ws.y);
  gsi_text(&gsi, ws.x * 0.5f - 70.f, ws.y * 0.5f, "Hello, Gunslinger.", NULL,
           false, 255, 255, 255, 255);
  gsi_render_pass_submit(&gsi, &cb, gs_color(10, 10, 10, 255));

  // Submit command buffer for GPU
  gs_graphics_submit_command_buffer(&cb);
}

gs_app_desc_t gs_main(int32_t argc, char **argv) {
  return (gs_app_desc_t){.window_width = 800,
                         .window_height = 600,
                         .init = init,
                         .update = update,
                         .window_title = "GST",
                         .enable_vsync = true};
}
