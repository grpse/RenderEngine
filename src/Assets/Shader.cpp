#include "Shader.h"

Shader::Shader() {
    m_program = glCreateProgram();
    m_fragment = glCreateShader(Shader::ShaderType::Fragment);
    m_vertex = glCreateShader(Shader::ShaderType::Vertex);
}

Shader::~Shader() {

}

void Shader::load(const char* relativePath) {
    #if defined(OPENGL)

        char* vert = FileUtils::readAllText(relativePath + ".vert");
        char* frag = FileUtils::readAllText(relativePath + ".frag");

        m_compileProgram(m_vertex, vert);
        m_compileProgram(m_fragment, frag);
    #endif
}



void Shader::use() {
    
}


void Shader::setUniformv(const char* uniform, const Vector2& v) {

}

void Shader::setUniformv(const char* uniform, const Vector3& v) {

}

void Shader::setUniformv(const char* uniform, const Vector4& v) {

}

void Shader::setUniformv(const char* uniform, const Matrix4& m) {

}

void Shader::setUniformv(const char* uniform, const Texture& t) {

}



void Shader::m_compileProgram(unsigned int programID, char* source) {

    //Send the vertex shader source code to GL
    glShaderSource(programID, 1, &source, 0);

    //Compile the vertex shader
    glCompileShader(programID);

    int isCompiled = 0;
    glGetShaderiv(programID, GL_COMPILE_STATUS, &isCompiled);
    
    if(isCompiled == false) {

        unsigned int maxLength = 0;
        glGetShaderiv(programID, GL_INFO_LOG_LENGTH, &maxLength);

        //The maxLength includes the NULL character
        char* infoLog = new char[maxLength + 1];
        glGetShaderInfoLog(programID, maxLength, &maxLength, &infoLog[0]);
        
        //We don't need the shader anymore.
        glDeleteShader(programID);

        //Use the infoLog as you see fit.
        printf("Compile Error: %s\n", infoLog);
        //In this simple program, we'll just leave
        return;
    }
}

void Shader::m_link() {

    //Attach our shaders to our program
    glAttachShader(m_program, m_vertex);
    glAttachShader(m_program, m_fragment);

    //Link our program
    glLinkProgram(m_program);

    //Note the different functions here: glGetProgram* instead of glGetShader*.
    int isLinked = 0;
    glGetProgramiv(m_program, GL_LINK_STATUS, &isLinked);

    if(isLinked == false) {

        unsigned int maxLength = 0;
        glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &maxLength);

        //The maxLength includes the NULL character
        char* infoLog = new char[maxLength + 1];
        glGetProgramInfoLog(m_program, maxLength, &maxLength, &infoLog[0]);
        
        //We don't need the program anymore.
        glDeleteProgram(m_program);
        //Don't leak shaders either.
        glDeleteShader(m_vertex);
        glDeleteShader(m_fragment);

        //Use the infoLog as you see fit.        
        //In this simple program, we'll just leave
        return;
    }

    //Always detach shaders after a successful link.
    glDetachShader(m_program, m_vertex);
    glDetachShader(m_program, m_fragment);
}