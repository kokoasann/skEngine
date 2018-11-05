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
		D3D_FEATURE_LEVEL		m_featureLevel;				//Direct3D デバイスのターゲットとなる機能セット。
		ID3D11Device*			m_pd3dDevice = NULL;		//D3D11デバイス。
		IDXGISwapChain*			m_pSwapChain = NULL;		//スワップチェイン。
		ID3D11DeviceContext*	m_pd3dDeviceContext = NULL;	//D3D11デバイスコンテキスト。
		ID3D11RenderTargetView* m_backBuffer = NULL;		//バックバッファ。
		ID3D11RasterizerState*	m_rasterizerState = NULL;	//ラスタライザステート。
		ID3D11Texture2D*		m_depthStencil = NULL;		//デプスステンシル。
		ID3D11DepthStencilView* m_depthStencilView = NULL;	//デプスステンシルビュー。
		int m_frameBufferWidth = 0;
		int m_frameBufferHeight = 0;
	};
}