/*Проверка дали числото е произведение на
две прости числа*/


#include <iostream>
using namespace std;

bool is_prime(int x)
{
	if (x < 2)
		return false;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	
	bool found = false;

	for (int i = 2; i <= n / 2; i++)
	{
		if (is_prime(i))
		{
			int j = n / i;
			if (i * j == n && is_prime(j))
			{
				cout << n << " = " << i << " * " << j << endl;
				found = true;
				break;
			}
		}
	}
	if (!found)
	{
		cout << n << " is not a multiplication on two prime numbers." << endl;
	}
	return 0;
}
