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

	// unordered_map의 사용법에 주의하자.
	// 내부적으로 pair 객체로 구현되 있다.
	static unordered_map<int, string> m_Map;
	// shift 키가 눌려져 있을 땐 아래의 map에서 string을 가져다 쓴다
	static unordered_map<int, string> m_ShiftMap;

};
