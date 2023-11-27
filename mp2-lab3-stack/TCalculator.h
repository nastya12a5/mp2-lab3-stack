#pragma once
#include <string>
#include <cmath>
#include "Tstack.h"
using namespace std;
class TCalculator
{
	string  infix, postfix;
	Tstack<char> st = Tstack<char>(10);
	Tstack<double> D = Tstack<double>(10);
	int prior(char op)
	{
		if (op == '(' || op == ')') return 0;
		if (op == '+' || op == '-') return 1;
		if (op == '*' || op == '/') return 2;
		if (op == '^') return 3;
	}
	void ToPostfix();
public:
	TCalculator(string& str) :infix(str) { ToPostfix(); };
	bool CheckExpression();
	void SetInfix(string str);
	string GetPostfix();
	string GetInfix();
	double CalcPostfix();
	double Calc();
	void OutputPostfix();
	void OutputInfix();
};
