#ifndef GRIDLINES_H
#define GRIDLINES_H

#include "glm/glm.hpp"
#include <vector>

//Forward Declaration of glrenderer
class GLRenderer;

class Gridlines
{
public:
    void init();
    void draw(GLRenderer* context);

private:
    std::vector<float> lineData;
    glm::mat4 m_model;
    glm::vec3 m_color;
    unsigned int m_vbo;
    unsigned int m_vao;
};

#endif // GRIDLINES_H
