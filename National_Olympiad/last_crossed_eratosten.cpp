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
					cout << "The last crossed number is: " << i << endl;
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
	int last = eratosten(n);
	cout << "The last crossed number: " << last << endl;
	return 0;
}
