#include "Polynomial.h"

int main()
{
	TList <int> list;
	list.InsFirst(1);
	list.InsCurr(7);
	list.InsFirst(2);
	list.InsFirst(1);
	list.DelFirst();
	list.InsLast(5);
	list.DelCurr();
	cout << list;
}