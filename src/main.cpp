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

    while (Window::update()) {
        if (Keyboard::isKeyDown(GLFW_KEY_ESCAPE))
            Window::close();

        Window::show();
    }

    return 0;
}