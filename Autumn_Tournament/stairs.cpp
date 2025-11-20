#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int N_stone_bricks;
	int K_milimetres;
	int S_count_stairs = 0;

	vector <int> stairs(N_stone_bricks);

	cin >> N_stone_bricks;
	cin >> K_milimetres;


	for (int i = 0; i < N_stone_bricks; i++)
	{
		cin >> stairs[i];
	}


	int total_length = 0;
	for (int i = 0; i < N_stone_bricks; i++)
	{
		total_length += stairs[i];
	}
	cout << total_length << endl;
	if (total_length == K_milimetres)
	{
		cout << N_stone_bricks << endl;
	} else {
		return 0;
	}

}
