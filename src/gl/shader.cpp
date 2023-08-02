#include "shader.hpp"

#include <stdio.h>
#include <filesystem>

#include <glad/glad.h>

/*
#ifdef _WIN32
#include <direct.h>
#elif defined __linux__
#error "Not implemented for Linux!"
#endif
*/


// Filepaths are in relation to executable @TODO fix that in some way
// And are loaded at runtime
constexpr char* default_vertex_shader_filepath   = "src/shaders/default_vertex_shader.vert";
constexpr char* default_fragment_shader_filepath = "src/shaders/default_fragment_shader.frag";


Shader::Shader(const char* vertex_shader_filepath,
               const char* fragment_shader_filepath) {
  //@TODO: implement
}

Shader::Shader() {
  FILE* vertex_shader_file;
  FILE* fragment_shader_file;
  size_t vertex_shader_file_size, fragment_shader_file_size;

  vertex_shader_file_size   = std::filesystem::file_size(default_vertex_shader_filepath); 
  fragment_shader_file_size = std::filesystem::file_size(default_fragment_shader_filepath);

  // Let's malloc that stuff
  // char vertex_shader_code_buffer[vertex_shader_file_size];
  // char fragment_shader_code_buffer[fragment_shader_file_size];
  // TODO: check for malloc failures
  char* vertex_shader_code_buffer = (char*)   malloc(vertex_shader_file_size * sizeof(char) + 1);
  char* fragment_shader_code_buffer = (char*) malloc(fragment_shader_file_size * sizeof(char) + 1);
  // Read files into buffers
  //
  vertex_shader_file = fopen(default_vertex_shader_filepath, "rb");
  fragment_shader_file = fopen(default_fragment_shader_filepath, "rb");

  if (vertex_shader_file != 0) { // Success
    fread(vertex_shader_code_buffer, 1, vertex_shader_file_size, vertex_shader_file);
    vertex_shader_code_buffer[vertex_shader_file_size] = '\0';
  } else {
    printf("There has been problem with vertex shader!\n");
  }

  if (fragment_shader_file != 0) { // Success
    fread(fragment_shader_code_buffer, 1, fragment_shader_file_size, fragment_shader_file);
    fragment_shader_code_buffer[fragment_shader_file_size] = '\0';
  } else {
    printf("There has been problem with fragment shader!\n");
  }

  // DEBUG stuff
  // ShaderType DUPA = COUNT;
  // checkCompileErrors(1, DUPA);

  // Compiling shaders
  unsigned int vertex_id, fragment_id;
  constexpr ShaderType vertex_type   = VERTEX;
  constexpr ShaderType fragment_type = FRAGMENT;
  constexpr ShaderType program_type  = PROGRAM;

  // Vertex shader
  vertex_id = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex_id, 1, &vertex_shader_code_buffer, NULL);
  glCompileShader(vertex_id);
  checkCompileErrors(vertex_id, vertex_type);

  // Fragment shader
  fragment_id = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment_id, 1, &fragment_shader_code_buffer, NULL);
  glCompileShader(fragment_id);
  checkCompileErrors(fragment_id, fragment_type);

  // Shader program
  program_ID = glCreateProgram();
  glAttachShader(program_ID, vertex_id);
  glAttachShader(program_ID, fragment_id);
  glLinkProgram(program_ID);
  checkCompileErrors(program_ID, program_type);

  // Deleting shaders - they are linked inside a program
  glDeleteShader(vertex_id);
  glDeleteShader(fragment_id);

  // Freeing stuff
  free(vertex_shader_code_buffer);
  free(fragment_shader_code_buffer);
}

void Shader::use() {
  glUseProgram(program_ID);
}

void Shader::setBool(const char* name, bool value) {
  glUniform1i(glGetUniformLocation(program_ID, name), (int) value);
}

void Shader::setInt(const char* name, int value) {
  glUniform1i(glGetUniformLocation(program_ID, name), value);
}

void Shader::setFloat(const char* name, float value) {
  glUniform1f(glGetUniformLocation(program_ID, name), value);
}

// Enum utility functions
void get_shader_type_name(ShaderType& type, char* filled_text, size_t size) {
  switch (type) {
    case VERTEX:
      strncpy(filled_text, "VERTEX", size);
      break;
    case FRAGMENT:
      strncpy(filled_text, "FRAGMENT", size);
      break;
    case PROGRAM:
      strncpy(filled_text, "PROGRAM", size);
      break;
    case COUNT:
      strncpy(filled_text, "COUNT: 2", size);
      break;
    default:
      printf("  ERROR: We shouldn't be here! %s %d\n", __FILE__, __LINE__);
      break;
  }
}

void Shader::checkCompileErrors(unsigned int shader, ShaderType type) {
  int success;
  char info_log[1024];

  switch (type) {
    case VERTEX:
    case FRAGMENT:
      char shader_type_name[32];
      get_shader_type_name(type, shader_type_name, 32);

      glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

      if (!success) {
        glGetShaderInfoLog(shader, 1024, NULL, info_log);
        printf("ERROR::%s_SHADER_COMPILATION_ERROR: %s", shader_type_name, info_log);
      }

      break;
    case PROGRAM:
      glGetProgramiv(shader, GL_LINK_STATUS, &success);

      if (!success) {
        glGetProgramInfoLog(shader, 1024, NULL, info_log);
        printf("ERROR::PROGRAM_LINKING_ERROR: %s", info_log);
      }

      break;
    default:
      printf("  ERROR: We shouldn't be here! %s %d\n", __FILE__, __LINE__);
      break;
  }
}
