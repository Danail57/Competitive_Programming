#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack <char> symbols;
	stack <int> numbers;

	int N;
	char S;
	int current_number;

	do
	{
		cin >> S;
		cin >> N;
		numbers.push(N);
		symbols.push(S);
	} while (symbols.top() != '=');
	

	current_number = numbers.top();
	numbers.pop();
	symbols.pop();


	while (numbers.empty() == false)
	{
		switch (symbols.top())
		{
		case '+':
			current_number -= numbers.top();
			break;

		case '-':
			current_number += numbers.top();
			break;

		case '*':
			current_number /= numbers.top();
			break;

		case '/':
			current_number /= numbers.top();
			break;
		}
		numbers.pop();
		symbols.pop();
	}
	cout << current_number << endl;
	return 0;
}
