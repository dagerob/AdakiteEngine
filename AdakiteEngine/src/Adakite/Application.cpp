#include "Application.h"
#include "Window.h"
#include "Log.h"

namespace Adakite {
	Application::Application() {
		
	}

	Application::~Application() {

	}

	void Application::Run() {
		// We make the GLFW window
		Window myWindow(1080, 720, 0);

		// to save the time since start
		float t = 0.0f;

		// the period of the physics simulation
		const float dt = 0.01f;

		// the minimum time the engine will take for rendering each frame
		float minimumFrameTime = 0.2f;

		float currentTime = glfwGetTime();
		float accumulator = 0.0f;

		while (!glfwWindowShouldClose(myWindow.getWindow()))
		{
			// we calculate this frame's delta time
			float newTime = glfwGetTime();
			float frameTime = newTime - currentTime;
			currentTime = newTime;

			// we add this time to the accumulator so that the physics can take dts out of it
			// we always add the minimumFrameTime as a bare minimum
			accumulator += frameTime < minimumFrameTime ? minimumFrameTime : frameTime;

			float lastPhysicsTime = t;

			// we consume the accumulator in dt chunks
			while (accumulator >= dt)
			{
				accumulator -= dt;
				t += dt;

				float thisDeltaT = t - lastPhysicsTime;
				ADK_CORE_TRACE("Physics: {0}", thisDeltaT);
				lastPhysicsTime = t;
			}

			ADK_CORE_INFO("Render: {0}", frameTime);
			// just an easy way to display the render cycling over all the colors
			myWindow.initializeDraw(glm::cos(t)/2.0f + 0.5f, glm::cos(t + glm::pi<float>()/ 2) / 2.0f + 0.5f, glm::cos(t + glm::pi<float>()) / 2.0f + 0.5f);

			// if we finished early kill the rest of time doing nothing
			while (glfwGetTime() - newTime < minimumFrameTime) {
				continue;
			}

			myWindow.finalizeDraw();
		}
	}
}