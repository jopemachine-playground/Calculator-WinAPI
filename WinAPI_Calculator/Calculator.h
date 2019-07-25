#pragma once
#include <stack>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

class Calculator {
public:

	int calculate(string infixStr);

	static Calculator* getInstance() {
		if (Instance == nullptr) Instance = new Calculator();
		return Instance;
	}

private:

	Calculator() {}

	static Calculator* Instance;

	// ����ǥ����� ����ǥ������� ��ȯ
	// ��ȯ�� �� �� ��ū���� �и���, ť�� ����� �ִ´�.
	queue<string> InfToPost(string infixStr);

	int parsingPost(queue<string> postfixStr);

	int binaryOpEval(char op, pair<int, int> operand);
	
};
