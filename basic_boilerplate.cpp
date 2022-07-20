#include <stdio.h>
#include <GL/glew.h>
#include <glfw/glfw3.h>
#include <iostream>

// window dimensions
const GLint WIDTH = 800, HEIGHT = 600;

int main() 
{
   // Initialize GLFW and check for errors
  if(!glfwInit())
  {
    printf("GLFW Initialization Failed!");
    glfwTerminate();
    return 1;
  }
  
  // Set GLFW window properties and OpenGL version
  glfwWindowHint(GLFW_CONTEXT_MAJOR_VERSION, 3);
  glfwWindowHint(GLFW_CONTEXT_MINOR_VERSION, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  
  // Window creation
  GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
  if(!mainWindow)
  {
     printf("GLFW Initialization Failed!");
    glfwTerminate();
    return 1;
  }
  // Get buffer size information
  int bufferWidth, bufferHeight;
  glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);
  
  // Set context for GLEW to use
  glfwMakeContextCurrent(mainWindow);
  
  // Allow modern extension features
  glewExperimental = GL_TRUE;
  
  // Initialize GLEW
  if(glewInit() != GLEW_OK)
  {
    printf("GLEW Initialization Failed!");
    glfwDestroyWindow(mainWindow);
    glfwTerminate();
    return 1;
  }
  
  // Set up viewport size
  glViewport(0, 0, bufferWidth, bufferHeight);
  
  // Loop until window closes
  while(!glfwWindowShouldClose)
  {
    // Get and handle input
    glfwPollEvents();
    
    // Clear Window
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glfwSwapBuffers(mainWindow);
  }
  return 0;
}
