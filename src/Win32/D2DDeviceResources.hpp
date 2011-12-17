#ifndef WIN32_D2DDEVICERESOURCES_HPP_
#define WIN32_D2DDEVICERESOURCES_HPP_

#include <Win32/D2DManager.hpp>

class D2DDeviceResources {
public:
    D2DDeviceResources();
    ~D2DDeviceResources();
    
    bool create(HWND hwnd);
    void discard();
    
    void beginDraw();
    void endDraw();
    
private:
    ID2D1HwndRenderTarget* renderTarget_;
};

#endif // WIN32_D2DDEVICERESOURCES_HPP_
