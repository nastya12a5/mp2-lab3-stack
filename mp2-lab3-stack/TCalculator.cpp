#include "TCalculator.h"

using namespace std;

bool TCalculator::CheckExpression()
{
    if (st.Empty() == false)
    {
        this->st.Clear();
    }
    int res = 0;
    for (int i = 0; i < infix.size(); i++)
    {
        if (infix[i] == '(')
        {
            st.Push(infix[i]);
        }
        if (infix[i] == ')')
        {
            if (!st.Empty())
            {
                st.Pop();
            }
            else
                res = 1;
        }
    }
    if (!st.Empty())
        res = 1;
    if (res == 0)
    {
        return true;
    }
    else
        return false;
}

void TCalculator::SetInfix(std::string str)
{
    infix = str;
}

std::string TCalculator::GetPostfix()
{
    return postfix;
}

std::string TCalculator::GetInfix()
{
    return infix;
}

double TCalculator::CalcPostfix()
{
    if (D.Empty() == false)
    {
        this->D.Clear();
    }
    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            D.Push(postfix[i] - '0');
        }


        if ((postfix[i] == '+') || (postfix[i] == '-') || (postfix[i] == '*') || (postfix[i] == '/') || (postfix[i] == '^'))
        {
            double x1 = 0; double x2 = 0; double  y = 0;
            if (D.Empty() == false)
            {
                x2 = D.Pop();
            }
            if (D.Empty() == false)
            {
                x1 = D.Pop();
            }
            if (postfix[i] == '+') y = x1 + x2;
            if (postfix[i] == '-') y = x1 - x2;
            if (postfix[i] == '*')  y = x1 * x2;
            if (postfix[i] == '/') y = x1 / x2;
            if (postfix[i] == '^') y = pow(x1, x2);

            D.Push(y);

        }

    }
    double res;
    if (D.Empty() == false)
    {
        res = D.Pop();
    }
    else
    {
        throw "stack is empty";
    }


    if (!D.Empty())
    {
        throw "problems with res";
    }
    return res;
}

void TCalculator::ToPostfix()
{
    if (st.Empty() == false)
    {
        this->st.Clear();
    }
    string str = '(' + infix + ')';
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            st.Push('(');
        }
        if (str[i] >= '0' && str[i] <= '9')
        {
            postfix += str[i];
        }
        if (str[i] == ')')
        {
            char el = st.Pop();
            while (el != '(')
            {
                postfix += el;
                el = st.Pop();
            }
        }
        if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^'))
        {
            char el = st.Pop();

            if (prior(el) >= prior(str[i]))
            {
                postfix += el;
                el = st.Pop();
            }
            else
            {
                st.Push(el);
            }
            st.Push(str[i]);
        }


    }

}