#include <space-simulation/register.h>
#include <space-simulation/simulation.h>

namespace space {

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

PhysicsSimulation::PhysicsSimulation(int _numParticles) noexcept {
    ParticleRegister::setCapacity(_numParticles);
    for (int i = 0; i < _numParticles; ++i) {
        glm::dvec2 position{static_cast<double>(-10000 + rand() % 20000),
                            static_cast<double>(-10000 + rand() % 20000)};
        ParticleRegister::spawnParticle(position);
    }
}

} // namespace space