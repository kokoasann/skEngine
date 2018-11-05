#pragma once

namespace skEngine
{
	class GameEngine
	{
	public:
		GameEngine();
		~GameEngine();

		static GameEngine& GetInstance();
		

		void GameInit(HINSTANCE hInstance, HINSTANCE hprevinstance, LPWSTR lpCmdLine, int nCmdShow,const char* gamename);
		void GameLoop();

		static LRESULT CALLBACK MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	private:
		HWND m_hWnd = nullptr;
	};

	static GameEngine& GetGameEngineInstance()
	{
		return GameEngine::GetInstance();
	}
}
