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

		// �ش� map�� ���ϴ� value �� ��ȯ
		return m_Map.find(key)->second;
	}

	bool isProperInput(char key) {
		auto it = m_Map.find(key);

		if (it != m_Map.end()) {
			return true;
		}
		return false;
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

	// unordered_map�� ������ ��������.
	// ���������� pair ��ü�� ������ �ִ�.
	unordered_map<char, int> m_Map;

	KeyMapper() {
		m_Map.insert({ '0', 0x30 });
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