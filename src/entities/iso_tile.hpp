#ifndef _H_ISO_TILE
#define _H_ISO_TILE

#include <GLFW\glfw3.h>

#include "../gl/colors.hpp"

constexpr GLfloat ISO_TILE_SIZE   = 1.0f;
constexpr int     ISO_TILE_X_SIZE = 10;
constexpr int     ISO_TILE_Y_SIZE = 10;

class IsoTile {
public:

  // IsoMap position - integer position
  int x, y;

  // GL stuff
  GLfloat vertices[4 * 3] = {0};
  GLfloat colors[4 * 4]   = {0};
  unsigned int indices[] = {0, 1, 2, 1, 2, 3};

  unsigned int VBO, VAO, EBO;

  IsoTile() = delete; // Default ctor = LET'S NOT!
  IsoTile(int _x, int _y);

};

#endif /* _H_ISO_TILE */

