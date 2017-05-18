#include "Transform.h"

Transform::Transform() {
    m_dirty = true;
}

void Transform::setPosition(const glm::vec3& p) {
    m_dirty = true;
    m_position = p;
}

const glm::vec3& Transform::getPosition() {
    return m_position;
}

void Transform::setScale(const glm::vec3& s) {
    m_dirty = true;
    m_scale = s;
}

const glm::vec3& Transform::getScale() {
    return m_scale;
}

void Transform::setRotation(const glm::quat& r) {
    m_dirty = true;
    m_rotation = r;
}

const glm::quat& Transform::getRotation() {
    return m_rotation;
}

glm::vec3 Transform::getFront() {
    glm::vec4 front(0, 0, -1, 1);
    glm::mat4 rotation = glm::toMat4(m_rotation);
    front = front * rotation;
    return glm::vec3(front.x, front.y, front.z);
}


glm::mat4& Transform::getModelMatrix() {
    if (m_dirty) {
        m_dirty = false;
        m_modelMatrix = glm::mat4(1);
        m_modelMatrix = glm::translate(m_modelMatrix, m_position);
        m_modelMatrix = glm::rotate(m_modelMatrix, m_rotation.x, glm::vec3(1, 0, 0));
        m_modelMatrix = glm::rotate(m_modelMatrix, m_rotation.y, glm::vec3(0, 1, 0));
        m_modelMatrix = glm::rotate(m_modelMatrix, m_rotation.z, glm::vec3(0, 0, 1));
        m_modelMatrix = glm::scale(m_modelMatrix, m_scale);
    }

    return m_modelMatrix;
}