#include <space-simulation/simulation.h>

namespace space {

ParticleRegister ParticleRegister::s_Instance;

void ParticleRegister::setCapacity(size_t _size) {
    s_Instance.m_particles.reserve(_size + 1);
}

void ParticleRegister::spawnParticle(glm::dvec2 _position, double _weight) {
    s_Instance.m_particles.push_back({_position});
}

void PhysicsSimulation::update() {
    for (auto& i : ParticleRegister::singlton()) {
        i.acceleration = {};

        for (auto& j : ParticleRegister::singlton()) {
            if (&i == &j)
                continue;

            glm::dvec2 diff = j.position - i.position;
            glm::dvec2 normal = glm::normalize(diff);

            double distanceSquared = glm::dot(diff, diff);

            if (distanceSquared > pow(i.size + j.size, 2)) {
                double force = G / distanceSquared;
                i.acceleration += force * normal;
            }
        }
    }

    for (auto& i : ParticleRegister::singlton()) {
        i.velocity += i.acceleration;
        i.position += i.velocity;
    }
}

} // namespace space