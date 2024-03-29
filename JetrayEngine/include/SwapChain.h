#pragma once
#include "Prerequisites.h"

// Forward Declaration - Declaraciones Directas
class Device;
class DeviceContext;
class Window;
class Texture;

class 
SwapChain {
public:
	SwapChain() = default;
  ~SwapChain() { SAFE_RELEASE(m_swapChain) };
  
  void
  init(Device & device, 
       DeviceContext & deviceContext, 
       Texture & backBuffer, 
       Window window);

  void 
  update();
  
  void 
  render();
  
  void 
  destroy();

  void
  present();
public:
  IDXGISwapChain* m_swapChain = nullptr;
  D3D_DRIVER_TYPE m_driverType = D3D_DRIVER_TYPE_NULL;
private:
  D3D_FEATURE_LEVEL m_featureLevel = D3D_FEATURE_LEVEL_11_0;
};