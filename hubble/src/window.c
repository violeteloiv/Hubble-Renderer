#include "hubble/window.h"

#include <stdlib.h>

window_t* init_window(uint32_t p_width, uint32_t p_height, const char* p_name) {
    window_t* window = (window_t*)calloc(1, sizeof(window_t));

    window->width = p_width;
    window->height = p_height;
    window->name = p_name;
    window->handle = NULL;

    return window;
}

int window_should_close(window_t* p_window) {
    return glfwWindowShouldClose(p_window->handle);
}

void window_poll_events() {
    glfwPollEvents();
}

void destroy_window(window_t* p_window) {
    glfwDestroyWindow(p_window->handle);
    p_window->handle = NULL;

    free(p_window);
}