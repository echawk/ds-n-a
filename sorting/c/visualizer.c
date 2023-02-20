#define VISUALIZE
#define _DEFAULT_SOURCE // gets rid of usleep() warnings
#include "array.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define W_WIDTH 800
#define W_HEIGHT 600

#define SSECONDS(x) ((int)(x * 1000000))

int bar_w;
double bar_scale;

// SDL window & renderer
void *window;
void *renderer;

typedef struct {
  uint8_t r, g, b;
} rgb_T;

const rgb_T white = {.r = 255, .g = 255, .b = 255};
const rgb_T black = {.r = 0, .g = 0, .b = 0};
const rgb_T red = {.r = 255, .g = 20, .b = 20};
const rgb_T green = {.r = 20, .g = 255, .b = 20};

// Graphical Rectangle - assumed to be drawn from the bottom of the screen,
// hence no 'y'
typedef struct {
  int x;
  int height, width;
  rgb_T color;
} Rect_T;

Rect_T make_Rect(int x, int y, int height, int width, rgb_T color) {
  return (Rect_T){.x = x, .height = height, .width = width, .color = color};
}

// FIXME: When drawing, there is a big black bar along the right hand side
// -- need to figure out how to get it to take up the entire window.
// Draws, but does not present a rectangle 'r'
void draw_Rect(Rect_T r) {
  int i, j;
  SDL_SetRenderDrawColor(renderer, r.color.r, r.color.g, r.color.b, 255);
  for (i = r.x; i < r.x + r.width; i++) {
    for (j = W_HEIGHT; j > W_HEIGHT - r.height; j--) {
      SDL_RenderDrawPoint(renderer, i, j);
    }
  }
  SDL_SetRenderDrawColor(renderer, black.r, black.g, black.b, 255);
}

// Simple Arrays for Rect_T, same as 'Arr_T' in array.h
typedef struct RArr {
  int size;
  Rect_T *arr;
} RArr_T;

RArr_T make_RArr(int size) {
  return (RArr_T){.size = size, .arr = calloc(size, sizeof(RArr_T))};
}

// Needed globally for the 'swap' function.
RArr_T R;

void populate_RArr(RArr_T R, Arr_T A, int bar_w, double bar_scale,
                   rgb_T color) {
  int i;
  for (i = 0; i < R.size; i++) {
    R.arr[i] = (Rect_T){.x = i * bar_w,
                        .width = bar_w,
                        .height = (int)A.arr[i] * bar_scale,
                        .color = color};
  }
}

// Draws and presents all of the rectangles in an RArr 'R'
void show_RArr(RArr_T R) {
  int i;
  for (i = 0; i < R.size; i++) {
    draw_Rect(R.arr[i]);
  }
  SDL_RenderPresent(renderer);
}

// IMPORTANT
// This is crucial to this program working. We override the 'swap' function.
void swap(int ind1, int ind2, Arr_T A) {
  // Should always be the same code that's in 'array.h'
  // FIXME: make the ifndef more robust in array.c && array.h so we don't
  // have to copy and paste code.
  if (A.arr[ind1] != A.arr[ind2]) {
    A.arr[ind1] = A.arr[ind1] ^ A.arr[ind2];
    A.arr[ind2] = A.arr[ind1] ^ A.arr[ind2];
    A.arr[ind1] = A.arr[ind1] ^ A.arr[ind2];
  }
  // Now the fun part - reconstruct the RArr, print it, and sleep.
  populate_RArr(R, A, bar_w, bar_scale, white);
  R.arr[ind1].color = red;
  R.arr[ind2].color = red;
  SDL_RenderClear(renderer);
  show_RArr(R);
}

int init_sdl() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "[ERR] Could not initialize sdl2: %s\n", SDL_GetError());
    return EXIT_FAILURE;
  }
  window = SDL_CreateWindow("Sorting - C", 0, 0, W_WIDTH, W_HEIGHT,
                            SDL_WINDOW_SHOWN);
  if (window == NULL) {
    fprintf(stderr, "[ERR] SDL_CreateWindow failed: %s\n", SDL_GetError());
    return EXIT_FAILURE;
  }
  renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == NULL) {
    SDL_DestroyWindow(window);
    fprintf(stderr, "[ERR] SDL_CreateRenderer failed: %s", SDL_GetError());
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

void main_sdl() {
  Arr_T A = make_Arr(300);
  sorted_populate_Arr(A);

  // Some Window math...
  bar_w = W_WIDTH / A.size;
  bar_scale = (double)W_HEIGHT / A.arr[largestIndIn_Arr(A)];
  R = make_RArr(A.size);
  populate_RArr(R, A, bar_w, bar_scale, white);

  // Begin the visualization.
  show_RArr(R);
  shuffle_Arr(A);
  sort(A); // This function is provided by one of the algorithm files.
  usleep(SSECONDS(.2));

  // And we're done.
  SDL_RenderClear(renderer);
  populate_RArr(R, A, bar_w, bar_scale, green);
  show_RArr(R);
  usleep(SSECONDS(2));
}

void exit_sdl() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

int main() {
  srand(time(NULL));
  init_sdl();
  main_sdl();
  exit_sdl();
  return 0;
}
