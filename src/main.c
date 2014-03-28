#include "pebble.h"
#include "utils.h"
#include "favorites.h"
#include "map.h"

static void init();
static void deinit();
static void face_next();
static void face_destroy();
static void window_load();
static void window_unload();

static void click_config_provider(void *context);

static Window *window;
static FaceDeInit face_deinit = 0;

int main(void)
{
  init();
  face_next();
  app_event_loop();
  deinit();
}

static void init()
{
  //Initialize the app elements here!
  window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });

  window_stack_push(window, true /* Animated */);

  window_set_click_config_provider(window, click_config_provider);

  APP_LOG(APP_LOG_LEVEL_DEBUG, "Main.init(): Exit");
}
 
static void deinit()
{
  //De-initialize elements here to save memory
  face_destroy();

  window_destroy(window);
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Main.deinit(): Exit");
}

static void window_load(Window *window)
{
  //We will add the creation of the Window's elements here soon!
}
 
static void window_unload(Window *window)
{
  //We will safely destroy the Window's elements here!
}

void face_destroy() {
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Main.face_destro(): Enter");
  if (face_deinit != 0) face_deinit();
}

void face_next() {
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Main.faces_loop(): Enter");
  static int _currentFace = 0;

  face_destroy();

  switch (_currentFace) {
    case 0: face_deinit = face_favorites(window); break;
    case 1: face_deinit = face_map(window); break;
  }

  _currentFace = (_currentFace + 1) % 2;
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Main.faces_loop(): Next Face");
}

static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, face_next);
}