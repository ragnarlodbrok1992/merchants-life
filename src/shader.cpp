#include "shader.hpp"

#include <stdio.h>

// Filepaths are in relation to executable @TODO fix that in some way
// And are loaded at runtime
constexpr char* default_vertex_shader_filepath   = "src/shaders/default_vertex_shader.vert";
constexpr char* default_fragment_shader_filepath = "src/shaders/default_fragment_shader.frag";

Shader::Shader(const char* vertex_shader_filepath,
               const char* fragment_shader_filepath) {
  printf("Constructoooor!\n");
  printf("Vertex shader filepath: %s, fragment shader filepath: %s\n",
      vertex_shader_filepath,
      fragment_shader_filepath);
}

Shader::Shader() {
  printf("Constructoooor!\n");
  printf("Vertex shader filepath: %s, fragment shader filepath: %s\n",
      default_vertex_shader_filepath,
      default_fragment_shader_filepath);
}

