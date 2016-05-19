///////////////////////////////////////////////////////////////////////////////////////////
//                  INITIALIZE WINDOW AND HANDLE MAINLOOP
///////////////////////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <AvniInterfaces.h>
#include <ConfigurationManager.h>
#include <Singletons.h>
using namespace Avni;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int __stdcall WinMain(__in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in_opt LPSTR lpCmdLine, __in int nShowCmd)
{
    MSG msg = { 0 };

    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
    wc.lpszClassName = L"AVNI";
    wc.style = CS_OWNDC;

    if (!RegisterClass(&wc))
        return 1;

    HWND HWND = CreateWindowW(wc.lpszClassName, L"AVNI", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, 854, 480, 0, 0, hInstance, 0);

    CONFIGURATIONMANAGER->SetHWND((void*)HWND);
    CONFIGURATIONMANAGER->SetWindowed(true);
    CONFIGURATIONMANAGER->Initialize(Config_WIN32_Directx11);

    bool quit = false;
    while (HWND != INVALID_HANDLE_VALUE && !quit)
    {
        if (PeekMessage(&msg, NULL, 0, 0,PM_REMOVE) > 0)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        quit = CONFIGURATIONMANAGER->Update() || CONFIGURATIONMANAGER->GetShouldQuit();
    }


    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_KEYDOWN:
        {
            //app->OnKeyDown(_WParam);
            return 0;
        }
        case WM_DESTROY:
        {
			CONFIGURATIONMANAGER->SetShouldQuit(true);
            PostQuitMessage(0);
            return 0;
        }
        default:
        {
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    return 0;

}