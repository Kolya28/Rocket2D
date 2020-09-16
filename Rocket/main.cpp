#include "pch.h"
#include "Engine.h"
#include "Error.h"
#include "MainMenu.h"
#include"GameState.h"



#if defined(WIN32) && defined(NDEBUG) 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
#else
int main()
#endif
{
	Engine& engine = Engine::Instance();

	try
	{
		engine.init();
		engine.pushState(new MainMenu);
		//engine.pushState(new GameState);

		auto maxFrametime = chrono::milliseconds(1000) / 80;
		auto lastTime = chrono::steady_clock::now();

		while (engine.isRunning())
		{
			auto frametime = chrono::steady_clock::now();

			engine.poolEvents();

			
			auto deltatime = chrono::steady_clock::now() - lastTime;
			lastTime += deltatime;

			float dt = deltatime.count() / 1'000'000'000.f;
			engine.update(dt);

			engine.draw();

			std::this_thread::sleep_for(maxFrametime -
				(chrono::steady_clock::now() - frametime));
		}

		engine.cleanup();
	}
	catch (const std::runtime_error& ex)
	{
		Error::error(ex.what());
	}
	catch (const std::string& ex)
	{
		Error::error(ex);
	}
	catch (const char* ex)
	{
		Error::error(ex);
	}
	catch (...)
	{
		Error::error("Unknown Error");
	}

	return 0;
}