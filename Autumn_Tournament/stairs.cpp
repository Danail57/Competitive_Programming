#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int N_stone_bricks;
    int K_milimetres;
    int S_count_stairs = 0;

    cin >> N_stone_bricks;
    cin >> K_milimetres;

    vector<int> stairs(N_stone_bricks);

    for (int i = 0; i < N_stone_bricks; i++)
    {
        cin >> stairs[i];
    }

    
    sort(stairs.begin(), stairs.end());

    int current_stairs = 1;
    S_count_stairs = 1;

    for (int i = 1; i < N_stone_bricks; i++)
    {
        int diff = stairs[i] - stairs[i - 1];
        if(diff == 0) continue;
        if (diff > 0 && diff <= K_milimetres)
        {
            current_stairs++;
        }
        else
        {
           if (current_stairs > S_count_stairs)
            {
                S_count_stairs = current_stairs;
            }
            current_stairs = 1;
        }

    }

        if (current_stairs > S_count_stairs)
        {
            S_count_stairs = current_stairs;
        }
    cout << S_count_stairs << endl;

    return 0;
}
