#pragma once
#include <atlbase.h>
#include <windows.h>
#include <string>

using namespace std;

class TextIndicator {
public:

	static bool outputFlag;

	static void drawOutline(HDC);

	static void append(string);

	static void drawText(HDC);

	static void back();

	static void clear();

	static void setOutput(string);

	static void showResult(HDC);

	static string inputExpression();


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
