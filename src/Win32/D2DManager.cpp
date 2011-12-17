#include <Win32/D2DManager.hpp>

D2DManager D2DManager::d2dManager_;

D2DManager::D2DManager() :
    d2dFactory_(nullptr), dwriteFactory_(nullptr)
{
}

bool D2DManager::initialize()
{
    HRESULT hr;
    
    hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &d2dFactory_);

    if( SUCCEEDED(hr) ) {
        hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory),
            reinterpret_cast<IUnknown**>(&dwriteFactory_));
    }
    
    if( SUCCEEDED(hr) ) {
        return true;
    }
    
    finish();
    return false;
}

void D2DManager::finish()
{
    coSafeRelease(dwriteFactory_);
    coSafeRelease(d2dFactory_);
}
