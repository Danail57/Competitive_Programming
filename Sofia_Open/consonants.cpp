#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text;
	cin >> text;

	string vowels = "aeiouyAEIOUY";
	int current = 0;
	int best = 0;

	for (char c : text)
	{
		if (vowels.find(c) == string::npos)
		{
			current++;
			if (current > best)
			{
				best = current;
			}
		}
		else {
			current = 0;
		}
	}
	cout << best;
	return 0;
}
