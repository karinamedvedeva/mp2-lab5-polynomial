#pragma once
#include <iostream>
#include <locale>
using namespace std;

template <class T>
struct TLink
{
	T val;
	TLink* pNext;
};

template <class T>
class TList
{
protected:
	TLink<T>* pFirst, * pLast, * pCurr, * pPrev, * pStop;
	int size, pos;
public:
	TList();
	~TList();
	bool Empty(); //�������� ������ �� �������
	void InsFirst(T elem); //�������� ������� � ������ ������
	void InsLast(T elem); //�������� ������� � ����� ������
	void InsCurr(T elem); //�������� ������� � ������� ������� ������
	void DelFirst(); //������� ������ �������
	void DelCurr(); //������� ������� �������

	friend ostream& operator<<(ostream& ostr, const TList& l) //�����
	{
		TLink<T>* tmp = l.pFirst;
		while (tmp != l.pStop)
		{
			ostr << tmp->val<< " ";
			tmp = tmp->pNext;
		}
		return ostr;
	}
};

template <class T>
TList<T>::TList()
{
	pStop = NULL;
	pFirst = pStop;
	pLast = pStop;
	pCurr = pStop;
	pPrev = pStop;
	size = 0;
}

template <class T>
TList<T>::~TList()
{
	while (pFirst != pStop)
	{
		TLink<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
	pCurr =pPrev = pLast = pStop;
	size = 0;
	pos = 0;
}

template <class T>
bool TList<T>::Empty() //�������� ������ �� �������
{
	if (pStop == pFirst)
		return true;
	return false;
}

template <class T>
void TList<T>::InsFirst(T elem) //�������� ������� � ������ ������
{
	TLink<T>* tmp = new TLink<T>;
	tmp->val = elem;
	if (Empty())
	{
		tmp->pNext = pStop;
		pFirst = pLast = tmp;
	}
	else
	{
		tmp->pNext = pFirst;
		pFirst = tmp;
	}
	size++;
}

template <class T>
void TList<T>::InsLast(T elem) //�������� ������� � ������ ������
{
	TLink<T>* tmp = new TLink<T>;
	if (Empty())
		InsFirst(elem);
	else
	{
		tmp->val = elem;
		tmp->pNext = pStop;
		pLast->pNext = tmp;
		pLast = tmp;
	}
	size++;
}

template <class T>
void TList<T>::InsCurr(T elem) //�������� ������� � ������� ������� ������
{
	if (pCurr == pStop)
		InsLast(elem);
	else
	{
		if (pCurr == pFirst)
			InsFirst(elem);
		else
		{
			TLink<T>* tmp = new TLink<T>;
			tmp->val = elem;
			tmp->pNext = pCurr;
			pPrev -> pNext = tmp;
			pPrev = tmp;
			size++;
		}
	}
}

template <class T>
void TList<T>::DelFirst() //������� ������ �������
{
	if (Empty())
		throw 0;
	TLink<T>* tmp = pFirst;
	pFirst = pFirst->pNext;
	delete tmp;
	size--;
}

template <class T>
void TList<T>::DelCurr()
{
	if (pCurr = pStop)
		throw 0;
	else
	{
		if (pCurr = pFirst)
			DelFirst();
		else
		{
			TLink<T>* tmp = pCurr;
			pPrev->pNext = pCurr->pNext;
			delete tmp;
			pCurr = pPrev->pNext;
			size--;
		}
	}
}