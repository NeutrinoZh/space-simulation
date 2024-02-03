#pragma once

// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

#include <utils/utils.h>
#include <window/window.h>

namespace space {

class Camera {
public:
    static void clear(glm::vec4 color);
    static void setOrtho(glm::ivec2 size, float scope = 1.f);
    static void setPosition(glm::vec2 position);
    static void setScope(float scope);
};

} // namespace space