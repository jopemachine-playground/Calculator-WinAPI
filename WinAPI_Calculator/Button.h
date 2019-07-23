#pragma once
#include <atlbase.h>
#include <windows.h>

#define BUTTON_SIZE_X 50
#define BUTTON_SIZE_Y 50

class Button {
public:

	static HWND generate(HWND hWnd, HINSTANCE hInst, int position_x, int position_y, string text) {

		USES_CONVERSION;

		return CreateWindow(
			TEXT("button"),
			CA2T(text.c_str()),
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			position_x, // position of x
			position_y, // position of y
			BUTTON_SIZE_X, // x
			BUTTON_SIZE_Y, // y
			hWnd,
			(HMENU)0,
			hInst,
			NULL
		);
	}

	static HWND generate(HWND hWnd, HINSTANCE hInst, int position_x, int position_y, int size_x, int size_y, string text) {
		
		USES_CONVERSION;

		// CA2T : https://www.codeproject.com/Questions/396705/How-to-convert-string-to-LPCTSTR Âü°í
		// string to LPCTSTR
		return CreateWindow(
			TEXT("button"),
			CA2T(text.c_str()),
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			position_x, // position of x
			position_y, // position of y
			size_x, // x
			size_y, // y
			hWnd,
			(HMENU)0,
			hInst,
			NULL
		);
	}

private:
	
};