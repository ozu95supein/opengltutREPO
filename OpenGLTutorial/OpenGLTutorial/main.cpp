#include "libs.h"

void frame_buffer_resize_callback(GLFWwindow * window, int fbW, int fbH)
{
	glViewport(0, 0, fbW, fbH);
}

int main()
{
	//INIT GLFW
	glfwInit();
	//CREATE WINDOW
	const int WINDOW_WIDTH = 640;
	const int WINDOW_HEIGHT = 480;
	int framebufferWidth = 0;
	int framebufferHeight = 0;

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);


	GLFWwindow * window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "YoutubeTutorial", NULL, NULL);
	
	glfwSetFramebufferSizeCallback(window, frame_buffer_resize_callback);
	
	//glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeight);
	//glViewport(0, 0, framebufferWidth, framebufferHeight);

	glfwMakeContextCurrent(window);
	//INIT GLEW needs window and opengl contex
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		std::cout << "ERROR::MAIN::GLFW_INIT_FAILED" << std::endl;
		glfwTerminate();
	}
	//main loop
	while (!glfwWindowShouldClose(window))
	{
		//update input
		glfwPollEvents();

		//update
		//draw
		//clear
		glClearColor(0.f, 0.f, 0.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		//draw

		//end draw
		glfwSwapBuffers(window);
		glFlush();

	}
	//end of program
	glfwTerminate();
	return 0;
}