#include <windows.h>    
  
LRESULT CALLBACK myWndProc(HWND hWindow, UINT msg, WPARAM wParam, LPARAM lParam);   
     
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)      
{      
  const static TCHAR appName[] = TEXT("Hello world");      
  WNDCLASSEX myWin;      
  myWin.cbSize = sizeof(myWin);      
  myWin.style = CS_HREDRAW | CS_VREDRAW;      
  myWin.lpfnWndProc = myWndProc;      
  myWin.cbClsExtra = 0;      
  myWin.cbWndExtra = 0;      
  myWin.hInstance = hInstance;      
  myWin.hIcon = 0;      
  myWin.hIconSm  = 0;      
  myWin.hCursor = 0;      
  myWin.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);      
  myWin.lpszMenuName = 0;      
  myWin.lpszClassName = appName;      
  //Register      
  if (!RegisterClassEx(&myWin)) return 0;      
  const HWND hWindow = CreateWindow(      
    appName,      
    appName,      
    WS_OVERLAPPEDWINDOW,      
    CW_USEDEFAULT,      
    CW_USEDEFAULT,      
    CW_USEDEFAULT,      
    CW_USEDEFAULT,      
    0,      
    0,      
    hInstance,      
    0);      
  ShowWindow(hWindow,iCmdShow);      
  UpdateWindow(hWindow);      
  {      
    MSG msg;      
    while(GetMessage(&msg,0,0,0))      
    {      
      TranslateMessage(&msg);      
      DispatchMessage(&msg);      
    }      
    return (int)msg.wParam;      
  }      
}      
     
LRESULT CALLBACK myWndProc(HWND hWindow, UINT msg, WPARAM wParam, LPARAM lParam)      
{      
  if (msg==WM_PAINT)      
  {      
    PAINTSTRUCT ps;      
    const HDC hDC = BeginPaint(hWindow,&ps);      
    RECT rect;      
    GetClientRect(hWindow,&rect);      
    DrawText(hDC,TEXT("HELLO WORLD"),-1,&rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);      
    EndPaint(hWindow,&ps);      
    return 0;      
  }      
  else if (msg==WM_DESTROY)      
  {      
    PostQuitMessage(0);      
    return 0;      
  }      
  return DefWindowProc(hWindow,msg,wParam,lParam);      
}  