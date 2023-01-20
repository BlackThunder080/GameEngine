#include <iostream>
#include <Engine.h>

class MyApp : public Engine::Application
{
public:
	virtual void OnUpdate() override
	{

	}
};

int main(void)
{
	Engine::Application* app = new MyApp();
	app->Run();
	return 0;
}