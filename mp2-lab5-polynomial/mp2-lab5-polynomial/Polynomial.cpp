#include "TList.h"
#include "TPolinom.h"

int main()
{
	setlocale(LC_CTYPE, "Rus");
	TMonom  m;
	TPolinom P, Q;
	cout << "¬ведите полином P"<<endl;
	cin >> P;
	cout << "¬ведите полином Q" << endl;
	cin >> Q;
	cout << "P=" << P << endl << "Q=" << Q<<endl;
    P+= Q;
	cout << "P+Q="<<P<<endl;
	cout << "¬ведите моном m: " << endl;
	cin >> m;
	cout << "P= " << P << endl << "m= " << m << endl;
	P *= m;
	cout <<"P*m="<< P;
}