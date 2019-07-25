#pragma once
#include <unordered_map>

using namespace std;

class KeyMapper {
public:

	static KeyMapper* getInstance() {
		if (Instance == nullptr) Instance = new KeyMapper();
		return Instance;
	}

	string mappingInputToValue(int key, bool isShifted = false) {

		auto map = isShifted ? m_ShiftMap : m_Map;
		
		auto it = map.find(key);

		if (it != map.end()) {
			return it->second;
		}
		return "";
	}

private:
	
	static KeyMapper* Instance;

	// unordered_map의 사용법에 주의하자.
	// 내부적으로 pair 객체로 구현되 있다.
	unordered_map<int, string> m_Map;
	// shift 키가 눌려져 있을 땐 아래의 map에서 string을 가져다 쓴다
	unordered_map<int, string> m_ShiftMap;

	KeyMapper() {
		m_Map.insert({ VK_OEM_PLUS, " + " });
		m_Map.insert({ VK_ADD, " + " });
		m_Map.insert({ VK_OEM_MINUS, " - " });
		m_Map.insert({ VK_SUBTRACT, " - " });
		m_Map.insert({ VK_MULTIPLY, " * " });
		m_Map.insert({ VK_DIVIDE, " / " });
		m_Map.insert({ 0xBF, " / " });

		m_Map.insert({ 0x30, "0" });
		m_Map.insert({ 0x60, "0" });
		m_Map.insert({ 0x31, "1" });
		m_Map.insert({ 0x61, "1" });
		m_Map.insert({ 0x32, "2" });
		m_Map.insert({ 0x62, "2" });
		m_Map.insert({ 0x33, "3" });
		m_Map.insert({ 0x63, "3" });
		m_Map.insert({ 0x34, "4" });
		m_Map.insert({ 0x64, "4" });
		m_Map.insert({ 0x35, "5" });
		m_Map.insert({ 0x65, "5" });
		m_Map.insert({ 0x36, "6" });
		m_Map.insert({ 0x66, "6" });
		m_Map.insert({ 0x37, "7" });
		m_Map.insert({ 0x67, "7" });
		m_Map.insert({ 0x38, "8" });
		m_Map.insert({ 0x68, "8" });
		m_Map.insert({ 0x39, "9" });
		m_Map.insert({ 0x69, "9" });

		m_ShiftMap.insert({ VK_OEM_PLUS, " + " });
		m_ShiftMap.insert({ VK_OEM_MINUS, " - " });
		m_ShiftMap.insert({ 0x38, " * " });
		m_ShiftMap.insert({ 0x39 , " ( " });
		m_ShiftMap.insert({ 0x30 , " ) " });
	}

};

KeyMapper* KeyMapper::Instance = nullptr;