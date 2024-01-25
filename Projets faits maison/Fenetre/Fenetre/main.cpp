#include <windows.h>

// Boring preprocessing
#define FILE_MENU_NEW 1
#define FILE_MENU_OPEN 2
#define FILE_MENU_EXIT 3
#define MENU_HELP 4

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

HMENU hMenu;

void AddMenus(HWND);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
	// Sets the background, cursor, window instance and class name
	WNDCLASSW wc = { 0 };

	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInst;
	wc.lpszClassName = L"MyWindowClass";
	wc.lpfnWndProc = WindowProcedure;


	// If you can't register the window class, return -1
	if (!RegisterClassW(&wc))
		return -1;

	// Create the window
	CreateWindowW(L"MyWindowClass", L"MyWindow", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);

	MSG msg = { 0 };

	// Take care of what the user is doing (message)
	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{

	// Different cases of what the user can do
	switch (msg)
	{
	case WM_COMMAND:

		switch (wp)
		{
		// File -> New Button
		case FILE_MENU_NEW:
			MessageBox(hWnd, L"This should create a new file... \"SHOULD\"", L"Congrats !", MB_OK);
			break;

		// File -> Open Button
		case FILE_MENU_OPEN:
			MessageBox(hWnd, L"This will do something eventually...", L"This is awkward...", MB_RIGHT);
			break;

		// File -> Exit Button
		case FILE_MENU_EXIT:
			PostQuitMessage(0);
			break;
		// Help Button
		case MENU_HELP:
			MessageBox(hWnd, L"You clicked the help button !", L"Congratulations !", MB_OK);
		}

		break;
	// On window start, display the menus
	case WM_CREATE:
		AddMenus(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProcW(hWnd, msg, wp, lp);
	}
}

void AddMenus(HWND hWnd)
{
	// Creation of local menus (that don't need to be used in the global scope)
	hMenu = CreateMenu();
	HMENU hFileMenu = CreateMenu();
	HMENU hSubMenu = CreateMenu();

	// Adding them all to our window
	AppendMenuW(hSubMenu, MF_STRING, NULL, L"This is the submenu");

	AppendMenuW(hFileMenu, MF_STRING, FILE_MENU_NEW, L"New");
	AppendMenuW(hFileMenu, MF_STRING, FILE_MENU_OPEN, L"Open");
	AppendMenuW(hFileMenu, MF_POPUP, (UINT_PTR)hSubMenu, L"SubMenu");

	AppendMenuW(hFileMenu, MF_SEPARATOR, NULL, NULL);

	AppendMenuW(hFileMenu, MF_STRING, FILE_MENU_EXIT, L"Exit");


	AppendMenuW(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, L"File");
	AppendMenuW(hMenu, MF_STRING, MENU_HELP, L"Help");

	// Once everything is added to the menu list, display them on screen
	SetMenu(hWnd, hMenu);
}