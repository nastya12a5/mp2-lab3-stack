#pragma once
#include <algorithm>
#include <iostream>
using namespace std;
template <class T>
class Tstack
{
	T* pMem;
	int MaxSize;
	int CurrInd;
public:
	Tstack& operator = (const Tstack& s)
	{
		if (*this == s)
		{
			return *this;
		}
		delete[] pMem;
		CurrInd = s.CurrInd;
		MaxSize = s.MaxSize;
		pMem = new T[s.MaxSize];
		copy(s.pMem, s.pMem + CurrInd, pMem);
		return *this;

	}
	~Tstack()
	{
		delete[] pMem;
	}
	Tstack(int _MaxSize = 10)
	{
		if (_MaxSize < 1)
		{
			throw "wrong size";
		}
		MaxSize = _MaxSize;
		pMem = new T[MaxSize];
		CurrInd = -1;
	}
	Tstack(const Tstack& s)
	{
		MaxSize = s.MaxSize;
		CurrInd = s.CurrInd;
		delete[]pMem;
		pMem = new T[MaxSize];

		for (int i = 0; i <= CurrInd; i++)
		{
			pMem[i] = s.pMem[i];
		}
	}
	bool Empty()
	{
		return CurrInd == -1;
	}
	bool Full()
	{
		return CurrInd == MaxSize - 1;
	}
	void Push(T elem)
	{
		if (CurrInd >= MaxSize - 1)
		{
			throw("Stack Overflow");
		}
		pMem[CurrInd + 1] = elem;
		CurrInd++;
	}
	T Pop()
	{
		if (this->Empty() == true)
		{
			throw("Stack is empty");
		}
		CurrInd--;
		return pMem[CurrInd + 1];
	}
	int GetCurrInd()
	{
		return CurrInd;
	}
	T First_el()
	{
		if (CurrInd == -1)
			throw ("Stack is empty");
		return pMem[CurrInd];
	}
	void Clear()
	{
		while (!this->Empty())
		{
			this->Pop();
		}
	}
	void Output()
	{
		if (CurrInd == -1)
		{
			cout << "stack is empty" << endl;
		}
		cout << '(';
		for (int i = 0; i <= CurrInd; i++)
		{
			cout << pMem[i] << "";

		}
		cout << ")" << endl;
	}

};
