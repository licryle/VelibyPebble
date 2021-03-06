#include "pebble.h"
#include "favorites.h"

static void init();
static void deinit();

static Window *window;
static TextLayer *text_layer;

FaceDeInit face_favorites(Window *_window)
{
  window = _window;

  init();
  return deinit;
}

static void init()
{
  text_layer = text_layer_create(GRect(0, 0, 144, 168));
  text_layer_set_background_color(text_layer, GColorClear);
  text_layer_set_text_color(text_layer, GColorBlack);
   
  layer_add_child(window_get_root_layer(window), (Layer*) text_layer);
  text_layer_set_text(text_layer, "My favorites face!");
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Favorites.init(): Exit");
}
 
static void deinit()
{
  text_layer_destroy(text_layer);
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Favorites.deinit(): Exit");
}