#include "hubble/window.h"
#include "hubble/renderer.h"

int main(void) {
    window_t* window = init_window(800, 600, "Vulkan Window");
    renderer_t* renderer = init_renderer(window);

    while (!window_should_close(window)) {
        window_poll_events();
    }

    destroy_renderer(renderer);
    return 0;
}