#pragma once
#include <stack>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

class Calculator {
public:

	double calculate(string infixStr);

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

	double parsingPost(queue<string> postfixStr);

	double binaryOpEval(char op, pair<double, double> operand);
	
};
