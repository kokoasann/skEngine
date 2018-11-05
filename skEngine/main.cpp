#include "stdafx.h"
#include "skEngine.h"
using namespace skEngine;

//テスト用のwinmain関数
int WINAPI wWinMain(HINSTANCE hinstance, HINSTANCE hprevinstance, LPWSTR lpCmdLine, int nCmdShow)
{
	GetGameEngineInstance().GameInit(hinstance, hprevinstance, lpCmdLine, nCmdShow, "game");
	GetGameEngineInstance().GameLoop();
}