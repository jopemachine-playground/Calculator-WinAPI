#pragma once
#include <atlbase.h>
#include <windows.h>

class Button {
public:

	enum IDC_BUTTON_ID{
		IDC_BUTTON_0 = 100,
		IDC_BUTTON_1,
		IDC_BUTTON_2,
		IDC_BUTTON_3,
		IDC_BUTTON_4,
		IDC_BUTTON_5,
		IDC_BUTTON_6,
		IDC_BUTTON_7,
		IDC_BUTTON_8,
		IDC_BUTTON_9,
		IDC_BUTTON_LP,
		IDC_BUTTON_RP,
		IDC_BUTTON_BACK,
		IDC_BUTTON_CLEAR,
		IDC_BUTTON_DOT,
		IDC_BUTTON_PLUS,
		IDC_BUTTON_MINUS,
		IDC_BUTTON_MULTIPLY,
		IDC_BUTTON_DIVIDE,
		IDC_BUTTON_EQU,
	};

	static HWND generate(HWND hWnd, HINSTANCE hInst, int position_x, int position_y, int size_x, int size_y, string text, IDC_BUTTON_ID id) {
		
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
			(HMENU) id,
			hInst,
			NULL
		);
	}

	
};