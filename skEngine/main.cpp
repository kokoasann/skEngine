#include "stdafx.h"
#include "skEngine.h"
using namespace skEngine;

//�e�X�g�p��winmain�֐�
int WINAPI wWinMain(HINSTANCE hinstance, HINSTANCE hprevinstance, LPWSTR lpCmdLine, int nCmdShow)
{
	GetGameEngineInstance().GameInit(hinstance, hprevinstance, lpCmdLine, nCmdShow, "game");
	GetGameEngineInstance().GameLoop();
}