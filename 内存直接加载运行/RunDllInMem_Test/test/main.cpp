#include <windows.h>

// 窗口过程函数，处理窗口消息
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

// 程序入口点
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // 注册窗口类
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;                 // 窗口过程函数
    wc.hInstance = hInstance;                  // 程序实例句柄
    wc.lpszClassName = "MyWindowClass";        // 窗口类名称
    RegisterClass(&wc);

    // 创建窗口
    HWND hwnd = CreateWindow(
        "MyWindowClass",                       // 窗口类名称
        "Hello, Windows!",                     // 窗口标题
        WS_OVERLAPPEDWINDOW,                   // 窗口样式
        CW_USEDEFAULT, CW_USEDEFAULT,          // 窗口位置（默认）
        500, 300,                              // 窗口大小
        NULL, NULL, hInstance, NULL
    );

    // 显示窗口
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // 消息循环
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}
