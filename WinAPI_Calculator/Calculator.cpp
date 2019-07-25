#include <regex>
#include "Utility.h"
#include "Calculator.h"

using namespace std;

Calculator* Calculator::Instance = nullptr;

int Calculator::calculate(string infixStr) {
	return parsingPost(InfToPost(infixStr));
}

// ���� ǥ����� ���� ǥ������� �ٲ� ��ȯ�ϴ� �Լ�
queue<string> Calculator::InfToPost(string infixStr) {
	
	// ��ȯ�� ���� ����
	stack<string> stk;
	// ���� ǥ������� ��ȯ�� ���� ��ū�� 
	queue<string> ret;
	// ���� ǥ����� ��ū��
	vector<string> tokens = Utility::split(infixStr, ' ');

	for (auto iter = tokens.begin(); iter != tokens.end(); ++iter) {
		
		string token = (*iter);

		// �켱���� 1
		if (token == "*" || token == "/") {

			while (!stk.empty() &&
				(stk.top() == "*" || stk.top() == "/")) {
				ret.push(stk.top());
				stk.pop();
			}
			stk.push(token);
		}

		// �켱���� 2
		else if (token == "+" || token == "-") {

			while (!stk.empty() && stk.top() != "(") {
				ret.push(stk.top());
				stk.pop();
			}
			stk.push(token);
		}

		// �켱���� 3
		else if (token == "(") {
			stk.push("(");
		}

		// �켱���� 4
		else if (token == ")") {

			while (stk.top() != "(") {

				ret.push(stk.top());
				stk.pop();

			}
			stk.pop();
		}

		// �� �� 
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

int Calculator::parsingPost(queue<string> tokens) {

	// ����� ���� ����
	stack<string> stk;

	while(!tokens.empty()) {
		// �����ڸ� ���� ��� ���ÿ��� �ǿ����� 2���� ���� ������ �����Ѵ� 
		if (tokens.front() == "*" ||
			tokens.front() == "/" ||
			tokens.front() == "+" ||
			tokens.front() == "-") {

			if (stk.empty()) {
				// ���� ó��
			}
			int operand1 = atoi(stk.top().c_str());
			stk.pop();
			int operand2 = atoi(stk.top().c_str());
			stk.pop();
			stk.push(to_string(binaryOpEval(*(tokens.front().c_str()), { operand1, operand2 })));
			tokens.pop();
			continue;
		}

		stk.push(tokens.front());
		tokens.pop();
	}

	if (stk.empty()) {
		// ���� ó��
	}

	return atoi(stk.top().c_str());
}


int Calculator::binaryOpEval(char op, pair<int, int> operand) {
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