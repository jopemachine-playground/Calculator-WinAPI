#pragma once
#include <unordered_map>

using namespace std;

class KeyMapper {
public:

	static KeyMapper* getInstance() {
		if (Instance == nullptr) Instance = new KeyMapper();
		return Instance;
	}

	int value(char key) {

		// 해당 map의 원하는 value 값 반환
		return m_Map.find(key)->second;
	}

	char isProperInput(char key) {
		auto it = m_Map.find(key);

		if (it != m_Map.end()) {
			return it->second;
		}
		return NULL;
	}

	string isOperator(char key) {
		switch (key) {
			case VK_OEM_PLUS:
			case VK_ADD:
				return " + ";
			case VK_SUBTRACT:
			case VK_OEM_MINUS:
				return " - ";
			case VK_MULTIPLY:
				return " * ";
			case VK_DIVIDE:
				return " / ";
		}
		return "";
	}

private:
	
	static KeyMapper* Instance;

	// unordered_map의 사용법에 주의하자.
	// 내부적으로 pair 객체로 구현되 있다.
	unordered_map<int, char> m_Map;

	KeyMapper() {
		m_Map.insert({ 0x30, '0' });
		m_Map.insert({ 0x60, '0' });
		m_Map.insert({ 0x31, '1' });
		m_Map.insert({ 0x61, '1' });
		m_Map.insert({ 0x32, '2' });
		m_Map.insert({ 0x62, '2' });
		m_Map.insert({ 0x33, '3' });
		m_Map.insert({ 0x63, '3' });
		m_Map.insert({ 0x34, '4' });
		m_Map.insert({ 0x64, '4' });
		m_Map.insert({ 0x35, '5' });
		m_Map.insert({ 0x65, '5' });
		m_Map.insert({ 0x36, '6' });
		m_Map.insert({ 0x66, '6' });
		m_Map.insert({ 0x37, '7' });
		m_Map.insert({ 0x67, '7' });
		m_Map.insert({ 0x38, '8' });
		m_Map.insert({ 0x68, '8' });
		m_Map.insert({ 0x39, '9' });
		m_Map.insert({ 0x69, '9' });
	}

};

KeyMapper* KeyMapper::Instance = nullptr;