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
		//�E�B���h�E�N���X�̃p�����[�^��ݒ�(�P�Ȃ�\���̂̕ϐ��̏������ł��B)
		WNDCLASSEX wc =
		{
			sizeof(WNDCLASSEX),		//�\���̂̃T�C�Y�B
			CS_CLASSDC,				//�E�B���h�E�̃X�^�C���B
									//�����̎w��ŃX�N���[���o�[��������ł��邪�A�Q�[���ł͕s�v�Ȃ̂�CS_CLASSDC�ł悢�B
			MsgProc,				//���b�Z�[�W�v���V�[�W��(��q)
			0,						//0�ł����B
			0,						//0�ł����B
			GetModuleHandle(NULL),	//���̃N���X�̂��߂̃E�C���h�E�v���V�[�W��������C���X�^���X�n���h���B
									//�����C�ɂ��Ȃ��Ă悢�B
			NULL,					//�A�C�R���̃n���h���B�A�C�R����ς������ꍇ������ύX����B�Ƃ肠��������ł����B
			NULL,					//�}�E�X�J�[�\���̃n���h���BNULL�̏ꍇ�̓f�t�H���g�B
			NULL,					//�E�B���h�E�̔w�i�F�BNULL�̏ꍇ�̓f�t�H���g�B
			NULL,					//���j���[���BNULL�ł����B
			TEXT("Sample_00"),		//�E�B���h�E�N���X�ɕt���閼�O�B
			NULL					//NULL�ł����B
		};
		//�E�B���h�E�N���X�̓o�^�B
		RegisterClassEx(&wc);

		// �E�B���h�E�̍쐬�B
		m_hWnd = CreateWindow(
			TEXT("Sample_00"),		//�g�p����E�B���h�E�N���X�̖��O�B
									//��قǍ쐬�����E�B���h�E�N���X�Ɠ������O�ɂ���B
			TEXT(gamename),		//�E�B���h�E�̖��O�B�E�B���h�E�N���X�̖��O�ƕʖ��ł��悢�B
			WS_OVERLAPPEDWINDOW,	//�E�B���h�E�X�^�C���B�Q�[���ł͊�{�I��WS_OVERLAPPEDWINDOW�ł����A
			0,						//�E�B���h�E�̏���X���W�B
			0,						//�E�B���h�E�̏���Y���W�B
			1280,					//�E�B���h�E�̕��B
			720,					//�E�B���h�E�̍����B
			NULL,					//�e�E�B���h�E�B�Q�[���ł͊�{�I��NULL�ł����B
			NULL,					//���j���[�B����NULL�ł����B
			hInstance,				//�A�v���P�[�V�����̃C���X�^���X�B
			NULL
		);

		ShowWindow(m_hWnd, nCmdShow);
	}

	void GameEngine::GameLoop()
	{
		//���b�Z�[�W�\���̂̕ϐ�msg���������B
		MSG msg = { 0 };
		while (WM_QUIT != msg.message)	//���b�Z�[�W���[�v
		{
			//�E�B���h�E����̃��b�Z�[�W���󂯎��B
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
	}

	

	LRESULT CALLBACK GameEngine::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		//�����Ă������b�Z�[�W�ŏ����𕪊򂳂���B
		switch (msg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		case WM_LBUTTONDOWN:
			//�}�E�X�̍��{�^���������ꂽ�B
			//MessageBox(hWnd, "�}�E�X�̍��{�^���������ꂽ��B", "���m�点", MB_OK);
			break;
		case WM_RBUTTONDOWN:
			//MessageBox(hWnd, "�}�E�X��migi�{�^���������ꂽ��B", "���m�点", MB_OK);
			break;
		default:
			return DefWindowProc(hWnd, msg, wParam, lParam);
		}

		return 0;
	}
}