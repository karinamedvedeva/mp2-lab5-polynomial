#pragma once
#include "THeadList.h"
#include "Tlist.h"

struct TMonom
{
	double coeff;
	int x, y, z;
public:
	TMonom()
	{
		coeff =0;
		x = 0;
		y = 0;
		z = 0;
	}

	TMonom(double _coeff, int _x, int _y, int _z)
	{
		coeff = _coeff;
		x = _x;
		y = _y;
		z = _z;
	}

	bool operator>(const TMonom& m) 
	{
		if ( x > m.x || y > m.y || z > m.z)
			return true;
		else
		   return false;
		if (coeff < m.coeff)
			return false;
		return true;
	}

	bool operator<(const TMonom& m)
	{
		if (x < m.x || y < m.y || z < m.z)
			return true;
		else
			return false;
		if (coeff > m.coeff)
			return false;
		return true;
	}

	bool operator==(const TMonom& m)
	{
		if (coeff != m.coeff || x != m.x || y != m.y || z != m.z)
			return false;
		return true;
	}

	friend istream& operator>>(istream& istr, TMonom& m)
	{
		cout << "Введите значение коэффициента: ";
		istr >> m.coeff;
		cout << "Введите значение степени переменной x: ";
		istr >> m.x;
		cout << "Введите значение степени переменной y: ";
		istr >> m.y;
		cout << "Введите значение степени переменной z: ";
		istr >> m.z;
		return istr;
	}

	friend ostream& operator<<(ostream& ostr, TMonom& m)
	{
		ostr << m.coeff;
		if (m.x != 0)
		{
			if (m.x == 1)
				ostr << "*x";
			else
			    ostr << "*x^" << m.x;
		}
		if (m.y != 0)
		{
			if (m.y == 1)
				ostr << "*y";
			else
				ostr << "*y^" << m.y;
		}
		if (m.z != 0)
		{
			if (m.z == 1)
				ostr << "*z";
			else
				ostr << "*z^" << m.z;
		}
		return ostr;
	}

	TMonom operator*(const double val)
	{
		TMonom res(this->x, this->y, this->z, this->coeff);
		res.coeff *= val;
		return res;
	}
	
	TMonom operator*(const TMonom& m)
	{
		TMonom res;
		res.x = x + m.x;
		res.y = y + m.y;
		res.z = z + m.z;;
		res.coeff = coeff * m.coeff;
		return res;
	}

	TMonom& operator=(const TMonom& m)
	{
		coeff = m.coeff;
		x = m.x;
		y = m.y;
		z = m.z;
		return *this;
	}
};


class TPolinom : public THeadList<TMonom>
{
public:
	TPolinom();
	TPolinom& operator=(TPolinom& q);
	void InsMonom(TMonom& m); //добавить моном
	TPolinom& operator+=(TPolinom& q);
	TPolinom& operator*= (TMonom& m);
	int GetSize()
	{
	    return size;
	}
	friend istream& operator>>(istream& istr, TPolinom& p)
	{
		cout << "Введите размер полинома: ";
		int size;
		cin >> size;
		for (int i = 0; i < size; i++)
		{
			TMonom m;
			istr >> m;
			p.InsMonom(m);
		}
		return istr;
	}

	friend ostream& operator<<(ostream& ostr, TPolinom& p)
	{
		for (p.Reset(); !p.IsEnd(); p.GoNext())
		{
			ostr << p.pCurr->val<<" ";
		}
		if (p.size == 0)
		{
			ostr << 0;
		}
		return ostr;
	}
};

TPolinom::TPolinom()
{
	TMonom tmp;
	tmp.z = -1;
	pHead->val = tmp;
}

TPolinom& TPolinom::operator=(TPolinom& q)
{
	if (this == &q)
		return *this;
	while (pFirst != pStop)
	{
		DelFirst();
	}
	for (q.Reset(); !q.IsEnd(); q.GoNext())
	{
		InsLast(q.GetCurr());
	}
	return *this;
}

void TPolinom::InsMonom(TMonom& m)
{
	for (Reset(); !IsEnd(); GoNext())
	{
		if (m > pCurr->val)
		{
			InsCurr(m);
			break;
		}
		else
		{
			if (m == pCurr->val)
			{
				if ((m.coeff + pCurr->val.coeff) == 0)
				{
					DelCurr();
				break;
			    }
				else 
				{
					pCurr->val.coeff = m.coeff + pCurr->val.coeff;
					break;
				}
			}
		}
	}
	if (pCurr == pStop)
		InsLast(m);
}

TPolinom& TPolinom::operator+=(TPolinom& q)
{
	Reset();
	q.Reset();
	while (!q.IsEnd())
	{
		if (pCurr->val < q.pCurr->val)
		{
			InsCurr(q.pCurr->val);
			q.GoNext();
		}
		else
		{
			if (pCurr->val > q.pCurr->val)
				GoNext();
			else
			{
				double tmp = pCurr->val.coeff + q.pCurr->val.coeff;
				if (tmp)
				{
					pCurr->val.coeff = tmp;
					GoNext();
					q.GoNext();
				}
				else
				{
					DelCurr();
				    q.GoNext();
				}
			}
		}
	}
	return *this;
}

TPolinom& TPolinom::operator*= (TMonom& m)
{
	for (Reset(); !IsEnd(); GoNext())
	{
		pCurr->val= pCurr->val* m;
	}
	return *this;
}