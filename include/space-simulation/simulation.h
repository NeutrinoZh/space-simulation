#pragma once
#include <utils/utils.h>

namespace space {
class PhysicsSimulation {
private:
    const double G = 1.f;

public:
    PhysicsSimulation() noexcept;

    void update();
};

} // namespace space