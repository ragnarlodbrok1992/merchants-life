#ifndef _H_SHADER
#define _H_SHADER

#include <string.h>
#include <stdio.h>


enum ShaderType {
  VERTEX,
  FRAGMENT,
  PROGRAM, // enum for checking errors
  COUNT // keep last for count of shader_types in our engine - 2
};

// Enum utility functions
void get_shader_type_name(ShaderType& type, char* filled_text, size_t size);

class Shader {
  public:
    // I think that any shader programs requires two shaders at least - fragment and vertex
    unsigned int program_ID; // Shaders are differenciate using program ID's
    char* vertex_code;
    char* fragment_code;

    // Constructors
    // Rule of zero, three, five? Don't know yet @TODO
    Shader(); // Default values are in shader.cpp
    Shader(const char* vertex_shader_filepath,
           const char* fragment_shader_filepath);

    // Loading shaders
    // void load(const char* vsfp, const char* fsfp);

    // Activating shader
    void use();

    // Utility uniform functions -- setting stuff
    void setBool (const char* name, bool value);
    void setInt  (const char* name, int value);
    void setFloat(const char* name, float value);

  private:
    // Compiler errors checker - OpenGL does this silently and if you don't ask
    // it doesn't bother you with details about why is your shader fucked up
    void checkCompileErrors(unsigned int shader, ShaderType type);
};

#endif /* _H_SHADER */

