// mp2-lab3-stack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "TStack.h"
#include "TCalculator.h"
using namespace std;
/* Написана реалтзация класса TStack 
*/
int main()
{
    TStack <int> st(20);
    TCalculator calcul;

    string s1 = "()";
    calcul.SetInfix(s1);
    if (calcul.CheckExpression()) cout << "right" << endl;
    else cout << "wrong" << endl;

}


