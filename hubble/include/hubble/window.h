#ifndef HUBBLE_WINDOW_H_DEFINED
#define HUBBLE_WINDOW_H_DEFINED

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdint.h>

typedef struct {
    uint32_t width;
    uint32_t height;
    char* name;
    GLFWwindow* handle;
} window_t;

window_t* init_window(uint32_t p_width, uint32_t p_height, const char* p_name);

int window_should_close(window_t* p_window);

void window_poll_events();
void destroy_window(window_t* p_window);

#endif // HUBBLE_WINDOW_H_DEFINED