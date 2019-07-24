#pragma once
#include <atlbase.h>
#include <windows.h>

class TextIndicator {
public:

	static TextIndicator* getInstance() {
		if (Instance == nullptr) Instance = new TextIndicator();
		return Instance;
	}

	static void drawOutline(HDC hdc) {
		Rectangle(hdc, left, top, right, bottom);
	}

	void append(HDC hdc, char ch) {
		USES_CONVERSION;
		inputStr += ch;
		DrawText(hdc, CA2T(inputStr.c_str()), inputStr.size(), &TextRange, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
	}

	void drawText(HDC hdc) {
		USES_CONVERSION;
		DrawText(hdc, CA2T(inputStr.c_str()), inputStr.size(), &TextRange, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
	}

	void clear() {
		inputStr = "";
	}

	string value() {
		return inputStr;
	}


private:
	
	RECT TextRange;

	// 현재 입력 중인 텍스트
	string inputStr;

	TextIndicator() {
		inputStr = "";
		TextRange.left = left;
		TextRange.right = right;
		TextRange.top = top;
		TextRange.bottom = bottom;
	}

	static TextIndicator* Instance;

	static const int left = 25;
	static const int right = 325;
	static const int top = 25;
	static const int bottom = 90;

};

TextIndicator* TextIndicator::Instance = nullptr;
