#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    const char CLASS_NAME[] = "MyWindowClass";
    
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    RegisterClass(&wc);
    
    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, "GDI Text Output",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600, NULL, NULL, hInstance, NULL
    );
    
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            // Устанавливаем прозрачный фон для текста
            SetBkMode(hdc, TRANSPARENT);
            
            // Устанавливаем цвет текста (красный)
            SetTextColor(hdc, RGB(255, 0, 0));
            
            // Получаем размеры клиентской области окна
            RECT rect;
            GetClientRect(hwnd, &rect);
            
            // Текст для вывода
            const char* text = "Hello, GDI!";
            
            // Вычисляем размер текста
            SIZE textSize;
            GetTextExtentPoint32(hdc, text, strlen(text), &textSize);
            
            // Вычисляем координаты для центрирования текста
            int x = (rect.right - textSize.cx) / 2;
            int y = (rect.bottom - textSize.cy) / 2;
            
            // Выводим текст
            TextOut(hdc, x, y, text, strlen(text));
            
            EndPaint(hwnd, &ps);
            return 0;
        }
        
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    
    return DefWindowProc(hwnd, msg, wParam, lParam);
}