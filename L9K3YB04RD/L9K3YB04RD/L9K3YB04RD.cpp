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
time_t SEED = time(NULL);

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

            int CURRENT;

            cout << p->vkCode << endl;

            //if (wParam == WM_SYSKEYDOWN) {
            //        return 0;
            //}

            if (wParam == WM_KEYDOWN) {

                switch (p->vkCode) {

                    // Space
                case 32:

                    srand(time(NULL));

                    break;

                case 65:

                        keybd_event('4', 0, 0, 0);
                        keybd_event('4', 0, KEYEVENTF_KEYUP, 0);

                        return 1;

                    break;

                case 73:

                        keybd_event(VK_LSHIFT, 0x2A, 0, 0);
                        keybd_event('I', 0, 0, 0); //Alt Press
                        keybd_event('I', 0, KEYEVENTF_KEYUP, 0);
                        keybd_event(VK_LSHIFT, 0x2A, KEYEVENTF_KEYUP, 0);

                        return 1;

                    break;


                case 79:

                        keybd_event('0', 0, 0, 0);
                        keybd_event('0', 0, KEYEVENTF_KEYUP, 0);

                        return 1;

                    break;

                case 83:
                {


                    kb.wScan = CURRENT;
                    kb.dwFlags = KEYEVENTF_UNICODE;
                    Input.type = INPUT_KEYBOARD;
                    Input.ki = kb;
                    ::SendInput(1, &Input, sizeof(Input));

                    kb.wScan = CURRENT;
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

