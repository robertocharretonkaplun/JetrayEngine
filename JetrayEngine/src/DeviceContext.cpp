#include "DeviceContext.h"

void 
DeviceContext::destroy() {
	m_deviceContext->ClearState();
}

void
DeviceContext::ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView, 
																		 unsigned int ClearFlags, 
																		 float Depth, 
																		 unsigned int Stencil) {
	if (pDepthStencilView == nullptr) {
		WARNING("ERROR: DeviceContext::ClearDepthStencilView : Error in data from params [CHECK FOR ID3D11DepthStencilView* pDepthStencilView] \n");
		exit(1);
	}
	else {
		m_deviceContext->ClearDepthStencilView(pDepthStencilView, ClearFlags, Depth, Stencil);
	}
}

void 
DeviceContext::PSSetShaderResources(unsigned int StartSlot, 
																		unsigned int NumViews, 
																		ID3D11ShaderResourceView* const* ppShaderResourceViews) {
	if (ppShaderResourceViews == nullptr) {
		WARNING("ERROR: DeviceContext::PSSetShaderResources : Error in data from params [CHECK FOR ID3D11ShaderResourceView* const* ppShaderResourceViews] \n");
		exit(1);
	}
	else {
		m_deviceContext->PSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}
}

void 
DeviceContext::OMSetRenderTargets(unsigned int NumViews, 
																	ID3D11RenderTargetView* const* ppRenderTargetViews, 
																	ID3D11DepthStencilView* pDepthStencilView) {
	if (ppRenderTargetViews == nullptr) {
		WARNING("ERROR: DeviceContext::OMSetRenderTargets : Error in data from params [CHECK FOR ID3D11RenderTargetView* const* ppRenderTargetViews] \n");
		exit(1);
	}
	else if(pDepthStencilView == nullptr) {
		WARNING("ERROR: DeviceContext::OMSetRenderTargets : Error in data from params [CHECK FOR ID3D11DepthStencilView* pDepthStencilView] \n");
		exit(1);
	}
	else {
		m_deviceContext->OMSetRenderTargets(NumViews, ppRenderTargetViews, pDepthStencilView);
	}
}

void 
DeviceContext::ClearRenderTargetView(ID3D11RenderTargetView* pRenderTargetView, 
																		 const float ColorRGBA[4]) {
	if (pRenderTargetView == nullptr) {
		WARNING("ERROR: DeviceContext::ClearRenderTargetView : Error in data from params [CHECK FOR ID3D11RenderTargetView* pRenderTargetView] \n");
		exit(1);
	}
	else {
		m_deviceContext->ClearRenderTargetView(pRenderTargetView, ColorRGBA);
	}
}

void 
DeviceContext::RSSetViewports(unsigned int NumViewports, 
														  const D3D11_VIEWPORT* pViewports) {
	m_deviceContext->RSSetViewports(NumViewports, pViewports);
}
