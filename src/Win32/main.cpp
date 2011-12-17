#include <Win32/Application.hpp>

int WINAPI wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{
    return Application::getInstance().bootstrap();
}
