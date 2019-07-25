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

	// 중위표기식을 후위표기식으로 변환
	// 변환할 때 각 토큰들을 분리해, 큐를 만들어 넣는다.
	queue<string> InfToPost(string infixStr);

	int parsingPost(queue<string> postfixStr);

	int binaryOpEval(char op, pair<int, int> operand);
	
};
