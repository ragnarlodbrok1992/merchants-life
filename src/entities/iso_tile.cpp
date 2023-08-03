#include "iso_tile.hpp"

#include <stdio.h>

IsoTile::IsoTile(int _x, int _y) : x(_x), y(_y) {
  // Also remember that we have a coordinates like that (maybe idk): (x, y, z) in vertices
  // +----------------->
  // |
  // |
  // |
  // |
  // |
  // |
  // |
  // v
  
  // Setting up vertices
  constexpr GLfloat top_left    [3] = {- ISO_TILE_SIZE,   ISO_TILE_SIZE, 0.0f};
  constexpr GLfloat top_right   [3] = {  ISO_TILE_SIZE,   ISO_TILE_SIZE, 0.0f};
  constexpr GLfloat bottom_left [3] = {- ISO_TILE_SIZE, - ISO_TILE_SIZE, 0.0f};
  constexpr GLfloat bottom_right[3] = {  ISO_TILE_SIZE, - ISO_TILE_SIZE, 0.0f};

  // Setting up colors
  for (int a = 0; a < 4; a++) {
    colors[a]      = RED[a];
    colors[a + 4]  = GREEN[a];
    colors[a + 8]  = BLUE[a];
    colors[a + 12] = YELLOW[a];
  }

  // Setting up vertices
  for (int a = 0; a < 3; a++) {
    vertices[a]     = top_left[a];
    vertices[a + 3] = top_right[a];
    vertices[a + 6] = bottom_left[a];
    vertices[a + 9] = bottom_right[a];
  }

  // Initializing buffers
}



