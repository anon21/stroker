#ifndef WIN32_EDITORWINDOW_HPP_
#define WIN32_EDITORWINDOW_HPP_

#include <Win32/EventHandler.hpp>
#include <Win32/D2DDeviceResources.hpp>

class EditorWindow :
    public EventHandler<EditorWindow>
{
public:
    static bool registerWndcls();
    
    EditorWindow();
    
    LRESULT dispatchEvent(UINT msg, WPARAM wp, LPARAM lp);
    void onRender();
    
    void create();
    
private:
    HWND hwnd_;
    D2DDeviceResources deviceResources_;
};

#endif // WIN32_EDITORWINDOW_HPP_
