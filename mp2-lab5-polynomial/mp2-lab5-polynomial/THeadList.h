#pragma once
#include "TList.h"

template <class T>
class THeadList :public TList<T>
{
protected:
	TLink<T>* pHead;
public:
	THeadList();  //�����������
	~THeadList();  //����������
	void InsFirst(T elem);  //���������� �������� � ������
	void DelFirst();  //�������� �������� �� ������

};

template <class T>
THeadList<T>::THeadList():TList<T>()  //�����������
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
void THeadList<T>::InsFirst(T elem)  //���������� �������� � ������
{
	TList<T>::InsFirst(elem);
	pHead->pNext = TList<T>::pFirst;
}

template <class T>  
void THeadList<T>::DelFirst()  //�������� �������� �� ������
{
	TList<T>::DelFirst();
	pHead->pNext = TList<T>::pFirst;
}