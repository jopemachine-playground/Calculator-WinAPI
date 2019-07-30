#pragma once
#include "Button.h"

// 마우스로 버튼을 클릭했을 때 호출할 key들의 모음
const std::unordered_map<Button::IDC_BUTTON_ID, int> Button::m_Map = {
	{ IDC_BUTTON_0, 0x30 },
	{ IDC_BUTTON_1, 0x31 },
	{ IDC_BUTTON_2, 0x32 },
	{ IDC_BUTTON_3, 0x33 },
	{ IDC_BUTTON_4, 0x34 },
	{ IDC_BUTTON_5, 0x35 },
	{ IDC_BUTTON_6, 0x36 },
	{ IDC_BUTTON_7, 0x37 },
	{ IDC_BUTTON_8, 0x38 },
	{ IDC_BUTTON_9, 0x39 },
	{ IDC_BUTTON_PLUS, VK_ADD },
	{ IDC_BUTTON_MINUS, VK_SUBTRACT },
	{ IDC_BUTTON_MULTIPLY, VK_MULTIPLY },
	{ IDC_BUTTON_DIVIDE, VK_DIVIDE },
};

int Button::VkKeyValue(IDC_BUTTON_ID id) {
	return m_Map.at(id);
}	

HWND Button::generate(HWND hWnd, HINSTANCE hInst, int position_x, int position_y, int size_x, int size_y, string text, IDC_BUTTON_ID id) {

	USES_CONVERSION;

	// CA2T : https://www.codeproject.com/Questions/396705/How-to-convert-string-to-LPCTSTR 참고
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
		(HMENU)id,
		hInst,
		NULL
	);
}