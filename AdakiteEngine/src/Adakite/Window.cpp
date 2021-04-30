#include "Window.h"
#include "Log.h"

Window::Window(int screenWidth, int screenHeight, int AntiAliasing) {
	this->screenHeight = screenHeight;
	this->screenWidth = screenWidth;
	this->AntiAliasingMode = AntiAliasing;
	deltaTime = 0.0f;
	lastFrame = 0.0f;

	// initialize things
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_SAMPLES, AntiAliasingMode);

	window = glfwCreateWindow(screenWidth, screenHeight, "RenderingEngine", NULL, NULL);
	// create window
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		ADK_CORE_ERROR("Failed to create GLFW window");
		glfwTerminate();
		error = true;
		return;
	}
	glfwMakeContextCurrent(window);

	// initialize glad with the pointer to the corresponding functions for the drivers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		ADK_CORE_ERROR("Failed to initialize GLAD");
		error = true;
		return;
	}
	// we create the viewport and set the resize callback function
	glViewport(0, 0, screenWidth, screenHeight);

	// we enable the depht buffer
	glEnable(GL_DEPTH_TEST);

	// activate antialiasing
	glEnable(GL_MULTISAMPLE);

	// to enable the changing of the point size when rendering using GL_POINTS
	glEnable(GL_PROGRAM_POINT_SIZE);
}

void Window::initializeDraw(float r, float g, float b) {
	glClearColor(r, g, b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
}

void Window::finalizeDraw() const {
	glfwSwapBuffers(window);
	glfwPollEvents();
}