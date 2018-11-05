#pragma once

namespace skEngine
{
	class GraphicsEngine
	{
	public:
		GraphicsEngine();

		void Init(HWND hwnd);
		void Initd3dDevaiceAndSwapChein(HWND hwnd);

	private:
		D3D_FEATURE_LEVEL		m_featureLevel;				//Direct3D �f�o�C�X�̃^�[�Q�b�g�ƂȂ�@�\�Z�b�g�B
		ID3D11Device*			m_pd3dDevice = NULL;		//D3D11�f�o�C�X�B
		IDXGISwapChain*			m_pSwapChain = NULL;		//�X���b�v�`�F�C���B
		ID3D11DeviceContext*	m_pd3dDeviceContext = NULL;	//D3D11�f�o�C�X�R���e�L�X�g�B
		ID3D11RenderTargetView* m_backBuffer = NULL;		//�o�b�N�o�b�t�@�B
		ID3D11RasterizerState*	m_rasterizerState = NULL;	//���X�^���C�U�X�e�[�g�B
		ID3D11Texture2D*		m_depthStencil = NULL;		//�f�v�X�X�e���V���B
		ID3D11DepthStencilView* m_depthStencilView = NULL;	//�f�v�X�X�e���V���r���[�B
		int m_frameBufferWidth = 0;
		int m_frameBufferHeight = 0;
	};
}