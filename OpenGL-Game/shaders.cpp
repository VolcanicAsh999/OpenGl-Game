#include "OpenGL.h"
#include "shaders.h"

/*GLuint programID;

GLuint LoadShaders(const char *vertex_file_path, const char *fragment_file_path)
{
    GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    string vertexShaderCode;
    ifstream vertexShaderStream(vertex_file_path, ios::in);
    if (vertexShaderStream.is_open()) {
        string line = "";
        while (getline(vertexShaderStream, line))
            vertexShaderCode += "\n" + line;
        vertexShaderStream.close();
    }

    string fragmentShaderCode;
    ifstream fragmentShaderStream(fragment_file_path, ios::in);
    if (fragmentShaderStream.is_open()) {
        string line = "";
        while (getline(fragmentShaderStream, line))
            fragmentShaderCode += "\n" + line;
        fragmentShaderStream.close();
    }

    GLint result = GL_FALSE;
    int infoLogLength;
    char const *vertexSourcePointer = vertexShaderCode.c_str();
    glShaderSource(vertexShaderID, 1, &vertexSourcePointer, NULL);
    glCompileShader(vertexShaderID);

    glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &result);
    glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
    vector<char> vertexShaderErrorMessage(infoLogLength);
    glGetShaderInfoLog(vertexShaderID, infoLogLength, NULL, &vertexShaderErrorMessage[0]);
    fprintf(stdout, "%s\n", &vertexShaderErrorMessage[0]);

    char const *fragmentSourcePointer = fragmentShaderCode.c_str();
    glShaderSource(fragmentShaderID, 1, &fragmentSourcePointer, NULL);
    glCompileShader(fragmentShaderID);

    glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &result);
    glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
    vector<char> fragmentShaderErrorMessage(infoLogLength);
    glGetShaderInfoLog(fragmentShaderID, infoLogLength, NULL, &fragmentShaderErrorMessage[0]);
    fprintf(stdout, "%s\n", &fragmentShaderErrorMessage[0]);

    GLuint programID = glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    glLinkProgram(programID);

    glGetProgramiv(programID, GL_LINK_STATUS, &result);
    glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);
    vector<char> programErrorMessage(max(infoLogLength, int(1)));
    glGetProgramInfoLog(programID, infoLogLength, NULL, &programErrorMessage[0]);
    fprintf(stdout, "%s\n", &programErrorMessage[0]);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);

    return programID;
}

void initShaders()
{
    programID = LoadShaders("GL.vert", "GL.frag");
}

void checkProgram()
{
    glUseProgram(programID);
}*/

void initShaders()
{

}

void checkProgram()
{

}
