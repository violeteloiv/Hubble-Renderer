#include "hubble/renderer.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

renderer_t* init_renderer(window_t* p_window, renderer_type p_type) {
    renderer_t* renderer = (renderer_t*)calloc(1, sizeof(renderer_t));

    glfwInit();

    switch (p_type) {
        case HUBBLE_VULKAN_API: {
            // GLFW was originally designed to initialize an OpenGL context, but here we tell them not to.
            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
            break;
        }
        case HUBBLE_NO_RENDERER_API:
        default: {
            fprintf(stderr, "ERROR: init_renderer - NO RENDERER API SPECIFIED\n");
            exit(1);
        }
    }
    
    // TODO: Handle resizing windows later
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    p_window->handle = glfwCreateWindow(p_window->width, p_window->height, p_window->name, NULL, NULL);

    renderer->window = p_window;
    renderer->type = p_type;

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, NULL);
    fprintf(stdout, "Extension Count: %d\n", extensionCount);

    return renderer;
}

void destroy_renderer(renderer_t* p_renderer) {
    destroy_window(p_renderer->window);
    free(p_renderer);

    glfwTerminate();
}