#include <utils/utils.h>

namespace space {

struct Particle {
    glm::dvec2 position;
    double weight;
    double size;

    glm::dvec2 velocity = {0, 0};
    glm::dvec2 acceleration = {0, 0};
};

class ParticleRegister {
private:
    std::vector<Particle> m_particles;

    static ParticleRegister s_Instance;

public:
    static void setCapacity(size_t size) {
        s_Instance.m_particles.reserve(size + 1);
    }

    static void spawnParticle(glm::dvec2 _position, double _weight) {
        s_Instance.m_particles.push_back({_position, _weight, 1.f});
    }

    auto begin() {
        return m_particles.begin();
    }

    auto end() {
        return m_particles.end();
    }

    static ParticleRegister& singlton() {
        return s_Instance;
    }
};

} // namespace space