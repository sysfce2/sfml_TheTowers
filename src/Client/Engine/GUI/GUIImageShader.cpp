#include "GUIImageShader.hpp"

void GUIImageShader::init(){
    loadShader("res/shaders/gui_image_vertex_shader.glsl", "res/shaders/gui_image_fragment_shader.glsl");
    getUniformLocations();
}

void GUIImageShader::loadMatrix(const glm::mat4& matrix){
    glUniformMatrix4fv(m_matrixLocation, 1, GL_FALSE, &matrix[0][0]);
}

void GUIImageShader::loadPosition(const glm::vec2& position){
    glUniform3fv(m_positionLocation, 1, &position[0]);
}

void GUIImageShader::getUniformLocations(){
    bind();
    m_positionLocation = glGetUniformLocation(m_programID, "position");
    m_matrixLocation = glGetUniformLocation(m_programID, "matrix");
    unbind();
}