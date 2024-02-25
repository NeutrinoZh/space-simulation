#pragma once
#include <utils/utils.h>

namespace space {

struct Mesh {
public:
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uv;
    std::vector<uint> indices;

    Mesh(std::vector<glm::vec3> vertices, std::vector<uint> indicies,
         std::vector<glm::vec2> uv)
        : vertices(vertices), uv(uv), indices(indicies){};
};

} // namespace space