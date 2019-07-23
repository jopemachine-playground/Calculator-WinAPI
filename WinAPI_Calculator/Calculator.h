#pragma once
#include <stack>
#include <iostream>
#include <string>

using namespace std;

class Calculator {
public:

private:

	static string InfToPost(string infixStr);

	static int parsingPost(string postfixStr);

	static int binaryOpEval(char op, pair<int, int> operand);
};