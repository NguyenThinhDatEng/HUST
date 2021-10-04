#include<iostream>
using namespace std;

struct ps 
{
	int tu, mau;
	ps(int x, int y) {
		tu = x;
		mau = y;
	}
};

ps rutGon(ps a);

// display on Screen
void psPrint(ps a);

ps operator + (ps a, ps b);

ps operator - (ps a, ps b);

ps operator * (ps a, ps b);

ps operator *(ps a, int k);

ps operator *(int k, ps a);

ps operator / (ps a, ps b);

ps operator / (ps a, int k);

void main() {
	ps a1 = ps(4, 10);
	ps a2 = ps(1, 3);
	ps c = ps(1, 1);
	c = a1 / a2;
	psPrint(c); cout << endl;
	psPrint(a1 / 5); cout << endl;
}

ps rutGon(ps a)
{
	int k = a.tu < a.mau ? a.tu : a.mau;
	for (int i = k; i > 0; i--)
	{
		if (a.tu % i == 0 && a.mau % i == 0)
		{
			a.tu /= i;
			a.mau /= i;
			break;
		}
	}
	return a;
}

void psPrint(ps a)
{
	cout << a.tu << "/" << a.mau;
}

ps operator + (ps a, ps b)
{
	int mau = a.mau * b.mau;
	int tu = a.tu * b.mau + a.mau * b.tu;
	ps c = ps(tu, mau);
	c = rutGon(c);
	return c;
}

ps operator - (ps a, ps b)
{
	int mau = a.mau * b.mau;
	int tu = a.tu * b.mau - a.mau * b.tu;
	ps c = ps(tu, mau);
	c = rutGon(c);
	return c;
}

ps operator * (ps a, ps b)
{
	int mau = a.mau * b.mau;
	int tu = a.tu * b.tu;
	ps c = ps(tu, mau);
	c = rutGon(c);
	return c;
}

ps operator *(ps a, int k)
{
	int mau = a.mau;
	int tu = a.tu * k;
	ps c = ps(tu, mau);
	c = rutGon(c);
	return c;
}

ps operator *(int k, ps a) {
	int mau = a.mau;
	int tu = a.tu * k;
	ps c = ps(tu, mau);
	c = rutGon(c);
	return c;
}

ps operator / (ps a, ps b)
{
	int mau = a.mau * b.tu;
	int tu = a.tu * b.mau;
	ps c = ps(tu, mau);
	c = rutGon(c);
	return c;
}

ps operator / (ps a, int k)
{
	int mau = a.mau * k;
	int tu = a.tu;
	ps c = ps(tu, mau);
	c = rutGon(c);
	return c;
}