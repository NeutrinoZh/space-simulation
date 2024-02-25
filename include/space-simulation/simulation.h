#pragma once
#include <utils/utils.h>

namespace space {
class PhysicsSimulation {
private:
    const double G = 1.f;

public:
    PhysicsSimulation(int _numParticles) noexcept;

    void update();
};

} // namespace space