#include "shader.hpp"

#include <stdio.h>

Shader::Shader(const char* vertex_shader_filepath,
               const char* fragment_shader_filepath) {
  printf("Constructoooor!\n");
  printf("Vertex shader filepath: %s, fragment shader filepath: %s\n",
      vertex_shader_filepath,
      fragment_shader_filepath);
}

