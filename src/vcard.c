#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"

// #define APPTITLE "Visitenkarte"
#define APPTITLE "vcard"

#define MY_UUID { 0x10, 0x7F, 0x87, 0x5B, 0x50, 0xCF, 0x4B, 0xF7, 0xA9, 0x0C, 0x0C, 0xAE, 0xBE, 0xA8, 0xBC, 0xB2 }
PBL_APP_INFO(MY_UUID,
             APPTITLE, "Gerald Schneider",
             0, 1, /* App version */
             DEFAULT_MENU_ICON,
             APP_INFO_STANDARD_APP);

Window window;
Layer layer;
BmpContainer image;

void layer_update_callback(Layer *me, GContext* ctx) {
  (void)me;
  (void)ctx;

  GRect destination = layer_get_frame(&image.layer.layer);

  destination.origin.y = 9;
  destination.origin.x = 7;

  graphics_draw_bitmap_in_rect(ctx, &image.bmp, destination);
}

void handle_init(AppContextRef ctx) {
  (void)ctx;

  window_init(&window, APPTITLE);
  window_stack_push(&window, true /* Animated */);

  layer_init(&layer, window.layer.frame);
  layer.update_proc = &layer_update_callback;
  layer_add_child(&window.layer, &layer);

  resource_init_current_app(&VERSION);
  bmp_init_container(RESOURCE_ID_QRCODE, &image);
}

void handle_deinit(AppContextRef ctx) {
  (void)ctx;

  bmp_deinit_container(&image);
}

void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init,
    .deinit_handler = &handle_deinit
  };
  app_event_loop(params, &handlers);
}
