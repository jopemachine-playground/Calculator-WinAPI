#pragma once
#include "Utility.h"
#include "Calculator.h"

using namespace std;

Calculator* Calculator::Instance = nullptr;

double Calculator::calculate(string infixStr) {
	return parsingPost(InfToPost(infixStr));
}

// 중위 표기식을 후위 표기식으로 바꿔 반환하는 함수
queue<string> Calculator::InfToPost(string infixStr) {
	
	// 변환을 위한 스택
	stack<string> stk;
	// 후위 표기식으로 변환한 후의 토큰들 
	queue<string> ret;
	// 중위 표기식의 토큰들
	vector<string> tokens = Utility::split(infixStr, ' ');

	for (auto iter = tokens.begin(); iter != tokens.end(); ++iter) {
		
		string token = (*iter);

		// 우선순위 1
		if (token == "*" || token == "/") {

			while (!stk.empty() &&
				(stk.top() == "*" || stk.top() == "/")) {
				ret.push(stk.top());
				stk.pop();
			}
			stk.push(token);
		}

		// 우선순위 2
		else if (token == "+" || token == "-") {

			while (!stk.empty() && stk.top() != "(") {
				ret.push(stk.top());
				stk.pop();
			}
			stk.push(token);
		}

		// 우선순위 3
		else if (token == "(") {
			stk.push("(");
		}

		// 우선순위 4
		else if (token == ")") {

			while (stk.top() != "(") {

				ret.push(stk.top());
				stk.pop();

			}
			stk.pop();
		}

		// 그 외 
		else {
			ret.push(token);
		}
	}

	while (!stk.empty()) {
		ret.push(stk.top());
		stk.pop();
	}

	// for Debugging
	
	/*
		while (!ret.empty()) {
			string elem = ret.front();
			cout << elem;
			ret.pop();
		}
	*/

	return ret;
}

double Calculator::parsingPost(queue<string> tokens) {

	// 계산을 위한 스택
	stack<string> stk;

	while(!tokens.empty()) {
		// 연산자를 만난 경우 스택에서 피연산자 2개를 꺼내 연산을 수행한다 
		if (tokens.front() == "*" ||
			tokens.front() == "/" ||
			tokens.front() == "+" ||
			tokens.front() == "-") {

			if (stk.empty()) {
				// 에러 처리
			}
			double operand1 = atoi(stk.top().c_str());
			stk.pop();
			double operand2 = atoi(stk.top().c_str());
			stk.pop();

			auto r = to_string(binaryOpEval(*(tokens.front().c_str()), { operand1, operand2 }));

			stk.push(to_string(binaryOpEval(*(tokens.front().c_str()), { operand1, operand2 })));
			tokens.pop();
			continue;
		}

		stk.push(tokens.front());
		tokens.pop();
	}

	if (stk.empty()) {
		// 에러 처리
	}

	return atof(stk.top().c_str());
}


double Calculator::binaryOpEval(char op, pair<double, double> operand) {
	switch (op)
	{
	case '+':
		return operand.second + operand.first;
	case '-':
		return operand.second - operand.first;
	case '*':
		return operand.second * operand.first;
	case '/':
		return operand.second / operand.first;
	}
}