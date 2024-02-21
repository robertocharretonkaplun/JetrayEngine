#pragma once
#include "Prerequisites.h"

class 
DeviceContext {
public:
	DeviceContext() = default;
	~DeviceContext() { SAFE_RELEASE(m_deviceContext); };

	void 
  init();

  void 
  update();
  
  void 
  render();
  
  void 
  destroy();

  void 
  ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView,
                        unsigned int ClearFlags,
                        float Depth,
                        unsigned int  Stencil);

  void
  PSSetShaderResources(unsigned int StartSlot,
                       unsigned int NumViews,
                       ID3D11ShaderResourceView* const* ppShaderResourceViews);

  void 
  OMSetRenderTargets(unsigned int NumViews,
                     ID3D11RenderTargetView* const* ppRenderTargetViews,
                     ID3D11DepthStencilView* pDepthStencilView);
  
  void 
  ClearRenderTargetView(ID3D11RenderTargetView* pRenderTargetView,
                        const float ColorRGBA[4]);

  void 
  RSSetViewports(unsigned int NumViewports, const D3D11_VIEWPORT* pViewports);

public:
  ID3D11DeviceContext* m_deviceContext = nullptr;
};