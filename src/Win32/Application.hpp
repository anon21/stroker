#ifndef WIN32_APPLICATION_HPP_
#define WIN32_APPLICATION_HPP_

#include <Win32/Config.hpp>
#include <Windows.h>

class Application {
public:
    static Application& getInstance() { return app_; }
    
    int bootstrap();
    
private:
    static Application app_;
    
    Application() {}
    Application(Application const&) {}
    
    bool initialize();
    void finish();
    int messageLoop();
};

#endif // WIN32_APPLICATION_HPP_
