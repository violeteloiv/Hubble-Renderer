#ifndef HUBBLE_RENDERER_H_DEFINED
#define HUBBLE_RENDERER_H_DEFINED

#include "hubble/window.h"

typedef enum {
    HUBBLE_VULKAN_API = 0,
    HUBBLE_NO_RENDERER_API,
} renderer_type;

typedef struct {
    window_t* window;

    renderer_type type;
} renderer_t;

renderer_t* init_renderer(window_t* p_window, renderer_type p_type);

void destroy_renderer(renderer_t* p_renderer);

#endif // HUBBLE_RENDERER_H_DEFINED