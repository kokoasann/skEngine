#include "../stdafx.h"
#include "GraphicsEngine.h"

namespace skEngine
{
	GraphicsEngine::GraphicsEngine()
	{
	}

	void GraphicsEngine::Init(HWND hwnd)
	{
		Initd3dDevaiceAndSwapChein(hwnd);
	}

	void GraphicsEngine::Initd3dDevaiceAndSwapChein(HWND hwnd)
	{
		//�X���b�v�`�F�C�����쐬���邽�߂̏���ݒ肷��B
		DXGI_SWAP_CHAIN_DESC sd;
		ZeroMemory(&sd, sizeof(sd));
		sd.BufferCount = 1;									//�X���b�v�`�F�C���̃o�b�t�@���B�ʏ�͂P�B
		sd.BufferDesc.Width = (UINT)FRAME_BUFFER_W;			//�t���[���o�b�t�@�̕��B
		sd.BufferDesc.Height = (UINT)FRAME_BUFFER_H;		//�t���[���o�b�t�@�̍����B
		sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;	//�t���[���o�b�t�@�̃t�H�[�}�b�g�BR8G8B8A8��32bit�B
		sd.BufferDesc.RefreshRate.Numerator = 60;			//���j�^�̃��t���b�V�����[�g�B(�o�b�N�o�b�t�@�ƃt�����g�o�b�t�@�����ւ���^�C�~���O�ƂȂ�B)
		sd.BufferDesc.RefreshRate.Denominator = 1;			//�Q�ɂ�����30fps�ɂȂ�B1�ł����B
		sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;	//�T�[�t�F�X�܂��̓��\�[�X���o�̓����_�[ �^�[�Q�b�g�Ƃ��Ďg�p���܂��B
		sd.OutputWindow = hwnd;							//�o�͐�̃E�B���h�E�n���h���B
		sd.SampleDesc.Count = 1;							//1�ł����B
		sd.SampleDesc.Quality = 0;							//MSAA�Ȃ��B0�ł����B
		sd.Windowed = TRUE;									//�E�B���h�E���[�h�BTRUE�ł悢�B

															//���p����DirectX�̋@�\�Z�b�g�BDirectX10�ȏ�ɑΉ����Ă���GPU�𗘗p�\�Ƃ���B
															//���̔z���D3D11CreateDeviceAndSwapChain�̈����Ƃ��Ďg���B
		D3D_FEATURE_LEVEL featureLevels[] =
		{
			D3D_FEATURE_LEVEL_11_0,
			D3D_FEATURE_LEVEL_10_1,
			D3D_FEATURE_LEVEL_10_0,
		};

		//D3D�f�o�C�X�ƃX���b�v�`�F�C�����쐬����B
		D3D11CreateDeviceAndSwapChain(
			NULL,											//NULL�ł����B
			D3D_DRIVER_TYPE_HARDWARE,						//D3D�f�o�C�X���A�N�Z�X����h���C�o�[�̎�ށB
															//��{�I��D3D_DRIVER_TYPE_HARDWARE���w�肷��΂悢�B
			NULL,											//NULL�ł����B
			0,												//�O�ł����B
			featureLevels,									//D3D�f�o�C�X�̃^�[�Q�b�g�ƂȂ�@�\�Z�b�g���w�肷��B
															//����̃T���v����DirectX10�ȏ���T�|�[�g����̂ŁA
															//�������܂�D3D_FEATURE_LEVEL�̔z���n���B
			sizeof(featureLevels) / sizeof(featureLevels[0]),	//�@�\�Z�b�g�̐��B
			D3D11_SDK_VERSION,								//�g�p����DirectX�̃o�[�W�����B
															//D3D11_SDK_VERSION���w�肷��΂悢�B
			&sd,											//�X���b�v�`�F�C�����쐬���邽�߂̏��B
			&m_pSwapChain,									//�쐬�����X���b�v�`�F�C���̃A�h���X�̊i�[��B
			&m_pd3dDevice,									//�쐬����D3D�f�o�C�X�̃A�h���X�̊i�[��B
			&m_featureLevel,								//�g�p�����@�\�Z�b�g�̊i�[��B
			&m_pd3dDeviceContext							//�쐬����D3D�f�o�C�X�R���e�L�X�g�̃A�h���X�̊i�[��B
		);

		//�������ݐ�ɂȂ郌���_�����O�^�[�Q�b�g���쐬�B
		ID3D11Texture2D* pBackBuffer = NULL;
		m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
		m_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &m_backBuffer);
		pBackBuffer->Release();
		//�[�x�X�e���V���r���[�̍쐬�B
		{
			//�[�x�e�N�X�`���̍쐬�B
			D3D11_TEXTURE2D_DESC texDesc;
			ZeroMemory(&texDesc, sizeof(texDesc));
			texDesc.Width = (UINT)FRAME_BUFFER_W;
			texDesc.Height = (UINT)FRAME_BUFFER_H;
			texDesc.MipLevels = 1;
			texDesc.ArraySize = 1;
			texDesc.Format = DXGI_FORMAT_D32_FLOAT;
			texDesc.SampleDesc.Count = 1;
			texDesc.SampleDesc.Quality = 0;
			texDesc.Usage = D3D11_USAGE_DEFAULT;
			texDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
			texDesc.CPUAccessFlags = 0;
			texDesc.MiscFlags = 0;
			m_pd3dDevice->CreateTexture2D(&texDesc, NULL, &m_depthStencil);
			//�[�x�X�e���V���r���[���쐬�B
			D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
			ZeroMemory(&descDSV, sizeof(descDSV));
			descDSV.Format = texDesc.Format;
			descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
			descDSV.Texture2D.MipSlice = 0;
			m_pd3dDevice->CreateDepthStencilView(m_depthStencil, &descDSV, &m_depthStencilView);
		}
		D3D11_RASTERIZER_DESC desc = {};
		desc.CullMode = D3D11_CULL_NONE;
		desc.FillMode = D3D11_FILL_SOLID;
		desc.DepthClipEnable = true;
		desc.MultisampleEnable = true;

		//���X�^���C�U�ƃr���[�|�[�g���������B
		m_pd3dDevice->CreateRasterizerState(&desc, &m_rasterizerState);

		D3D11_VIEWPORT viewport;
		viewport.Width = FRAME_BUFFER_W;
		viewport.Height = FRAME_BUFFER_H;
		viewport.TopLeftX = 0;
		viewport.TopLeftY = 0;
		viewport.MinDepth = 0.0f;
		viewport.MaxDepth = 1.0f;
		m_pd3dDeviceContext->RSSetViewports(1, &viewport);
		m_pd3dDeviceContext->RSSetState(m_rasterizerState);
	}
}