#include "Calculator.h"

using namespace std;

int Calculator::calculate(string infixStr) {
	return parsingPost(InfToPost(infixStr));
}

// ���� ǥ����� ���� ǥ������� �ٲ� ��ȯ�ϴ� �Լ�
string Calculator::InfToPost(string infixStr) {

	stack<char> stk;
	string ret = "";

	for (int i = 0; i < infixStr.size(); i++) {

		// �켱���� 1
		if (infixStr.at(i) == '*' || infixStr.at(i) == '/') {

			while (!stk.empty() &&
				(stk.top() == '*' || stk.top() == '/')) {
				ret += stk.top();
				stk.pop();
			}
			stk.push(infixStr.at(i));
		}

		// �켱���� 2
		else if (infixStr.at(i) == '+' || infixStr.at(i) == '-') {

			while (!stk.empty() && stk.top() != '(') {
				ret += stk.top();
				stk.pop();
			}
			stk.push(infixStr.at(i));
		}

		// �켱���� 3
		else if (infixStr.at(i) == '(') {
			stk.push('(');
		}

		// �켱���� 4
		else if (infixStr.at(i) == ')') {

			while (stk.top() != '(') {

				ret += stk.top();
				stk.pop();

			}
			stk.pop();
		}

		// �� �� 
		else {
			ret += infixStr.at(i);
		}
	}

	while (!stk.empty()) {
		ret += stk.top();
		stk.pop();
	}

	return ret;
}

int Calculator::parsingPost(string postfixStr) {

	stack<char> stk;

	for (int i = 0; i < postfixStr.size(); i++) {
		// �����ڸ� ���� ��� ���ÿ��� �ǿ����� 2���� ���� ������ �����Ѵ� 
		if (postfixStr.at(i) == '*' ||
			postfixStr.at(i) == '/' ||
			postfixStr.at(i) == '+' ||
			postfixStr.at(i) == '-') {

			if (stk.empty()) {
				// ���� ó��
			}
			int operand1 = (int)stk.top();
			stk.pop();
			int operand2 = (int)stk.top();
			stk.pop();
			stk.push(binaryOpEval(postfixStr.at(i), { operand1, operand2 }));

			continue;
		}

		stk.push(postfixStr.at(i));
	}

	if (stk.empty()) {
		// ���� ó��
	}

	return stk.top();
}


int Calculator::binaryOpEval(char op, pair<int, int> operand) {
	switch (op)
	{
	case '+':
		return operand.first + operand.second;
	case '-':
		return operand.first - operand.second;
	case '*':
		return operand.first * operand.second;
	case '/':
		return operand.first / operand.second;
	}
}