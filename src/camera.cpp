#include "space-simulation/camera.h"

namespace space {

namespace {

static float m_scope = 1.f;
static glm::vec2 m_position = glm::vec2();

static glm::ivec2 m_projectionPortSize = glm::ivec2();
static glm::mat4 m_orthoMatrix = glm::mat4(1);
static glm::mat4 m_viewMatrix = glm::mat4(1);

} // namespace

void Camera::clear(glm::vec4 color) {
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Camera::setOrtho(glm::ivec2 _size, float _scope) {
    m_projectionPortSize = _size;
    m_scope = _scope;

    // clang-format off
    m_orthoMatrix = glm::ortho(
        -static_cast<float>(_size.x / 2  * _scope), static_cast<float>(_size.x / 2  * _scope),
        -static_cast<float>(_size.y / 2  * _scope), static_cast<float>(_size.y / 2 * _scope),
        -1.f, 1.f);
    // clang-format on
}

void Camera::setScope(float _scope) {
    setOrtho(m_projectionPortSize, _scope);
}

float Camera::getScope() {
    return m_scope;
}

void Camera::setPosition(glm::vec2 _position) {
    m_position = _position;

    m_viewMatrix = glm::mat4(1);
    m_viewMatrix = glm::translate(m_viewMatrix, glm::vec3(_position, 0));
}

glm::vec2 Camera::getPosition() {
    return m_position;
}

glm::mat4& Camera::getProj() {
    return m_orthoMatrix;
}

glm::mat4& Camera::getView() {
    return m_viewMatrix;
}

} // namespace space