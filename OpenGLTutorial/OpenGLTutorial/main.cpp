#include "libs.h"

int main()
{
	glfwInit();

	//create a window before glew init

	//glew
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		glfwTerminate();
		throw "error in glew init";
	}
	
	system("Pause");
	return 0;
}