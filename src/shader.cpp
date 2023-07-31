#include "shader.hpp"

#include <stdio.h>
#include <filesystem>

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
  /* DEBUG PRINTS
  printf("Constructoooor!\n");
  printf("Vertex shader filepath: %s, fragment shader filepath: %s\n",
      vertex_shader_filepath,
      fragment_shader_filepath);
      */

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

  // Freeing stuff
  free(vertex_shader_code_buffer);
  free(fragment_shader_code_buffer);
}

void Shader::checkCompileErrors(unsigned int shader, ShaderType type) {
  switch (type) {
    case VERTEX:

      break;
    case FRAGMENT:

      break;
    default:
      printf("  ERROR: We shouldn't be here! %s %d\n", __FILE__, __LINE__);
      break;
  }
}
