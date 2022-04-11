#include "Account.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <math.h>
using namespace std;

void Account::setSecondname(string value)
{
	secondname = value;
}

bool Account::setNo(int value)
{
	if (value > 0)
	{
		no = value;
		return true;
	}
	else
	{
		no = 0;
		return false;
	}
}

bool Account::setPercent(double value)
{
	if (value > 0)
	{
		percent = value;
		return true;
	}
	else
	{
		percent = -value;
		return false;
	}
}

void Account::setSumma()
{
	cin >> summa;
}

Account::Account()
{
	setNo(0);
	setPercent(0);
}
Account::Account(int no, double percent)
{
	setNo(no);
	setPercent(percent);
}
Account::Account(const Account& a)
{
	setNo(a.getNo());
	setPercent(a.getPercent());
}

ostream& operator <<(ostream& out, const Account& x)
{
	out << string(x);
	return out;
}
istream& operator >>(istream& in, Account& x)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "������ ����� ����������� �������: "; in >> x.no;
	cout << "������ ������� ��������: "; in >> x.secondname;
	
	return in;
}
Account& Account::operator =(const Account& r)
{
	secondname = r.secondname;
	percent = r.percent;
	no = r.no;
	summa = r.summa;
	return *this;
}
Account::operator string() const
{
	stringstream ss;
	ss << "----------------------------------------------------------------------------\n";
	ss << "|500h|200h|100h| 50h| 20h| 10h|  5h|  2h|  1h| 50c| 25c| 10c|  5c|  2c|  1c|\n";
	ss << "----------------------------------------------------------------------------\n";
	ss << "|" << setw(4) << summa.getH500() << "|" << setw(4) << summa.getH200() << "|" << setw(4) << summa.getH100() << "|" <<
		setw(4) << summa.getH50() << "|" << setw(4) << summa.getH20() << "|" << setw(4) << summa.getH10() << "|" << setw(4) <<
		summa.getH5() << "|" << setw(4) << summa.getH2() << "|" << setw(4) << summa.getH1() << "|" << setw(4) << summa.getC50() <<
		"|" << setw(4) << summa.getC25() << "|" << setw(4) << summa.getC10() << "|" << setw(4) << summa.getC5() << "|" <<
		setw(4) << summa.getC2() << "|" << setw(4) << summa.getC1() << "|\n" <<
		"----------------------------------------------------------------------------\n";

	int a = summa.getH500() * 500 + summa.getH200() * 200 + summa.getH100() * 100 +
		summa.getH50() * 50 + summa.getH20() * 20 + summa.getH10() * 10 + summa.getH5() * 5 + summa.getH2() * 2 + summa.getH1();
	int b = summa.getC50() * 50 + summa.getC25() * 25 + summa.getC10() * 10 + summa.getC5() * 5 + summa.getC2() * 2 + summa.getC1();
	while (b >= 100)
	{
		b -= 100;
		a += 1;
	}
	if (b < 10)
		ss << "Sum = " << a << ",0" << b << endl;
	else
		ss << "Sum = " << a << "," << b << endl;

	return ss.str();
}

void Account::ChangeOwner()
{	
	cin >> summa;
	setPercent(5);
}

void Account::GetMoney()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int no;
	do {
		cout << "������ ������ �� ������ �����?" << endl;
		cout << "[1] - 500 ���." << endl;
		cout << "[2] - 200 ���" << endl;
		cout << "[3] - 100 ���" << endl;
		cout << "[4] - 50 ���" << endl;
		cout << "[5] - 20 ���" << endl;
		cout << "������ ��������: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			summa.setH500(summa.getH500() - 1);
			cout << "�� ������ ����� 500 �������" << endl;
		break;
		case 2:
			summa.setH200(summa.getH200() - 1);
			cout << "�� ������ ����� 200 �������" << endl;
		break;
		case 3:
			summa.setH100(summa.getH100() - 1);
			cout << "�� ������ ����� 100 �������" << endl;
		break;
		case 4:
			summa.setH50(summa.getH50() - 1);
			cout << "�� ������ ����� 50 �������" << endl;
		break;
		case 5:
			summa.setH20(summa.getH20() - 1);
			cout << "�� ������ ����� 20 �������" << endl;
		}
		break;
		cout << endl;
	} while (no != 6);
}

