/*Дадени са два низа 𝑠 и 𝑝, съставени от малки
 *латински букви. Напишете програма small,
 *която намира най-късия подниз на 𝑠, който
 *съдържа всичките елементи на 𝑝.
 *Търсеният подниз трябва да съдържа последователни
 *елементи на 𝑠. Ако низът 𝑝 има повтарящи се букви,
 *търсеният подниз на 𝑠 трябва да съдържа толкова пъти
 *всяка от тези букви, колкото пъти тя се повтаря в 𝑝.
 * На първия ред във входа е записан низът 𝑠.
 * На втория ред във входа е записан низът 𝑝
 */

#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main()
{
    string s, p;
    cin >> s >> p;

    int need[26] = {0};
    int have[26] = {0};
    for (int i = 0; i < p.size(); i++)
        need[p[i] - 'a']++; // превръща буквата в индекс от 0 до 25

    int left = 0;
    int best_len = INT_MAX;
    int best_start = 0;
    int missing = p.size();

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        have[c - 'a']++;
        if (need[c - 'a'] > 0 && have[c - 'a'] <= need[c - 'a'])
            missing--;
        while (missing == 0) {
            if (right - left + 1 < best_len) {
                best_len = right - left + 1;
                best_start = left;
            }
            char lc = s[left];
            have[lc - 'a']--;
            if (need[lc - 'a'] > 0 && have[lc - 'a'] < need[lc - 'a'])
                missing++;
            left++;
        }
    }
    if (best_len == INT_MAX)
        cout << -1 << endl;
    else
        cout << s.substr(best_start, best_len) << endl;
}
