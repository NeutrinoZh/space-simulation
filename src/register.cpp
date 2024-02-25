#include <space-simulation/register.h>

namespace space {

ParticleRegister ParticleRegister::s_Instance;

void ParticleRegister::setCapacity(size_t _size) {
    s_Instance.m_particles.reserve(_size + 1);
}

void ParticleRegister::spawnParticle(glm::dvec2 _position) {
    s_Instance.m_particles.push_back({_position});
}

} // namespace space