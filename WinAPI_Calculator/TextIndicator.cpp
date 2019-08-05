#pragma once
#include "TextIndicator.h"

bool TextIndicator::outputFlag = false;

string TextIndicator::inputStr = "";
string TextIndicator::outputStr = "";

RECT TextIndicator::inputTextRange = { 
	left,
	top - 10,
	right - 20, 
	bottom 
};

RECT TextIndicator::outputTextRange = { 
	left, 
	top + 10,
	right - 20, 
	bottom + 30 
};

void TextIndicator::showResult(HDC& hdc) {

	// 소수 부분이 0이라면, 따로 표기하지 않는다.
	int integerValue = atoi(outputStr.c_str());
	double fractionValue = atof(outputStr.c_str()) - integerValue;

	if (!fractionValue) {
		outputStr = to_string(integerValue);
	}

	USES_CONVERSION;
	DrawText(hdc, CA2T(outputStr.c_str()), outputStr.size(), &outputTextRange, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
	outputFlag = false;
}

string TextIndicator::inputExpression() {
	return inputStr;
}

void TextIndicator::clear() {
	inputStr = "";
}

void TextIndicator::back() {
	inputStr = inputStr.substr(0, inputStr.length() - 1);
}

void TextIndicator::drawText(HDC& hdc) {
	USES_CONVERSION;
	DrawText(hdc, CA2T(inputStr.c_str()), inputStr.size(), &inputTextRange, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
}

void TextIndicator::append(string ch) {
	inputStr += ch;
}

void TextIndicator::drawOutline(HDC& hdc) {
	Rectangle(hdc, left, top + 5, right - 7, bottom + 5);
}