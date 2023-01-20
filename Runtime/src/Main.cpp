#include <iostream>
#include <functional>
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
	std::unique_ptr<MyApp> app = std::make_unique<MyApp>();
	app->Run();
	return 0;
}