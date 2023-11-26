// mp2-lab3-stack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <string>
#include <iostream>
#include "Tstack.h"
#include "TCalculator.h"
using namespace std;
int main()
{
	string s = "(2+2)*2^2";
	TCalculator a(s);

	cout << a.CalcPostfix() << std::endl;

	if (a.CheckExpression()) cout << "right" << endl;

}


