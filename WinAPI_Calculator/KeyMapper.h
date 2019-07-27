#pragma once
#include <unordered_map>
#include <windows.h>

#include "Calculator.h"

using namespace std;

class KeyMapper {
public:

	static void KeyPressed(HWND hWnd, TCHAR input, bool& shiftKeyFlag, queue<string>& inputQue);

	static string mappingInputToValue(int key, bool isShifted);

private:

	// unordered_map�� ������ ��������.
	// ���������� pair ��ü�� ������ �ִ�.
	static unordered_map<int, string> m_Map;
	// shift Ű�� ������ ���� �� �Ʒ��� map���� string�� ������ ����
	static unordered_map<int, string> m_ShiftMap;

};
