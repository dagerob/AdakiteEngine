#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Window {
	unsigned int screenWidth, screenHeight;
	GLFWwindow* window;
	int AntiAliasingMode;
	bool error = false;
	float lastFrame = 0.0f, deltaTime = 0.0f;
public:
	Window(int screenWidth, int screenHeight, int AntiAliasing);
	GLFWwindow* getWindow() const { return window; };
	int getWidth() const { return screenWidth; };
	int getHeight() const { return screenHeight; };
	void initializeDraw(float r, float g, float b);
	void finalizeDraw() const;
	float getDeltaTime() { return deltaTime; };
};