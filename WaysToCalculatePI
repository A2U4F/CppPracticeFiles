#include<iostream>
#include<math.h>
#include<Windows.h>
#include<random>
#include<time.h>
#include <list>

using namespace std;

void Leibniz_formula();
void Piece_of_cycle();
void Line_of_cycle();
void Random_point();
void Slid_the_cycle();
void Infinite();

int main()
{

	SetConsoleTitle(L"made by A2U4F version 0.50");
	int col=10;

	while (col!=0)
	{
		cout << "Please choose the way to calculate PI:" << endl
			<< "1......Leibniz_formula" << endl
			<< "2......Piece_of_cycle" << endl
			<< "3......Line_of_cycle" << endl
			<< "4......Random_point" << endl
			<< "5......Slid_the_cycle" << endl
			<< "6......Infinite" << endl;

		cin >> col;
		system("cls");

		switch (col)
		{
		case 1:
			Leibniz_formula();
			break;
		case 2:
			Piece_of_cycle();
			break;
		case 3:
			Line_of_cycle();
			break;
		case 4:
			Random_point();
			break;
		case 5:
			Slid_the_cycle();
			break;
		case 6:
			Infinite();
			break;
		default:
			cout << "I can't find it......" << endl
				<<endl<<endl;
		}
	}
		system("pause");
	return 0;
}



void Leibniz_formula()
{
	double i = 1.0;
	double pi = 0.0;
	double k = 1.0;
	double t = 1.0;
	double c = 1e-8;

	while (fabs(t) >= c)
	{
		pi += t;
		k = -k;
		i += 2;
		t = k / i;
	}

	pi *= 4;
	cout << "pi = " << pi
		<< endl
		<< "precision = " << c * 10;

	cout 
		<< endl
		<< endl
		<< endl;
}

void Piece_of_cycle()
{
	double x=0.0, y=0.0;
	double c = 0.001;
	double init=0, total=0;
	double pi;

	do{
		 do{
			x += c;
			total += 1;
			if (pow(x, 2) + pow(y, 2) <= 100)init += 1;
		}while (x <= 10);
		x = 0;
		y += c;
	} while (y <= 10);

	pi =4* (init / total);
	cout << "pi = " << pi<< endl
		<< "init = " << init<<endl
		<<"total = "<<total<<endl;

	cout
		<< endl
		<< endl
		<< endl;
}

void Line_of_cycle()
{
	double x = 0.0, y = 0.0;
	double c = 0.00001;
	double init = 0, total = 0, added = 0;
	double pi;

	x += c;
	y += c;
	while (x <= 10) {
		added += 1;
		x += c;
	}

	total = pow(added, 2);

	x = 10;

	while (y <= 10) {
		while (pow(x, 2) + pow(y, 2) >= 100) {
			added -= 1;
			x -= c;
		}
		init += added;
		y += c;
	}

	pi = 4 * (init / total);
	cout << "pi = " << pi << endl
		<< "init = " << init << endl
		<< "total = " << total << endl;

	cout
		<< endl
		<< endl
		<< endl;
}

void Random_point()
{
	srand(time(0)*100+56);

	long long int c = 1000000;
	long double init = 0;
	long double total = 0;
	double pi=0.0;

	for (int timeo = 1; timeo <= 100; timeo++) {
		for (long long int timei = 1; timei <= c; timei++) {
			double x = rand() / static_cast<double>(32767);
			double y = rand() / static_cast<double>(32767);
			total += 1;
			if (pow(x, 2) + pow(y, 2) <= 1)init += 1;
		}
		system("cls");
		cout << "进度条" << timeo << "%";
	}

	cout << endl;

	pi = 4 * (init / total);
	cout
		<< "pi = " << pi << endl
		<< "init = " << init << endl
		<< "total = " << total;

	cout
		<< endl
		<< endl
		<< endl;
}

void Slid_the_cycle()
{
	double cosrate = 0.50;
	double line = 6;
	double pi = 0.50;

	for (int t = 1; t <= 10; t++) {
		cosrate = sqrt((cosrate + 1) / 2);
		line *= sqrt(2 / (cosrate + 1));
		cout << "pi == " << pi * line << endl;
	}

	pi *= line;

	cout << "pi = " << pi << endl;

	cout
		<< endl
		<< endl
		<< endl;
}

int count(int n)
{
	int i = 1;
	double sum = 0;
	int a, b;
	while (1)
	{
		a = 2 * i + 1;
		b = i;
		sum = sum + log10(a / b);
		i++;
		if (sum > n + 1) {
			return i;
		}
	}
}

void Infinite()
{
	cout << "Please enter the digit you want to calculate:" << endl;
#define NODE_NUM 550
	list<int> num(NODE_NUM, 0);
	list<int> sum(NODE_NUM, 0);
	int print;
	cin >> print;
	int cnt = count(print);

	num.front() = 2;
	sum.front() = 2;

	for (int i = 1; i <= cnt; ++i)
	{
		int ret = 0;

		for (list<int>::reverse_iterator cur1 = num.rbegin(); cur1 != num.rend(); cur1++)
		{
			int val = *cur1 * i + ret;
			ret = val / 10;
			*cur1 = val % 10;
		}

		ret = 0;

		for (list<int>::iterator cur1 = num.begin(); cur1 != num.end(); cur1++)
		{
			int div = (i << 1) + 1;
			int val = *cur1 + ret * 10;
			*cur1 = val / div;
			ret = val - *cur1 * div;
		}

		ret = 0;

		for (auto cur2 = sum.rbegin(), cur1 = num.rbegin(); cur2 != sum.rend(); cur2++, cur1++)
		{
			int val = *cur1 + *cur2 + ret;
			*cur2 = val % 10;
			ret = val / 10;
		}

	}


	cout << sum.front() << '.';
	list<int>::iterator it = sum.begin();
	it++;

	int i = 0;
	while (i < print)
	{
		cout << *it;
		it++;
		i++;
	}

	cout 
		<< endl
		<< endl
		<< endl;
}
