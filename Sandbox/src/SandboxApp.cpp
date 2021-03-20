#include <Adakite.h>

class Sandbox : public Adakite::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Adakite::Application* Adakite::CreateApplication() {
	return new Sandbox();
}