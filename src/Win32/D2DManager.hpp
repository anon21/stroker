#ifndef WIN32_D2DMANAGER_HPP_
#define WIN32_D2DMANAGER_HPP_

#include <Win32/Config.hpp>
#include <Windows.h>
#include <d2d1.h>
#include <dwrite.h>

template<typename COMObject>
inline void coSafeRelease(COMObject*& ptr)
{
    if( ptr != nullptr ) {
        ptr->Release();
        ptr = nullptr;
    }
}

class D2DManager {
public:
    static D2DManager& getInstance() { return d2dManager_; }
    
    D2DManager();
    
    bool initialize();
    void finish();
    
    ID2D1Factory* getD2DFactory() { return d2dFactory_; }
    IDWriteFactory* getDWriteFactory() { return dwriteFactory_; }
    
private:
    static D2DManager d2dManager_;
    
    ID2D1Factory* d2dFactory_;
    IDWriteFactory* dwriteFactory_;
};

#endif // WIN32_D2DMANAGER_HPP_
