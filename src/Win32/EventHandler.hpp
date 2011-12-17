#ifndef WIN32_EVENTHANDLER_HPP_
#define WIN32_EVENTHANDLER_HPP_

#include <Win32/Config.hpp>
#include <Windows.h>

template<typename Window>
class EventHandler {
public:
    static LRESULT CALLBACK callWndproc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
    {
        if( msg == WM_CREATE ) {
            CREATESTRUCT* cs = reinterpret_cast<CREATESTRUCT*>(lp);
            
            if( cs->lpCreateParams != nullptr ) {
                SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(cs->lpCreateParams));
            }
        } else {
            Window* wind = reinterpret_cast<Window*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
            
            if( wind != nullptr )
                return wind->dispatchEvent(msg, wp, lp);
        }
        
        return DefWindowProc(hwnd, msg, wp, lp);
    }
};

#endif // WIN32_EVENTHANDLER_HPP_
