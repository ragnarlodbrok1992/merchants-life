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
  /* DEBUG PRINTS
  printf("Constructoooor!\n");
  printf("Vertex shader filepath: %s, fragment shader filepath: %s\n",
      default_vertex_shader_filepath,
      default_fragment_shader_filepath);
      */

  FILE vertex_shader_file, fragment_shader_file;
  
  // Checking filesizes for vertex and fragment shader
  printf("Vertex shader file_size: %lld\n", std::filesystem::file_size(default_vertex_shader_filepath));
  printf("Fragment shader file_size: %lld\n", std::filesystem::file_size(default_fragment_shader_filepath));

}

