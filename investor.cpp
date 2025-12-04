#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	long long N_number_of_deposit;
	long long S_value_of_N;

	
	cin >> N_number_of_deposit;
	cin >> S_value_of_N;

	vector<long long> F(N_number_of_deposit + 1);
	F[1] = 1;
	F[2] = 1;

	for (long long i = 3; i <= N_number_of_deposit; i++)
	{
		F[i] = F[i - 1] + F[i - 2];
	}

	long long x = F[N_number_of_deposit - 2];
	long long y = F[N_number_of_deposit - 1];
	long long count_decisions = 0;


	// НОК
	/*	for (long long i = min(N_number_of_deposit, S_value_of_N); i >= 1; i--)
	{
		if (N_number_of_deposit % i == 0 && S_value_of_N % i == 0)
		{
			cout << i;
		}
	}*/

	// НОД и алгоритъм на Евклид
	while (x != 0)
	{
		y %= x;
		swap(x, y);
	}
	
	if (S_value_of_N % y == 0)
	{
		long long value = S_value_of_N;
		value /= y;

		x = F[N_number_of_deposit - 2] / y;
		y = F[N_number_of_deposit - 1] / y;

		long long currR = x, nextR = y;
		long long currS = 1, nextS = 0;
		long long currT = 0, nextT = 1;

		while (nextR) 
		{
			long long quotient = currR / nextR;
			long long prevR = currR; currR = nextR; nextR = prevR - quotient * nextR;
			long long prevS = currS; currS = nextS; nextS = prevS - quotient * nextS;
			long long prevT = currT; currT = nextT; nextT = prevT - quotient * nextT;
		}
		long long x0 = currS, y0 = currT;
		x0 *= value;
		y0 *= value;

		long long min_x;
		long long max_x;

		if (x0 % y == 0)
		{
			min_x =- 1 * x0 / y + 1;
		}
		else
		{
			min_x = ceil(-1.0 * x0 / y);
		}

		if (y0 % x == 0)
		{
			max_x = y0 / x - 1;
		}
		else
		{
			max_x = floor(1.0 * y0 / x);
		}

		if (max_x >= min_x)
		{
			cout << max_x - min_x + 1 << endl;
		}
		else
		{
			cout << 0 << '\n';
		}
	}
	else
	{
		cout << 0 << '\n';
	}
	return 0;

}
