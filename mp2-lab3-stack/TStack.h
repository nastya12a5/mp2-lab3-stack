#pragma once
#include <iostream>
using namespace std;
template <class T>
class TStack
{
	T* pMem;
	int MaxSize;
	int CurrInd;
public:
	TStack(int _MaxSize = 10) {
		if (CurrInd > MaxSize) throw("Wrong size");
		MaxSize = _MaxSize;
		pMem = new T[MaxSize];
		CurrInd = -1;
	}
	~TStack()
	{
		delete[] pMem;
	}
	TStack(const TStack& s)
	{
		MaxSize = s.MaxSize;
		pMem = new T[MaxSize];
		CurrInd = s.CurrInd;
		for (int i = 0; i <= CurrInd; i++)
		{
			pMem[i] = s.pMem[i];
		}
	}
	TStack& operator=(const TStack& s)
	{
		if (this != &s)
		{
			if (MaxSize != s.MaxSize)
			{
				delete[]pMem;
				MaxSize = s.MaxSize;
				pMem = new T[MaxSize];
			}
			CurrInd = s.CurrInd;
			for (int i = 0; i < CurrInd; i++)
			{
				pMem[i] = s.pMem[i];
			}
		}
		return *this;
	}
	bool empty() {
		if (CurrInd == -1) { return true; }
		else return false;
	}
	bool full()
	{
		if (CurrInd == MaxSize - 1) return true;
		else return false;
	}
	void Push(const T& el) {
		if (CurrInd + 1 >= MaxSize)
		{
			throw("Overflow");
		}
		CurrInd++;
		pMem[CurrInd + 1] = el;
	}
	T Pop()
	{
		if (CurrInd == -1)
		{
			throw("Dtack is empty");
		}
		CurrInd--;
		return pMem[CurrInd++];
	}
};

