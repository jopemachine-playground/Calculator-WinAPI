#pragma once
#include <unordered_map>
#include <atlbase.h>
#include <windows.h>

using namespace std;

class Button {
public:

	struct ButtonEvent {
		int vk_value;
		bool isShifted;
	};

	enum IDC_BUTTON_ID{
		IDC_BUTTON_0 = 200,
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
	
	static Button::ButtonEvent VkKeyValue(IDC_BUTTON_ID id);

	static HWND generate(
		HWND hWnd, 
		HINSTANCE hInst, 
		int position_x, 
		int position_y, 
		int size_x, 
		int size_y, 
		string text, 
		IDC_BUTTON_ID id
	);

private:

	static unordered_map<IDC_BUTTON_ID, ButtonEvent> m_Map;

};
