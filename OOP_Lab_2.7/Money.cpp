#include "Money.h"

using namespace std;

void Money::setH500(const int x) { h500 = x; };
void Money::setH200(const int x) { h200 = x; };
void Money::setH100(const int x) { h100 = x; };
void Money::setH50(const int x) { h50 = x; };
void Money::setH20(const int x) { h20 = x; };
void Money::setH10(const int x) { h10 = x; };
void Money::setH5(const int x) { h5 = x; };
void Money::setH2(const int x) { h2 = x; };
void Money::setH1(const int x) { h1 = x; };
void Money::setC50(const int x) { c50 = x; };
void Money::setC25(const int x) { c25 = x; };
void Money::setC10(const int x) { c10 = x; };
void Money::setC5(const int x) { c5 = x; };
void Money::setC2(const int x) { c2 = x; };
void Money::setC1(const int x) { c1 = x; };

Money::Money()
{
	h500 = 0;
	h200 = 0;
	h100 = 0;
	h50 = 0;
	h20 = 0;
	h10 = 0;
	h5 = 0;
	h2 = 0;
	h1 = 0;
	c50 = 0;
	c25 = 0;
	c10 = 0;
	c5 = 0;
	c2 = 0;
	c1 = 0;
}
Money::Money(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o)
{
	h500 = a;
	h200 = b;
	h100 = c;
	h50 = d;
	h20 = e;
	h10 = f;
	h5 = g;
	h2 = h;
	h1 = i;
	c50 = j;
	c25 = k;
	c10 = l;
	c5 = m;
	c2 = n;
	c1 = o;
}
Money::Money(Money& a)
{
	h500 = a.h500;
	h200 = a.h200;
	h100 = a.h100;
	h50 = a.h50;
	h20 = a.h20;
	h10 = a.h10;
	h5 = a.h5;
	h2 = a.h2;
	h1 = a.h1;
	c50 = a.c50;
	c25 = a.c25;
	c10 = a.c10;
	c5 = a.c5;
	c2 = a.c2;
	c1 = a.c1;
}
Money::operator string() const
{
	stringstream sout;
	int a = h500 * 500 + h200 * 200 + h100 * 100 +
		h50 * 50 + h20 * 20 + h10 * 10 + h5 * 5 + h2 * 2 + h1;
	int b = c50 * 50 + c25 * 25 + c10 * 10 + c5 * 5 + c2 * 2 + c1;
	while (b >= 100)
	{
		b -= 100;
		a += 1;
	}
	if (b < 10)
		sout << "Cума = " << a << ",0" << b << endl;
	else
		sout << "Сума = " << a << "," << b << endl;

	return sout.str();
}

ostream& operator <<(ostream& out, const Money& x)
{
	out << string(x);
	return out;
}
istream& operator >>(istream& in, Money& x)
{
	
	do {
		cout << "Веедіть кількість кожної купюри:" << endl;
		cout << "500 = "; in >> x.h500;
		cout << "200 = "; in >> x.h200;
		cout << "100 = "; in >> x.h100;
		cout << "50 = "; in >> x.h50;
		cout << "20 = "; in >> x.h20;
		cout << "10 = "; in >> x.h10;
		cout << "5 = "; in >> x.h5;
		cout << "2 = "; in >> x.h2;
		cout << "1 = "; in >> x.h1;
		cout << "0.50 = "; in >> x.c50;
		cout << "0.25 = "; in >> x.c25;
		cout << "0.10 = "; in >> x.c10;
		cout << "0.5 = "; in >> x.c5;
		cout << "0.02 = "; in >> x.c2;
		cout << "0.01 = "; in >> x.c1;
	} while ((x.h500 || x.h200 || x.h100 || x.h50 || x.h20 || x.h10 || x.h5 || x.h2 ||
		x.h1 || x.c50 || x.c25 || x.c10 || x.c5 || x.c2 || x.c1) < 0);
	
	return in;
}

Money& Money::operator =(const Money& r)
{
	h500 = r.h500;
	h200 = r.h200;
	h100 = r.h100;
	h50 = r.h50;
	h20 = r.h20;
	h10 = r.h10;
	h5 = r.h5;
	h2 = r.h2;
	h1 = r.h1;
	c50 = r.c50;
	c25 = r.c25;
	c10 = r.c10;
	c5 = r.c5;
	c2 = r.c2;
	c1 = r.c1;
	return *this;
}


double Money::Total() {
	int hrn, kop;
	double sum;
	hrn = h500 * 500 + h200 * 200 + h100 * 100 +
		h50 * 50 + h20 * 20 + h10 * 10 + h5 * 5 + h2 * 2 + h1;
	kop = c50 * 50 + c25 * 25 + c10 * 10 + c5 * 5 + c2 * 2 + c1;
	sum = (double)hrn + (double)kop / 100.;
	return sum;
}
