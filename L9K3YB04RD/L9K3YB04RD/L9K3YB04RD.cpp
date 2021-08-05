#include <iostream>
#include <windows.h>
#include <shellapi.h>
#include <strsafe.h>
#include <time.h> 

#define APPWM_ICONNOTIFY (WM_APP + 1)

using namespace std;

HHOOK hHook = 0;
NOTIFYICONDATA nid = {};
HWND hWnd = GetConsoleWindow();
LONG SEED = (unsigned int)time(NULL);

//HICON hIcon = static_cast<HICON>(LoadImage(NULL,
//    TEXT("L9.ico"),
//    IMAGE_ICON,
//    32, 32,
//    LR_DEFAULTCOLOR | LR_SHARED | LR_DEFAULTSIZE | LR_LOADFROMFILE));

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if ((GetKeyState(VK_CAPITAL) & 0x0001) != 0)
        if (nCode == HC_ACTION)
        {

            KBDLLHOOKSTRUCT* p = (KBDLLHOOKSTRUCT*)lParam;

            KEYBDINPUT kb = { 0 };
            INPUT Input = { 0 };

            cout << p->vkCode << endl;

            //if (wParam == WM_SYSKEYDOWN) {
            //        return 0;
            //}

            if (wParam == WM_KEYDOWN) {

                switch (p->vkCode) {

                // Space
                case 32:
                    SEED = (unsigned int)time(NULL);

                    break;

                // A
                case 65:
                {
                    int x[] = { 0x0034, 0x0041, 0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6 };

                    srand(SEED);
                    kb.wScan = x[rand() % (sizeof(x) / sizeof(*x))];
                    kb.dwFlags = KEYEVENTF_UNICODE;
                    Input.type = INPUT_KEYBOARD;
                    Input.ki = kb;
                    ::SendInput(1, &Input, sizeof(Input));

                    srand(SEED);
                    kb.wScan = x[rand() % (sizeof(x) / sizeof(*x))];
                    kb.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
                    Input.type = INPUT_KEYBOARD;
                    Input.ki = kb;
                    ::SendInput(1, &Input, sizeof(Input));

                    return 1;
                }

                    break;
                //D
                case 68:
                {
                    int x[] = { 0x0044, 0x00D0 };

                    srand(SEED);
                    kb.wScan = x[rand() % (sizeof(x) / sizeof(*x))];
                    kb.dwFlags = KEYEVENTF_UNICODE;
                    Input.type = INPUT_KEYBOARD;
                    Input.ki = kb;
                    ::SendInput(1, &Input, sizeof(Input));

                    srand(SEED);
                    kb.wScan = x[rand() % (sizeof(x) / sizeof(*x))];
                    kb.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
                    Input.type = INPUT_KEYBOARD;
                    Input.ki = kb;
                    ::SendInput(1, &Input, sizeof(Input));

                    return 1;
                }
                    break;
                //E
                case 69:
                {
                    int x[] = { 0x0033, 0x0045, 0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x011A, 0x0118, 0x0116, 0x0114, 0x0112, 0x20AC };

                    srand(SEED);
                    kb.wScan = x[rand() % (sizeof(x) / sizeof(*x))];
                    kb.dwFlags = KEYEVENTF_UNICODE;
                    Input.type = INPUT_KEYBOARD;
                    Input.ki = kb;
                    ::SendInput(1, &Input, sizeof(Input));

                    srand(SEED);
                    kb.wScan = x[rand() % (sizeof(x) / sizeof(*x))];
                    kb.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
                    Input.type = INPUT_KEYBOARD;
                    Input.ki = kb;
                    ::SendInput(1, &Input, sizeof(Input));

                    return 1;
                }
                    break;

                case 73:

                        keybd_event(VK_LSHIFT, 0x2A, 0, 0);
                        keybd_event('I', 0, 0, 0); //Alt Press
                        keybd_event('I', 0, KEYEVENTF_KEYUP, 0);
                        keybd_event(VK_LSHIFT, 0x2A, KEYEVENTF_KEYUP, 0);

                        return 1;

                    break;

                case 76:
                {
                    int x[] = { 0x004C, 0x0141, 0x0139, 0x13B};

                    srand(SEED);
                    kb.wScan = x[rand() % (sizeof(x) / sizeof(*x))];
                    kb.dwFlags = KEYEVENTF_UNICODE;
                    Input.type = INPUT_KEYBOARD;
                    Input.ki = kb;
                    ::SendInput(1, &Input, sizeof(Input));

                    srand(SEED);
                    kb.wScan = x[rand() % (sizeof(x) / sizeof(*x))];
                    kb.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
                    Input.type = INPUT_KEYBOARD;
                    Input.ki = kb;
                    ::SendInput(1, &Input, sizeof(Input));

                    return 1;
                }
                    break;

                case 79:
                {
                    int x[] = { 0x004F, 0x00D6, 0x00D5, 0x00D4, 0x00D3, 0x00D2, 0x00D8, 0x0030, 0x0150 };

                    srand(SEED);
                    kb.wScan = x[rand() % (sizeof(x) / sizeof(*x))];
                    kb.dwFlags = KEYEVENTF_UNICODE;
                    Input.type = INPUT_KEYBOARD;
                    Input.ki = kb;
                    ::SendInput(1, &Input, sizeof(Input));

                    srand(SEED);
                    kb.wScan = x[rand() % (sizeof(x) / sizeof(*x))];
                    kb.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
                    Input.type = INPUT_KEYBOARD;
                    Input.ki = kb;
                    ::SendInput(1, &Input, sizeof(Input));

                    return 1;
                }

                    break;

                case 83:
                {
                    int x[] = { 0x0024, 0x0053 };

                    srand(SEED);
                    kb.wScan = x[rand() % (sizeof(x) / sizeof(*x))];
                    kb.dwFlags = KEYEVENTF_UNICODE;
                    Input.type = INPUT_KEYBOARD;
                    Input.ki = kb;
                    ::SendInput(1, &Input, sizeof(Input));

                    srand(SEED);
                    kb.wScan = x[rand() % (sizeof(x) / sizeof(*x))];
                    kb.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
                    Input.type = INPUT_KEYBOARD;
                    Input.ki = kb;
                    ::SendInput(1, &Input, sizeof(Input));

                    return 1;
                }
                    break;

                //U
                case 85:
                {
                    int x[] = { 0x00D9 , 0x00DA, 0x00DB, 0x00DC, 0x0055 };

                    srand(SEED);
                    kb.wScan = x[rand() % (sizeof(x) / sizeof(*x))];
                    kb.dwFlags = KEYEVENTF_UNICODE;
                    Input.type = INPUT_KEYBOARD;
                    Input.ki = kb;
                    ::SendInput(1, &Input, sizeof(Input));

                    srand(SEED);
                    kb.wScan = x[rand() % (sizeof(x) / sizeof(*x))];
                    kb.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
                    Input.type = INPUT_KEYBOARD;
                    Input.ki = kb;
                    ::SendInput(1, &Input, sizeof(Input));

                    return 1;
                }

                    break;
                case 190:

                        kb.wScan = 0x002C;
                        kb.dwFlags = KEYEVENTF_UNICODE;
                        Input.type = INPUT_KEYBOARD;
                        Input.ki = kb;
                        ::SendInput(1, &Input, sizeof(Input));
                        kb.wScan = 0x002C;
                        kb.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
                        Input.type = INPUT_KEYBOARD;
                        Input.ki = kb;
                        ::SendInput(1, &Input, sizeof(Input));
                        kb.wScan = 0x002C;
                        kb.dwFlags = KEYEVENTF_UNICODE;
                        Input.type = INPUT_KEYBOARD;
                        Input.ki = kb;
                        ::SendInput(1, &Input, sizeof(Input));
                        kb.wScan = 0x002C;
                        kb.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
                        Input.type = INPUT_KEYBOARD;
                        Input.ki = kb;
                        ::SendInput(1, &Input, sizeof(Input));
                        kb.wScan = 0x002C;
                        kb.dwFlags = KEYEVENTF_UNICODE;
                        Input.type = INPUT_KEYBOARD;
                        Input.ki = kb;
                        ::SendInput(1, &Input, sizeof(Input));
                        kb.wScan = 0x002C;
                        kb.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
                        Input.type = INPUT_KEYBOARD;
                        Input.ki = kb;
                        ::SendInput(1, &Input, sizeof(Input));

                        return 1;
                    
                    break;

                case 191:
                {

                    if (GetKeyState(VK_SHIFT) & 0x8000)
                    {

                        int x[] = { 0, 1 };

                        srand(SEED);

                        if (x[rand() % (sizeof(x) / sizeof(*x))] == 0) {

                            kb.wScan = 0x003F;
                            kb.dwFlags = KEYEVENTF_UNICODE;
                            Input.type = INPUT_KEYBOARD;
                            Input.ki = kb;
                            ::SendInput(1, &Input, sizeof(Input));

                            kb.wScan = 0x003F;
                            kb.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
                            Input.type = INPUT_KEYBOARD;
                            Input.ki = kb;
                            ::SendInput(1, &Input, sizeof(Input));

                            kb.wScan = 0x0058;
                            kb.dwFlags = KEYEVENTF_UNICODE;
                            Input.type = INPUT_KEYBOARD;
                            Input.ki = kb;
                            ::SendInput(1, &Input, sizeof(Input));

                            kb.wScan = 0x0058;
                            kb.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
                            Input.type = INPUT_KEYBOARD;
                            Input.ki = kb;
                            ::SendInput(1, &Input, sizeof(Input));

                            kb.wScan = 0x0044;
                            kb.dwFlags = KEYEVENTF_UNICODE;
                            Input.type = INPUT_KEYBOARD;
                            Input.ki = kb;
                            ::SendInput(1, &Input, sizeof(Input));

                            kb.wScan = 0x0044;
                            kb.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
                            Input.type = INPUT_KEYBOARD;
                            Input.ki = kb;
                            ::SendInput(1, &Input, sizeof(Input));

                            return 1;
                        }

                    }

                }

                break;

                }

            }
        
        }
    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

//void AddToTray() {
//    static const int MSG_TRAYICON = WM_USER + 1;
//
//    nid.cbSize = sizeof(nid);
//    nid.hWnd = hWnd;
//    nid.uID = 6969;
//    nid.uFlags = NIF_ICON | NIF_TIP | NIF_MESSAGE;
//    nid.uCallbackMessage = APPWM_ICONNOTIFY;
//    nid.hIcon = hIcon;
//    StringCchCopy(nid.szTip, ARRAYSIZE(nid.szTip), L"L9");
//
//    Shell_NotifyIcon(NIM_ADD, &nid);
//}

//void Minimize()
//{
//    AddToTray();
//    ShowWindow(hWnd, SW_HIDE);
//}

void Restore() {
    Shell_NotifyIcon(NIM_DELETE, &nid);
    ShowWindow(hWnd, SW_SHOW);
}



int main() {

    //ShowWindow(hWnd, SW_HIDE);
    /*AddToTray();*/

    HHOOK hook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, 0,0);
    MSG msg;

    //while loop keeps the hook

    while (!GetMessage(&msg, NULL, NULL, NULL)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }


}

