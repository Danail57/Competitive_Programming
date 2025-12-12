/*Произведение на две прости числа ≤ N*/

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

	for (int i = 2; i <= n / 2; i++)
	{
		if (!is_prime(i)) continue;
		for (int j = i; j <= n; j++)
		{
			if (!is_prime(j)) continue;
			if (i * j <= n)
				cout << i << " * " << j << " = " << i * j << endl;
		}
	}
	return 0;
}
