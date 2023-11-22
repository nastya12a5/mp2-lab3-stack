#include "TCalculator.h"
#include "TStack.h"
#include <iostream>
#include "string"
using namespace std;
void TCalculator::SetInfix(const string& expr)
{
	infix = expr;
}
string TCalculator::GetInfix()
{
	return infix;
}
string TCalculator::GetPostfix()
{
	return postfix;
}
bool TCalculator::CheckExpression()
{
	int res = 0;
	for (int i = 0; i < infix.size(); i++)
	{
		if (infix[i] == '(')
		{
			st.Push(infix[i]);
		}
		if (infix[i] == ')')
		{
			if (st.empty()) res = 1;else st.Pop();
			
		}
	}
	if (!st.empty()) res = 2;
	if (res == 1 || res == 2) return false;
	if (res == 0) return true;
}
int TCalculator::prior(char op)
{
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	if (op == '^') return 3;
	if (op == '(' || op == ')') return 0;
}
double TCalculator::CalcPostfix()
{
	D.~TStack();
	for (int i = 0; i < postfix.size(); i++)
	{
		if (postfix[i] >= '0' && postfix[i] <= '9')
		{
			D.Push(postfix[i] - '0');
		}
		else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
		{
			double x1, x2, y;
			x2 = D.Pop(); x1 = D.Pop();
			if (postfix[i] == '+') y = x1 + x2;
			if (postfix[i] == '-') y = x1 - x2;
			if (postfix[i] == '*') y = x1 * x2;
			if (postfix[i] == '/') y = x1 / x2;
			//if (postfix[i] == '^') y = x1 ^ x2;
			D.Push(y);
		}

		return D.Pop();
	}
}
void TCalculator::ToPostfix()
{
	st.~TStack();
	string str = "(" + infix + ")";
	postfix.~basic_string();
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(') { st.Push('('); }
		else if (str[i] >= '0' && str[i] <= '9') { postfix += str[i]; }
		else if (str[i] == ')')
		{
			char el = st.Pop();
			while (el != '(')
			{
				postfix += el;
				el = st.Pop();
            }
		}
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
		{
			char el = st.Pop();
			while (prior(el) >= prior(str[i]))
			{
				postfix += el;
				el = st.Pop();
			}
		}
	}
	
}