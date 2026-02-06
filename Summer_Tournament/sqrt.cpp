/*Дадено е цяло неотрицателно число 𝑎.
 *Напишете програма sqrt, която намира
 *най-голямото цяло число 𝑥, за което 𝑥^2 ≤ 𝑎.
 */

#include <iostream>
using namespace std;

int main()
{
    unsigned long long a;
    cin >> a;

    unsigned long long left = 0;
    unsigned long long right = a;
    unsigned long long answer = 0;
    while (left <= right) {
        unsigned long long mid = left + (right - left) / 2;

        // mid * mid <= a
        if (mid <= a / mid) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << answer << endl;
}
