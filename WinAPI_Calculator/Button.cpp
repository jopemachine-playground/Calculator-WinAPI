#pragma once
#include "Button.h"

// ���콺�� ��ư�� Ŭ������ �� ȣ���� key���� ����
std::unordered_map<Button::IDC_BUTTON_ID, Button::ButtonEvent> Button::m_Map = {
	{ IDC_BUTTON_0, { 0x30, false }},
	{ IDC_BUTTON_1, { 0x31, false }},
	{ IDC_BUTTON_2, { 0x32, false }},
	{ IDC_BUTTON_3, { 0x33, false }},
	{ IDC_BUTTON_4, { 0x34, false }},
	{ IDC_BUTTON_5, { 0x35, false }},
	{ IDC_BUTTON_6, { 0x36, false }},
	{ IDC_BUTTON_7, { 0x37, false }},
	{ IDC_BUTTON_8, { 0x38, false }},
	{ IDC_BUTTON_9, { 0x39, false }},
	{ IDC_BUTTON_PLUS, { VK_ADD, false }} ,
	{ IDC_BUTTON_MINUS, { VK_SUBTRACT, false }},
	{ IDC_BUTTON_MULTIPLY, { VK_MULTIPLY, false }},
	{ IDC_BUTTON_DIVIDE, { VK_DIVIDE, false }},
	{ IDC_BUTTON_BACK, { VK_BACK, false }},
	{ IDC_BUTTON_LP, { 0x39, true }},
	{ IDC_BUTTON_RP, { 0x30, true }},
	{ IDC_BUTTON_EQU, { VK_RETURN, false }},
	{ IDC_BUTTON_CLEAR, { VK_BACK, true }}
};

Button::ButtonEvent Button::VkKeyValue(IDC_BUTTON_ID id) {
	return m_Map.at(id);
}

HWND Button::generate(HWND hWnd, HINSTANCE hInst, int position_x, int position_y, int size_x, int size_y, string text, IDC_BUTTON_ID id) {

	USES_CONVERSION;

	// CA2T : https://www.codeproject.com/Questions/396705/How-to-convert-string-to-LPCTSTR ����
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