void Account::AddMoney()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int no;
	do {
		cout << "������ ������ �� ������ �������� �� �������?" << endl;
		cout << "[1] - 500 ���." << endl;
		cout << "[2] - 200 ���" << endl;
		cout << "[3] - 100 ���" << endl;
		cout << "[4] - 50 ���" << endl;
		cout << "[5] - 20 ���" << endl;
		cout << "������ ��������: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			summa.setH500(summa.getH500() + 1);
			cout << "�� ������ ������� 500 �������" << endl;
			break;
		case 2:
			summa.setH200(summa.getH200() + 1);
			cout << "�� ������ ������� 200 �������" << endl;
			break;
		case 3:
			summa.setH100(summa.getH100() + 1);
			cout << "�� ������ ������� 100 �������" << endl;
			break;
		case 4:
			summa.setH50(summa.getH50() + 1);
			cout << "�� ������ ������� 50 �������" << endl;
			break;
		case 5:
			summa.setH20(summa.getH20() + 1);
			cout << "�� ������ ������� 20 �������" << endl;
		}
		break;
		cout << endl;
	} while (no != 6);
}

Account Account::MakePercent(Account& a)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double sum = 0;
	sum = summa.Total();
	int no;
	do {
		cout << "�� ������ ������ ���������� " << percent << "% �� ��� ������?" << endl;
		cout << "[1] - ���" << endl;
		cout << "[2] - ͳ" << endl;
		cout << "������ ��������: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			sum += sum * (percent / 100);
			cout << "�� ������ ���������� �������!" << endl;
		}
		break;
		cout << endl;
	} while (no != 2);

	int hrn = (int)sum;
	int coin = (floor((sum - hrn) * 100 + 0.501));

	Change(hrn, coin, a);
	return a;
}

Account Account::ToDollar(Account& a)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double sum = 0;
	int no;
	do {
		cout << "�� ������ ������ ��������� " << summa.Total() << "���. � �������?" << endl;
		cout << "[1] - ���" << endl;
		cout << "[2] - ͳ" << endl;
		cout << "������ ��������: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			sum += sum * 0.033;
			cout << "�� ������ �������� ����� � �������!" << endl;
		}
		break;
		cout << endl;
	} while (no != 2);

	int hrn = (int)sum;
	int coin = (floor((sum - hrn) * 100 + 0.501));

	Change(hrn, coin, a);
	return a;
}

Account Account::ToEuro(Account& a)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double sum = 0;
	int no;
	do {
		cout << "�� ������ ������ ��������� " << summa.Total() << "���. � ����?" << endl;
		cout << "[1] - ���" << endl;
		cout << "[2] - ͳ" << endl;
		cout << "������ ��������: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			sum += sum * 0.030;
			cout << "�� ������ �������� ����� � ����!" << endl;
		}
		break;
		cout << endl;
	} while (no != 2);

	int hrn = (int)sum;
	int coin = (floor((sum - hrn) * 100 + 0.501));

	Change(hrn, coin, a);
	return a;
}

void Account::Propys()
{
	double x = summa.Total();
	double frac = 0;
	double integral = 0;
	frac = modf(x, &integral);
	int numb = (int)integral;

	int osn[11] = { 0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };

	string basis[11][10] = {
		{"","","","","","","","","",""},
		{"","����","���","���","������","�'���","�����","��","���","������"},
		{"","������","��������","��������","�����","�'�������","���������","�������","��������","���'������"},
		{"","���","����","������","���������","�'�����","�������","�����","������","���'�����"},
		{"","����","��","���","������","�'���","�����","��","���","���'���"},
		{"","������","��������","��������","�����","�'�������","���������","�������","��������","���'������"},
		{"","���","����","������","���������","�'�����","�������","������","������","���'�����"},
		{"","����","���","���","������","�'���","�����","��","���","���'���"},
		{"","������","��������","��������","�����","�'�������","����������","�������","��������","���'������"},
		{"","���","����","������","���������","�'�����","�������","�����","������","���'�����"},
		{"","����","���","��� ","������","�'���","�����","��","���","���'���"} };


	string termination[10][10] = {
		{"","","","�����","","","�������","","","�������"},
		{"","","","������","","","������","","","������"},
		{"","","","������","","","�������","","","�������"},
		{"","","","������","","","�������","","","�������"},
		{"","","","������","","","�������","","","�������"},
		{"","","","�����","","","�������","","","�������"},
		{"","","","�����","","","�������","","","�������"},
		{"","","","�����","","","�������","","","�������"},
		{"","","","�����","","","�������","","","�������"},
		{"","","","�����","","","�������","","","�������"} };

	string dec[10] = { "������","����������","����������","����������","������������","�'���������","�����������","���������","����������","���'���������" };
	string result;

	if (!numb) {
		result = "���� ";
	}
	int n1 = numb;
	int cnt = 0;

	//��������� ������� ������� � ����
	while (numb) {
		numb /= 10;
		cnt++;
	}
	int cile = 0;

	while (n1) {
		if (!((cnt + 1) % 3)) {
			if ((n1 / osn[cnt]) == 1) {
				n1 %= osn[cnt];
				--cnt;
				cile = n1 / osn[cnt];
				n1 %= osn[cnt];
				result += dec[cile];
				--cnt;
				if (!(cnt % 3))
					result += " " + termination[0][cnt] + " ";
			}
			if (!cnt) break;
		}
		cile = n1 / osn[cnt];
		n1 %= osn[cnt];
		result += basis[cnt][cile] + " ";
		--cnt;
		if (!(cnt % 3))
			result += termination[cile][cnt] + " ";
	}
	cout << "�� ������ ������� " << result << "������� " << fixed << setprecision(0) << frac * 100 << " ������";
	cout << endl;
}

