#pragma once
#include "KeyMapper.h"
#include "TextIndicator.h"

std::unordered_map<int, string> KeyMapper::m_Map = {
		{ VK_OEM_PLUS, " + " },
		{ VK_ADD, " + " },
		{ VK_OEM_MINUS, " - " },
		{ VK_SUBTRACT, " - " },
		{ VK_MULTIPLY, " * " },
		{ VK_DIVIDE, " / " },
		{ 0xBF, " / " },

		{ 0x30, "0" },
		{ 0x60, "0" },
		{ 0x31, "1" },
		{ 0x61, "1" },
		{ 0x32, "2" },
		{ 0x62, "2" },
		{ 0x33, "3" },
		{ 0x63, "3" },
		{ 0x34, "4" },
		{ 0x64, "4" },
		{ 0x35, "5" },
		{ 0x65, "5" },
		{ 0x36, "6" },
		{ 0x66, "6" },
		{ 0x37, "7" },
		{ 0x67, "7" },
		{ 0x38, "8" },
		{ 0x68, "8" },
		{ 0x39, "9" },
		{ 0x69, "9" },
};

// Shift 버튼을 누른 채 입력했을 때 입력되는 키 모음
std::unordered_map<int, string> KeyMapper::m_ShiftMap = {
	{ VK_OEM_PLUS, " + " },
	{ VK_OEM_MINUS, " - " },
	{ 0x38, " * " },
	{ 0x39 , " ( " },
	{ 0x30 , " ) " }
};

void KeyMapper::KeyPressed(HWND hWnd, TCHAR input, bool& shiftKeyFlag, queue<string>& inputQue) {

	SetFocus(hWnd);

	static Calculator* calculator = Calculator::getInstance();

	if (input == VK_SHIFT) shiftKeyFlag = true;

	if (input == VK_BACK) shiftKeyFlag ? TextIndicator::clear() : TextIndicator::back();

	if (input == VK_RETURN) {
		string input = TextIndicator::inputExpression();
		TextIndicator::setOutput(to_string(calculator->calculate(input)));
	}

	string mappingValue = mappingInputToValue(input, shiftKeyFlag);
	if (mappingValue != "") inputQue.push(mappingValue);

	InvalidateRect(hWnd, NULL, FALSE);
}

string KeyMapper::mappingInputToValue(int key, bool isShifted = false) {

	auto map = isShifted ? m_ShiftMap : m_Map;

	auto it = map.find(key);

	if (it != map.end()) {
		return it->second;
	}
	return "";
}