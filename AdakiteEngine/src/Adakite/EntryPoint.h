#pragma once

#ifdef ADK_PLATFORM_WINDOWS

extern Adakite::Application* Adakite::CreateApplication();

int main(int argc, char** argv) {
	printf("Adakite Engine\n");
	auto app = Adakite::CreateApplication();
	app->Run();
	delete app;
}

#endif // ADK_PLATFORM_WINDOWS