double Account::Total(const Account& a) {
	int hrn, kop;
	double sum;
	hrn = a.summa.getH500() * 500 + a.summa.getH200() * 200 + a.summa.getH100() * 100 +
		a.summa.getH50() * 50 + a.summa.getH20() * 20 + a.summa.getH10() * 10 + a.summa.getH5() * 5 + a.summa.getH2() * 2 + a.summa.getH1();
	kop = a.summa.getC50() * 50 + a.summa.getC25() * 25 + a.summa.getC10() * 10 + a.summa.getC5() * 5 + a.summa.getC2() * 2 + a.summa.getC1();
	sum = (double)hrn + (double)kop / 100.;
	return sum;
}

Account Account::Add(const Account& x, const Account& y, Account& a)
{
	double subt = Total(x) + Total(y);
	int hrn = (int)subt;
	int coin = (floor((subt - hrn) * 100 + 0.501));

	return Change(hrn, coin, a);
}

Account Account::Subtract(const Account& x, const Account& y, Account& a)
{
	double subt = Total(x) - Total(y);
	if (subt <= 0)
	{
		cerr << "Sum on first account is lesser than that on the latter.\n";
	}
	else
	{
		int hrn = (int)subt;
		int coin = (floor((subt - hrn) * 100 + 0.501));

		return Change(hrn, coin, a);
	}
}

Account Account::Multiply(Account& x, const double y)
{
	if (y <= 0)
		Account(x);
	else
	{
		if (y != 1)
		{
			double sum = Total(x);
			sum *= y;
			int hrn = (int)sum;
			int coin = (floor((sum - hrn) * 100 + 0.501));

			return Change(hrn, coin, x);
		}
		else
			Account(x);
	}
	return x;
}

Account Account::Division(Account& x, const double y)
{
	if (y == 0)
		Account(x);
	else
	{
		if (y != 1)
		{
			double sum = Total(x);
			sum = sum / y;
			int hrn = (int)sum;
			int coin = (floor((sum - hrn) * 100 + 0.501));

			return Change(hrn, coin, x);
		}
		else
			Account(x);
	}
	return x;
}

Account Account::DivOfSums(const Account& x, const Account& y, Account& a)
{
	double subt = Total(x) / Total(y);
	int hrn = (int)subt;
	int coin = (floor((subt - hrn) * 100 + 0.501));

	return Change(hrn, coin, a);
}

Account Account::Change(int hrn, int coin, Account& d)
{
	d.summa.setH500(hrn / 500);
	hrn -= d.summa.getH500() * 500;
	d.summa.setH200(hrn / 200);
	hrn -= d.summa.getH200() * 200;
	d.summa.setH100(hrn / 100);
	hrn -= d.summa.getH100() * 100;
	d.summa.setH50(hrn / 50);
	hrn -= d.summa.getH50() * 50;
	d.summa.setH20(hrn / 20);
	hrn -= d.summa.getH20() * 20;
	d.summa.setH10(hrn / 10);
	hrn -= d.summa.getH10() * 10;
	d.summa.setH5(hrn / 5);
	hrn -= d.summa.getH5() * 5;
	d.summa.setH2(hrn / 2);
	hrn -= d.summa.getH2() * 2;
	d.summa.setC50(coin / 50);
	coin -= d.summa.getC50() * 50;
	d.summa.setC25(coin / 25);
	coin -= d.summa.getC25() * 25;
	d.summa.setC10(coin / 10);
	coin -= d.summa.getC10() * 10;
	d.summa.setC5(coin / 5);
	coin -= d.summa.getC5() * 5;
	d.summa.setC2(coin / 2);
	coin -= d.summa.getC2() * 2;
	
	return d;
}

bool Less(Account a, Account b) {
	return a.summa.Total() < b.summa.Total();
}
bool NLess(Account a, Account b) { return !Less(a, b); }

bool Great(Account a, Account b) {
	return a.summa.Total() > b.summa.Total();
}
bool NGreat(Account a, Account b) { return !Great(a, b); }

bool Equal(Account a, Account b) {
	return a.summa.Total() == b.summa.Total();
}
bool NEqual(Account a, Account b) { return !Equal(a, b); }
