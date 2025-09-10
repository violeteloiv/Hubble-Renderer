#include "hubble/renderer.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

renderer_t* init_renderer(window_t* p_window) {
    renderer_t* renderer = (renderer_t*)calloc(1, sizeof(renderer_t));

    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    p_window->handle = glfwCreateWindow(p_window->width, p_window->height, p_window->name, NULL, NULL);

    renderer->window = p_window;

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, NULL);
    printf("%d extensions supported\n", extensionCount);

    return renderer;
}

void destroy_renderer(renderer_t* p_renderer) {
    destroy_window(p_renderer->window);
    free(p_renderer);

    glfwTerminate();
}