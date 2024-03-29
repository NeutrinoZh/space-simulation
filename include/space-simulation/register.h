#pragma once
#include <utils/utils.h>

namespace space {

struct Particle {
    static constexpr float size = 2.f;

    glm::dvec2 position = {0, 0};
    glm::dvec2 velocity = {0, 0};
    glm::dvec2 acceleration = {0, 0};
};

class ParticleRegister {
private:
    std::vector<Particle> m_particles;

    static ParticleRegister s_Instance;

public:
    static void setCapacity(size_t size);
    static void spawnParticle(glm::dvec2 _position);
    static Particle& getParticleById(uint _id);

    inline auto begin() {
        return m_particles.begin();
    }

    inline auto end() {
        return m_particles.end();
    }

    static inline ParticleRegister& singlton() {
        return s_Instance;
    }
};

} // namespace space