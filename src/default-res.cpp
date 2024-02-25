#include <cmath>
#include <glm/ext/scalar_constants.hpp>
#include <space-simulation/default-res.h>

namespace space {

static Shader* m_defaultParticleShader = nullptr;
static Mesh* m_defaultCircle = nullptr;

void DefaultRes::load() {
    // clang-format off

    m_defaultParticleShader = new Shader(
        R"(
            #version 330 core
            layout (location = 0) in vec3 aPos;
            layout (location = 1) in vec2 aTexCoords;
            layout (location = 3) in mat4 model;

            uniform mat4 view;
            uniform mat4 projection;

            out vec2 TexCoord;

            void main() {
                gl_Position = projection * view * model * vec4(aPos, 1.0);
                TexCoord = aTexCoords;
            }
        )",
        R"(
            #version 330 core
            
            out vec4 FragColor;
            in vec2 TexCoord;
            
            uniform vec4 color;

            void main() {
                FragColor = color; 
            }
        )"
    );

    {
        std::vector<glm::vec3> vertices;
        std::vector<unsigned int> indices;
        std::vector<glm::vec2> uv;

        const int numSegments = 12;
        const float segmentAngle = 2.f * glm::pi<float>() / numSegments;

        vertices.push_back({0, 0, 0});
        uv.push_back({0.5f, 0.5f});

        for (int i = 0; i < numSegments; ++i) {
            float angle = i * segmentAngle;
            float c = cosf(angle),
                  s = sinf(angle);

            vertices.push_back({ c, s, 0.f });
            uv.push_back({
                0.5f + 0.5f * c,
                0.5f + 0.5f * s
            });
        }

        for (int i = 1; i <= numSegments; ++i) {
            indices.push_back(0);
            indices.push_back(i);
            indices.push_back((i % numSegments) + 1);
        }

        m_defaultCircle = new Mesh(vertices, indices, uv);
    }

    // clang-format on
}

void DefaultRes::free() {
    delete m_defaultParticleShader;
    delete m_defaultCircle;
}

Mesh* DefaultRes::getCircle() {
    return m_defaultCircle;
}

Shader* DefaultRes::getParticleShader() {
    return m_defaultParticleShader;
}

} // namespace space