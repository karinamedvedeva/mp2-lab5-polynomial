#include "TList.h"
#include "TPolinom.h"

int main()
{
	setlocale(LC_CTYPE, "Rus");
	TMonom  m;
	TPolinom P, Q;
	cout << "������� ������� P"<<endl;
	cin >> P;
	cout << "������� ������� Q" << endl;
	cin >> Q;
	cout << "P=" << P << endl << "Q=" << Q<<endl;
    P+= Q;
	cout << "P+Q="<<P<<endl;
	cout << "������� ����� m: " << endl;
	cin >> m;
	cout << "P= " << P << endl << "m= " << m << endl;
	P *= m;
	cout <<"P*m="<< P;
}