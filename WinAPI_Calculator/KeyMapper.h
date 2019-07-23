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

private:

	static KeyMapper* Instance;

	// unordered_map의 사용법에 주의하자.
	// 내부적으로 pair 객체로 구현되 있다.
	unordered_map<char, int> m_Map;

	KeyMapper() {
		m_Map.insert({ '1', 0x31 });
		m_Map.insert({ '2', 0x32 });
		m_Map.insert({ '3', 0x33 });
		m_Map.insert({ '4', 0x34 });
		m_Map.insert({ '5', 0x35 });
		m_Map.insert({ '6', 0x36 });
		m_Map.insert({ '7', 0x37 });
		m_Map.insert({ '8', 0x38 });
		m_Map.insert({ '9', 0x39 });
	}

};

KeyMapper* KeyMapper::Instance = nullptr;