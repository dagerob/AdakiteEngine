#pragma once

#ifdef ADK_PLATFORM_WINDOWS

extern Adakite::Application* Adakite::CreateApplication();

int main(int argc, char** argv) {
	printf("Adakite Engine\n");

	Adakite::Log::Init();
	ADK_CORE_WARN("Initialized the logs");
	int a = 8;
	ADK_INFO("Initialized the logs {0}",a);

	auto app = Adakite::CreateApplication();
	app->Run();
	delete app;
}

#endif // ADK_PLATFORM_WINDOWS
