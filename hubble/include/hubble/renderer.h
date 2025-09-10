#ifndef HUBBLE_RENDERER_H_DEFINED
#define HUBBLE_RENDERER_H_DEFINED

#include "hubble/window.h"

typedef struct {
    window_t* window;
} renderer_t;

renderer_t* init_renderer(window_t* p_window);

void destroy_renderer(renderer_t* p_renderer);

#endif // HUBBLE_RENDERER_H_DEFINED