#include <Win32/EditorWindow.hpp>

bool EditorWindow::registerWndcls()
{
    WNDCLASSEX wc;
    
    wc.cbSize           = sizeof(WNDCLASSEX);
    wc.style            = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc      = callWndproc;
    wc.cbClsExtra       = 0;
    wc.cbWndExtra       = 0;
    wc.hInstance        = GetModuleHandle(NULL);
    wc.hIcon	        = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor          = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground    = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName     = NULL;
    wc.lpszClassName    = TEXT("stroker_EditorWindow");
    wc.hIconSm          = LoadIcon(NULL, IDI_APPLICATION);
    
    return RegisterClassEx(&wc) != 0;
}

EditorWindow::EditorWindow() :
    hwnd_(nullptr)
{
}

LRESULT EditorWindow::dispatchEvent(UINT msg, WPARAM wp, LPARAM lp)
{
    switch( msg ) {
    case WM_CLOSE:
        DestroyWindow(hwnd_);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_PAINT:
		if( deviceResources_.create(hwnd_) ) {
			deviceResources_.beginDraw();
			onRender();
			deviceResources_.endDraw();
		}
		return 0;
	case WM_ERASEBKGND:
		return 0;
	case WM_DISPLAYCHANGE:
		deviceResources_.discard();
		break;
    }
    
    return DefWindowProc(hwnd_, msg, wp, lp);
}

void EditorWindow::onRender()
{
    
}

void EditorWindow::create()
{
    hwnd_ = CreateWindowEx(0,
        TEXT("stroker_EditorWindow"),
        TEXT("stroker"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        nullptr, nullptr, GetModuleHandle(nullptr), this);
    
    ShowWindow(hwnd_, SW_SHOWDEFAULT);
    UpdateWindow(hwnd_);
}
