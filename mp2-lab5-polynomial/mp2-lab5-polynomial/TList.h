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
	bool Empty(); //проверка списка на пустоту
	T GetCurr();

	void InsFirst(T elem); //добавить элемент в начало списка
	void InsLast(T elem); //добавить элемент в конец списка
	void InsCurr(T elem); //добавить элемент в текущую позицию списка
	void DelFirst(); //удалить первый элемент
	void DelCurr(); //удалить текущий элемент
	
	void Reset();
	void GoNext();
	bool IsEnd();

	friend ostream& operator<<(ostream& ostr, const TList& l) //вывод
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
bool TList<T>::Empty() //проверка списка на пустоту
{
	if (pStop == pFirst)
		return true;
	return false;
}

template <class T>
T TList<T>::GetCurr()
{
	if (Empty())
		throw 0;
	if (pCurr = pStop)
		throw 0;
	pCurr = pFirst->pNext;
	pPrev = pCurr;
	for (int i = 0; i < pos; i++)
	{
		pPrev = pCurr;
		pCurr = pCurr->pNext;
	}
	return pCurr->val;
}

template <class T>
void TList<T>::InsFirst(T elem) //добавить элемент в начало списка
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
void TList<T>::InsLast(T elem) //добавить элемент в конец списка
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
void TList<T>::InsCurr(T elem) //добавить элемент в текущую позицию списка
{
	if (pCurr == pStop)
	{
		InsLast(elem);
    }
	else
	{
		if (pCurr == pFirst)
		{
			InsFirst(elem);
		}
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
void TList<T>::DelFirst() //удалить первый элемент
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
	if (Empty())
		throw 0;
	else
	{
		if (pCurr == pFirst)
		{
			DelFirst();
			pCurr = pFirst;
		}
		else
		{
			pPrev->pNext = pCurr->pNext;
			delete pCurr;
			pCurr = pPrev->pNext;
			size--;
		}
	}
}

template <class T>
void TList<T>::Reset()
{
	pCurr = pFirst;
}

template <class T>
void TList<T>::GoNext()
{
	pPrev = pCurr;
	pCurr = pCurr->pNext;
}

template <class T>
bool TList<T>::IsEnd()
{
	return pCurr == pStop;
}