#pragma once
#include <stack>
#include <iostream>
#include <string>

using namespace std;

class Calculator {
public:

	static int calculate(string infixStr);

	static Calculator* getInstance() {
		if (Instance == nullptr) Instance = new Calculator();
		return Instance;
	}

private:

	Calculator() {}

	static Calculator* Instance;

	static string InfToPost(string infixStr);

	static int parsingPost(string postfixStr);

	static int binaryOpEval(char op, pair<int, int> operand);
};

Calculator* Calculator::Instance = nullptr;