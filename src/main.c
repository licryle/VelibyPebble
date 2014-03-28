#include "pebble.h"
#include "favorites.h"

static void init();
static void deinit();
static void faces_loop();
static void window_load();
static void window_unload();

static Window *window;

int main(void)
{
  init();
  faces_loop();
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
}
 
static void deinit()
{
  //De-initialize elements here to save memory
  window_destroy(window);
}

static void window_load(Window *window)
{
  //We will add the creation of the Window's elements here soon!
}
 
static void window_unload(Window *window)
{
  //We will safely destroy the Window's elements here!
}

void faces_loop() {
  int _currentFace = 0;

  while (true) {
    switch (_currentFace) {
      case 0: face_favorites(window); break;
    }

    _currentFace = _currentFace++ % 1;
  }
}