#include <Win32/Application.hpp>
#include <Win32/D2DManager.hpp>
#include <Win32/EditorWindow.hpp>
#include <memory>

Application Application::app_;

int Application::bootstrap()
{
    int exitCode = -1;
    
    if( initialize() ) {
        {
            auto wind = std::make_shared<EditorWindow>();
            wind->create();
            
            exitCode = messageLoop();
        }
        
        finish();
    }
    
    return exitCode;
}

bool Application::initialize()
{
    // register window classes
    if( !EditorWindow::registerWndcls() )
        return false;
    
    // initialize Direct2D and DirectWrite factories
    if( !D2DManager::getInstance().initialize() )
        return false;
    
    return true;
}

void Application::finish()
{
    D2DManager::getInstance().finish();
}

int Application::messageLoop()
{
    MSG msg;
    
    while( GetMessage(&msg, nullptr, 0, 0) > 0 ) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return msg.wParam;
}
