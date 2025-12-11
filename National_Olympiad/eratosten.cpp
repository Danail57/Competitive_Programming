// Напишете програма eratosthen, която намира
// последното задраскано число, ако търсим простите числа от 2 до дадено число n
// включително

#include <iostream>
#include <vector>
using namespace std;

int eratosten(int n)
{
	vector<bool> prime(n + 1, true);
	int last_crossed = -1;

	for (int p = 2; p * p <= n; p++)
	{
		if (prime[p])
		{
			for (int i = p * p; i <= n; i += p)
			{
				if (prime[i])
				{
					prime[i] = false;
					last_crossed = i;
				}
			}
		}
	}
	return last_crossed;
}

int main()
{
	long n;
	cin >> n;
	cout << eratosten(n) << endl;
	return 0;
}
