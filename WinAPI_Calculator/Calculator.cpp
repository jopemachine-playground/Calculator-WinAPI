#include "Calculator.h"

using namespace std;

// 중위 표기식을 후위 표기식으로 바꿔 반환하는 함수
string Calculator::InfToPost(string infixStr) {

	stack<char> stk;
	string ret = "";

	for (int i = 0; i < infixStr.size(); i++) {

		// 우선순위 1
		if (infixStr.at(i) == '*' || infixStr.at(i) == '/') {

			while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
				cout << stk.top();
				stk.pop();
			}
			stk.push(infixStr.at(i));
		}

		// 우선순위 2
		else if (infixStr.at(i) == '+' || infixStr.at(i) == '-') {

			while (!stk.empty() && stk.top() != '(') {
				cout << stk.top();
				stk.pop();
			}
			stk.push(infixStr.at(i));
		}

		// 우선순위 3
		else if (infixStr.at(i) == '(') {
			stk.push('(');
		}

		// 우선순위 4
		else if (infixStr.at(i) == ')') {

			while (stk.top() != '(') {

				cout << stk.top();
				stk.pop();

			}
			stk.pop();
		}

		// 그 외 
		else {
			cout << infixStr.at(i);
		}
	}
	while (!stk.empty()) {
		ret += stk.top();
		stk.pop();
	}
}

int Calculator::parsingPost(string postfixStr) {

	stack<char> stk;
	
	int loop = postfixStr.size();

	for (int i = 0; i < loop; i++) {
		// 연산자를 만난 경우 스택에서 피연산자 2개를 꺼내 연산을 수행한다 
		if (postfixStr.at(i) == '*' || postfixStr.at(i) == '/' || postfixStr.at(i) == '+' || postfixStr.at(i) == '-') {
			if (stk.empty()) {
				// 에러 처리
			}
			int operand1 = stk.top();
			stk.pop();
			int operand2 = stk.top();
			stk.pop();
			stk.push(binaryOpEval(postfixStr.at(i), {operand1, operand2}));
		}
	}
}

int Calculator::binaryOpEval(char op, pair<int, int> operand) {
	switch (op) {
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