#include <Win32/D2DDeviceResources.hpp>

D2DDeviceResources::D2DDeviceResources() :
    renderTarget_(nullptr)
{
}

D2DDeviceResources::~D2DDeviceResources()
{
    discard();
}

bool D2DDeviceResources::create(HWND hwnd)
{
    if( renderTarget_ != nullptr )
        return true;
    
    RECT clientRect;
	GetClientRect(hwnd, &clientRect);
	
	D2D1_SIZE_U clientSize = D2D1::SizeU(clientRect.right, clientRect.bottom);
	
	auto d2dFactory = D2DManager::getInstance().getD2DFactory();
	
	HRESULT hr = d2dFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(hwnd, clientSize),
		&renderTarget_);
	
	return SUCCEEDED(hr);
}

void D2DDeviceResources::discard()
{
    coSafeRelease(renderTarget_);
}

void D2DDeviceResources::beginDraw()
{
    renderTarget_->BeginDraw();
    renderTarget_->Clear();
}

void D2DDeviceResources::endDraw()
{
    HRESULT hr = renderTarget_->EndDraw();
    
    if( hr == D2DERR_RECREATE_TARGET ) {
        discard();
    }
}
