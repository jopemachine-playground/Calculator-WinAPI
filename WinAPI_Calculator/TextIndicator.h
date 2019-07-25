#pragma once
#include <atlbase.h>
#include <windows.h>

using namespace std;

class TextIndicator {
public:

	static bool outputFlag;

	static TextIndicator* getInstance() {
		if (Instance == nullptr) Instance = new TextIndicator();
		return Instance;
	}

	static void drawOutline(HDC hdc) {
		Rectangle(hdc, left + 5, top + 5, right - 7, bottom + 5);
	}

	void append(HDC hdc, string ch) {
		inputStr += ch;
	}

	void drawText(HDC hdc) {
		USES_CONVERSION;
		DrawText(hdc, CA2T(inputStr.c_str()), inputStr.size(), &inputTextRange, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
	}

	void back() {
		inputStr = inputStr.substr(0, inputStr.length() - 1);
	}

	void clear() {
		inputStr = "";
	}

	void setOutput(string output) {
		outputStr = output;
		outputFlag = true;
	}

	void showResult(HDC hdc) {
		USES_CONVERSION;
		DrawText(hdc, CA2T(outputStr.c_str()), outputStr.size(), &outputTextRange, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
		outputFlag = false;
	}

	string inputExpression() {
		return inputStr;
	}


private:
	
	RECT inputTextRange;
	RECT outputTextRange;

	// 현재 입력 중인 텍스트
	string inputStr;
	string outputStr;

	TextIndicator() {
		inputStr = "";
		inputTextRange.left = left;
		inputTextRange.right = right;
		inputTextRange.top = top;
		inputTextRange.bottom = bottom;

		outputTextRange.left = left;
		outputTextRange.right = right;
		outputTextRange.top = inputTextRange.top + 10;
		outputTextRange.bottom = inputTextRange.bottom + 30;
	}

	static TextIndicator* Instance;

	static const int left = 25;
	static const int right = 325;
	static const int top = 25;
	static const int bottom = 90;

};

TextIndicator* TextIndicator::Instance = nullptr;
bool TextIndicator::outputFlag = false;