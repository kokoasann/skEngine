#include "stdafx.h"
#include "skEngine.h"


namespace skEngine
{
	GameEngine::GameEngine()
	{
	}

	GameEngine::~GameEngine()
	{
	}

	GameEngine& GameEngine::GetInstance()
	{
		static GameEngine* engine = nullptr;
		if (engine == nullptr)
		{
			engine = new GameEngine;
		}
		return *engine;
	}

	


	void GameEngine::GameInit(HINSTANCE hInstance, HINSTANCE hprevinstance, LPWSTR lpCmdLine, int nCmdShow, const char * gamename)
	{
		//ウィンドウクラスのパラメータを設定(単なる構造体の変数の初期化です。)
		WNDCLASSEX wc =
		{
			sizeof(WNDCLASSEX),		//構造体のサイズ。
			CS_CLASSDC,				//ウィンドウのスタイル。
									//ここの指定でスクロールバーをつけたりできるが、ゲームでは不要なのでCS_CLASSDCでよい。
			MsgProc,				//メッセージプロシージャ(後述)
			0,						//0でいい。
			0,						//0でいい。
			GetModuleHandle(NULL),	//このクラスのためのウインドウプロシージャがあるインスタンスハンドル。
									//何も気にしなくてよい。
			NULL,					//アイコンのハンドル。アイコンを変えたい場合ここを変更する。とりあえずこれでいい。
			NULL,					//マウスカーソルのハンドル。NULLの場合はデフォルト。
			NULL,					//ウィンドウの背景色。NULLの場合はデフォルト。
			NULL,					//メニュー名。NULLでいい。
			TEXT("Sample_00"),		//ウィンドウクラスに付ける名前。
			NULL					//NULLでいい。
		};
		//ウィンドウクラスの登録。
		RegisterClassEx(&wc);

		// ウィンドウの作成。
		m_hWnd = CreateWindow(
			TEXT("Sample_00"),		//使用するウィンドウクラスの名前。
									//先ほど作成したウィンドウクラスと同じ名前にする。
			TEXT(gamename),		//ウィンドウの名前。ウィンドウクラスの名前と別名でもよい。
			WS_OVERLAPPEDWINDOW,	//ウィンドウスタイル。ゲームでは基本的にWS_OVERLAPPEDWINDOWでいい、
			0,						//ウィンドウの初期X座標。
			0,						//ウィンドウの初期Y座標。
			1280,					//ウィンドウの幅。
			720,					//ウィンドウの高さ。
			NULL,					//親ウィンドウ。ゲームでは基本的にNULLでいい。
			NULL,					//メニュー。今はNULLでいい。
			hInstance,				//アプリケーションのインスタンス。
			NULL
		);

		ShowWindow(m_hWnd, nCmdShow);
	}

	void GameEngine::GameLoop()
	{
		//メッセージ構造体の変数msgを初期化。
		MSG msg = { 0 };
		while (WM_QUIT != msg.message)	//メッセージループ
		{
			//ウィンドウからのメッセージを受け取る。
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
	}

	

	LRESULT CALLBACK GameEngine::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		//送られてきたメッセージで処理を分岐させる。
		switch (msg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		case WM_LBUTTONDOWN:
			//マウスの左ボタンが押された。
			//MessageBox(hWnd, "マウスの左ボタンが押されたよ。", "お知らせ", MB_OK);
			break;
		case WM_RBUTTONDOWN:
			//MessageBox(hWnd, "マウスのmigiボタンが押されたよ。", "お知らせ", MB_OK);
			break;
		default:
			return DefWindowProc(hWnd, msg, wParam, lParam);
		}

		return 0;
	}
}