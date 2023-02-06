#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main(void)
{
    /*修改字体*/
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof cfi;
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0; //字体宽
    cfi.dwFontSize.Y = 30; //字体高, 若字体宽为0, 则为字体大小
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL; //字体粗细 粗体FW_BOLD
    wcscpy_s(cfi.FaceName, L"楷体"); //设置字体
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi); //应用
    /*结束修改字体*/

    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFO consoleCurrentFont;
    POINT a;
    HWND h = GetForegroundWindow();

    /*移除快速编辑模式*/
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    mode &= ~ENABLE_QUICK_EDIT_MODE;
    SetConsoleMode(hStdin, mode);
    /*结束移除快速编辑模式*/

    while (1)
    {
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
        {
            GetCursorPos(&a);
            ScreenToClient(h, &a);
            GetCurrentConsoleFont(hOutput, FALSE, &consoleCurrentFont);
            int x = a.x / consoleCurrentFont.dwFontSize.X;
            int y = a.y / consoleCurrentFont.dwFontSize.Y;
            COORD pos = {(SHORT)x, (SHORT)y};
            SetConsoleCursorPosition(hOutput, pos);
            cout << '0';
        }
    }
    return 0;
}