#pragma once
#include <atlbase.h>
#include <windows.h>
#include <string>

using namespace std;

class TextIndicator {
public:

	static bool outputFlag;

	static void drawOutline(HDC hdc) {
		Rectangle(hdc, left, top + 5, right - 7, bottom + 5);
	}

	static void append(string ch) {
		inputStr += ch;
	}

	static void drawText(HDC hdc) {
		USES_CONVERSION;
		DrawText(hdc, CA2T(inputStr.c_str()), inputStr.size(), &inputTextRange, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);

	}

	static void back() {
		inputStr = inputStr.substr(0, inputStr.length() - 1);
	}

	static void clear() {
		inputStr = "";
	}

	static void setOutput(string output) {
		outputStr = output;
		outputFlag = true;
	}

	static void showResult(HDC hdc) {
		USES_CONVERSION;
		DrawText(hdc, CA2T(outputStr.c_str()), outputStr.size(), &outputTextRange, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
		outputFlag = false;
	}

	static string inputExpression() {
		return inputStr;
	}


private:
	
	static RECT inputTextRange;
	static RECT outputTextRange;

	// 현재 입력 중인 텍스트
	static string inputStr;
	static string outputStr;

	static const int left = 25;
	static const int right = 325;
	static const int top = 25;
	static const int bottom = 90;

};
