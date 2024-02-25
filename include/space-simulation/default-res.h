#pragma once
#include <space-simulation/mesh.h>
#include <space-simulation/shader.h>

namespace space {

class DefaultRes {
public:
    static void load();
    static void free();

    static Shader* getParticleShader();
    static Mesh* getCircle();
};

} // namespace space