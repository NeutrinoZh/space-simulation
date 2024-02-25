#pragma once
#include <utils/utils.h>

namespace space {

class Shader {
private:
    uint m_program;

public:
    Shader(const char* vertexShaderText, const char* fragmentShaderText);
    ~Shader();

    void use();
    void uMat4f(const char* name, glm::mat4 mat);
    void uVec4f(const char* name, glm::vec4 vec);
};

} // namespace space