#include <iostream>
#include <vector>
using namespace std;

/*Програма за извеждане на простите числа по алгоритъм на Ерапстен.*/

/*Започваме от p*p, защото всички по-малки, кратни на p,
вече са били елиминирани от по-малките прости числа.*/

vector<int> sieve(int n)
	{
		vector<bool> prime(n + 1, true);
		
		for (int p = 2; p * p <= n; p++)
		{
			if (prime[p] == true)
			{
				for (int i = p * p; i <= n; i += p)
					prime[i] = false;
			}
		}

		vector<int> result;
		for (int p = 2; p <= n; p++)
		{
			if (prime[p])
			{
				result.push_back(p);
			}
		}
		return result;
	}

int main()
{
	int n;
	cin >> n;
	vector<int> result = sieve(n);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}
