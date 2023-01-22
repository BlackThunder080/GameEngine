#include <iostream>
#include <Engine.h>

class MyApp : public Engine::Application
{
public:
	virtual void OnStart() override
	{
		Engine::Logger::Console()->info("Created Application");
	}
};

int main(void)
{
	Engine::Init();
	Engine::Application* app = new MyApp();
	app->Run();
	delete app;
	return 0;
}