#pragma once
#include "TStack.h"
#include <iostream>
#include "string"
class TCalculator
{
	string infix, postfix;
	TStack <double> D;
	TStack <char> st;
public:
	bool CheckExpression();
	int prior(char op);
	double CalcPostfix();
	void ToPostfix();
	void SetInfix(const string& expr);
	string GetInfix();
	string GetPostfix();
};

