#pragma once
#include "TList.h"

template <class T>
class THeadList :public TList<T>
{
protected:
	TLink<T>* pHead;
public:
	THeadList();  //конструктор
	~THeadList();  //деструктор
	void InsFirst(T elem);  //добавление элемента в начало
	void DelFirst();  //удаление элемента из начала

};

template <class T>
THeadList<T>::THeadList():TList<T>()  //конструктор
{
	TLink<T>* tmp = new TLink<T>;
	pHead = tmp;
	TList<T>::pStop = pHead;
	pHead->pNext = pHead;
	TList<T>::pFirst = TList<T>::pLast = TList<T>::pCurr = TList<T>::pPrev = pHead;
}

template <class T>
THeadList<T>::~THeadList()
{
	TList<T>::~TList();
	delete pHead;
}

template <class T>  
void THeadList<T>::InsFirst(T elem)  //добавление элемента в начало
{
	TList<T>::InsFirst(elem);
	pHead->pNext = TList<T>::pFirst;
}

template <class T>  
void THeadList<T>::DelFirst()  //удаление элемента из начала
{
	TList<T>::DelFirst();
	pHead->pNext = TList<T>::pFirst;
}