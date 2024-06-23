#include <windows.h>

// ���ڹ��̺�������������Ϣ
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

// ������ڵ�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // ע�ᴰ����
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;                 // ���ڹ��̺���
    wc.hInstance = hInstance;                  // ����ʵ�����
    wc.lpszClassName = "MyWindowClass";        // ����������
    RegisterClass(&wc);

    // ��������
    HWND hwnd = CreateWindow(
        "MyWindowClass",                       // ����������
        "Hello, Windows!",                     // ���ڱ���
        WS_OVERLAPPEDWINDOW,                   // ������ʽ
        CW_USEDEFAULT, CW_USEDEFAULT,          // ����λ�ã�Ĭ�ϣ�
        500, 300,                              // ���ڴ�С
        NULL, NULL, hInstance, NULL
    );

    // ��ʾ����
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // ��Ϣѭ��
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}
