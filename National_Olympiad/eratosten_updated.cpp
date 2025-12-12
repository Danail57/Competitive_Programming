#include <iostream>
using namespace std;

bool is_prime(int a)
{
	for (int i = 2; i * i <= a; i++)
		if (a % i == 0)
			return false;
	return true;
}

int main()
{
	int n;
	cin >> n;
	
	if (n < 9)
		cout << (n / 2) * 2 << endl;
	else
	{
		int i = 1;
		int last_prime = 1;
		while (i * i <= n)
		{
			if (is_prime(i))
				last_prime = i;
			i = i + 2;
		}
		int m1 = last_prime, last_prime2 = last_prime;
		while (last_prime * m1 <= n)
		{
			if (is_prime(m1))
				last_prime2 = m1;
			m1 += 2;
		}
		cout << last_prime * last_prime2 << endl;
	}
	return 0;
}
