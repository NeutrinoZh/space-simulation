#include "space-simulation/camera.h"
#include <window/window.h>

namespace space {

using namespace wind;

}

int main() {
    using namespace space;

    Window::init([](Window::Config* self) {
        self->title = "Space";
        self->fullScreen = false;
        self->size = {1920, 1080};
    });

    Camera::setOrtho(Window::size());

    while (Window::update()) {
        if (Keyboard::isKeyDown(GLFW_KEY_ESCAPE))
            Window::close();

        Camera::clear({0.1f, 0.1f, 0.1f, 1.f});
        Window::show();
    }

    return 0;
}