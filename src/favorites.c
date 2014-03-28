#include "pebble.h"

static void init();
static void deinit();
static void loop();

static Window *window;
static TextLayer *text_layer;

void face_favorites(Window *_window)
{
  window = _window;

  init();
  loop();
  deinit();
}

static void init()
{
  text_layer = text_layer_create(GRect(0, 0, 144, 168));
  text_layer_set_background_color(text_layer, GColorClear);
  text_layer_set_text_color(text_layer, GColorBlack);
   
  layer_add_child(window_get_root_layer(window), (Layer*) text_layer);
  text_layer_set_text(text_layer, "Anything you want, as long as it is in quotes!");
}
 
static void deinit()
{
  text_layer_destroy(text_layer);
}

static void loop()
{
  app_event_loop();
}