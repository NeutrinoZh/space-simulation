#include "space-simulation/camera.h"
#include "space-simulation/default-res.h"
#include "space-simulation/register.h"
#include "space-simulation/renderer.h"
#include "space-simulation/simulation.h"

#include <GL/gl.h>
#include <window/window.h>

namespace space {

static const int c_numParticles = 2500;

using namespace wind;

class CameraControll {
private:
    glm::vec2 mouseDownPosition = {};
    glm::vec2 mouseDownCamera = {};

public:
    void update() {
        if (Mouse::isButtonDown(GLFW_MOUSE_BUTTON_LEFT)) {
            mouseDownPosition = Mouse::position();
            mouseDownCamera = Camera::getPosition();
        }

        // clang-format off
        if (Mouse::isButton(GLFW_MOUSE_BUTTON_LEFT))
            Camera::setPosition({
                mouseDownCamera.x + (Mouse::position().x - mouseDownPosition.x) * Camera::getScope(),
                mouseDownCamera.y - (Mouse::position().y - mouseDownPosition.y) * Camera::getScope()
            });
        // clang-format on

        Camera::setScope(Camera::getScope() * 0.05f * Mouse::yScroll());
    }
};

} // namespace space

int main() {
    using namespace space;

    // Some initilizatoin

    Window::init([](Window::Config* self) {
        self->title = "Space";
        self->fullScreen = false;
        self->size = {1920, 1080};
    });

    DefaultRes::load();

    Camera::setOrtho(Window::size());

    // Application components
    CameraControll cameraControll;
    PhysicsSimulation simulation(c_numParticles);
    ParticleRenderer renderer(DefaultRes::getCircle()->vertices,
                              DefaultRes::getCircle()->indices,
                              DefaultRes::getCircle()->uv, c_numParticles);

    // Main loop
    while (Window::update()) {
        if (Keyboard::isKeyDown(GLFW_KEY_ESCAPE))
            Window::close();

        // Update all aplication components
        cameraControll.update();
        simulation.update();

        // Draw
        Camera::clear({0.1f, 0.1f, 0.1f, 1.f});

        for (int i = 0; i < c_numParticles; ++i)
            renderer.setPosition(i,
                                 ParticleRegister::getParticleById(i).position);
        renderer.draw(Camera::getProj(), Camera::getView());

        Window::show();
    }

    DefaultRes::free();

    return 0;
}