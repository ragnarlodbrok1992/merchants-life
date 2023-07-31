#include <stdio.h>
#include <glad\glad.h>
#include <GLFW\glfw3.h>

// Local includes
#include "shader.hpp"

// Functions forward declarations
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void processInput(GLFWwindow* window);

// Engine constants
const unsigned int SCREEN_WIDTH = 1024;
const unsigned int SCREEN_HEIGHT = 768;

int main(int argc, char* argv[]) {
  printf("Merchants Life - development version.\n");

  // DEBUG checks
  Shader* shader1 = new Shader();
  // Shader* shader2 = new Shader("Twojstary vertex shader", "Twojstarty fragment shader");

  /*
  // DEBUG: early return
  return 0;
  */

  // GLFW - initialize and configure
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // GLFW - window creation
  GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Merchants Life - developer version.", NULL, NULL); 
  if (window == NULL) {
    printf("Failed to create GLFW window!\n");
    glfwTerminate();

    return -1;
  }

  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // GLAD - loading all OpenGL function pointers
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    printf("Failed to initialize GLAD!\n");

    return -1;
  }

  // Setting callback functions
  glfwSetKeyCallback(window, key_callback);

  // Render loop
  while (!glfwWindowShouldClose(window)) {
    // Processing input at start of every frame
    processInput(window);

    // Render
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // GLFW - swap buffers and poll IO events
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // Terminating glfw
  glfwTerminate();

  // Last call before dropping
  // If this message wasn't printed - something is terribly wrong
  printf("Successfully exiting!\n");
  return 0;
}

// Processing input
void processInput(GLFWwindow* window) {

}

// Resizing window
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  // Viewport should match window size
  glViewport(0, 0, width, height);
}

// Key callback function
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

  if (action == GLFW_PRESS) {
    switch (key) {
      // Exit engine
      case GLFW_KEY_ESCAPE:
        glfwSetWindowShouldClose(window, GLFW_TRUE);
        break;
    }
  }
}
