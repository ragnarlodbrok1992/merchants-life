#ifndef _H_SHADER
#define _H_SHADER


class Shader {
  public:
    // I think that any shader programs requires two shaders at least - fragment and vertex
    unsigned int program_ID; // Shaders are differenciate using program ID's

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
    void checkCompilerErrors(unsigned int shader, const char* type);
};

#endif /* _H_SHADER */

