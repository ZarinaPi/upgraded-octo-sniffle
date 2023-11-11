// попытка_хз_какая.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <bitset>
using namespace std;

int swap(int n, int p, int q)
{
	if (((n & (1 << p)) >> p) ^ ((n & (1 << q)) >> q))
	{
		n ^= (1 << p);
		n ^= (1 << q);
	}
	return n;
}

int main()
{
	setlocale(0, "RUS");
	cout << sizeof(int) << "\n";
	cout << sizeof(short int) << "\n";
	cout << sizeof(long int) << "\n";
	cout << sizeof(float) << "\n";
	cout << sizeof(double) << "\n";
	cout << sizeof(long double) << "\n";
	cout << sizeof(char) << "\n";
	cout << sizeof(bool) <<"\n";
	
	int value = -127;
	unsigned int order = 32;
	unsigned int mask = 1 << order - 1;
	for (int i = 1; i <= order; i++)
	{
		putchar(value & mask ? '1' : '0');
		value <<= 1;
		if (i % 8 == 0)
		{
			putchar(' ');
		}
		if (i % order - 1 == 0)
		{
			putchar(' ');
		}
	}
	cout << "\n";
	union
	{
		int value_f;
		float numb_f = 3.14;
	};
	for (int i = 1; i <= order; i++)
	{
		putchar(value_f & mask ? '1' : '0');
		value_f <<= 1;
		if (i % 8 == 0)
		{
			putchar(' ');
		}
		if (i % order - 1 == 0)
		{
			putchar(' ');
		}
	}
	cout << "\n";
	union
	{
		int arr[2];
		double numb_d = 0.1;
	};
	unsigned int order_d = 64;
	unsigned int mask_d = 1 << order_d - 1;
	for (int i = 1; i <= order_d; i++)
	{
		putchar(*arr & mask_d ? '1' : '0');
		*arr <<= 1;
		if (i % order_d - 12 == 0)
		{
			putchar(' ');
		}
		if (i % order_d - 1 == 0)
		{
			putchar(' ');
		}
	}
	cout << "\n";


	int p, q, n;
	cout << "Введите число в котором хотите изменить биты\n";
	cin >> n;
	cout << "Введите номера битов, которые хотите поменять местами\n";
	cin >> p;
	p -= 1;
	cin >> q;
	q -= 1;

	cout << n << " битовое представления " << bitset<32>(n) << endl;
	n = swap(n, p, q);
	cout << n << " битовое представления " << bitset<32>(n) << endl;

	return 0;
}