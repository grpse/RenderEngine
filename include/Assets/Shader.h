#include "Asset.h"
#include "FileUtils.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4.h"
#include "Texture.h"

#ifndef SHADER_H
#define SHADER_H

class Shader : public Asset {

public:

    enum ShaderType {
        Fragment = GL_FRAGMENT_SHADER,
        Vertex = GL_VERTEX_SHADER
    };

    Shader();
    ~Shader();
    virtual void load(const char* relativePath);
    
    void use();

    void setUniformv(const char* uniform, const Vector2& v);
    void setUniformv(const char* uniform, const Vector3& v);
    void setUniformv(const char* uniform, const Vector4& v);
    void setUniformv(const char* uniform, const Matrix4& m);
    void setUniformv(const char* uniform, const Texture& t);


private:
    unsigned int m_program;
    unsigned int m_vertex;
    unsigned int m_fragment;
    char* m_currentShaderSource;

    void m_compileProgram(unsigned int programID, char* source);
    void m_link();
};

#endif /*SHADER_H*/