/*Напишете програма WORDS, която чете последователност
 *от думи и съставя възможно най-дългата редица от думи,
 *за която всяка следваща дума започва
 *с последната буква на предходната
 *(new – word – door …), като ако съществува такава дума,
 *то тя е единствена.
 *Всяка дума може да се използва само по веднъж.
 *От първия ред на стандартния вход се въвежда
 *n – брой думи. На всеки от следващите n реда се
 *въвежда по една дума. На първия ред на стандартния изход
 *се извежда число b - броя на думите в редицата и на
 *всеки от следващите редове по една дума от нея.
 *Ако съществуват две редици с еднаква дължина се
 *извежда тази, чиято първа дума е по-напред по
 *азбучен ред. Ако липсват думи, отговарящи
 *на условието сe извежда 0.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> words;
vector<bool> used;
vector<string> best_chain;
vector<string> current_chain;

void backtrack()
{
    bool extended = false;
    for (int i = 0; i < words.size(); i++) {
        if (!used[i]) {
            if (current_chain.empty() || current_chain.back().back() == words[i][0]) {
                used[i] = true;
                current_chain.push_back(words[i]);
                backtrack();
                current_chain.pop_back();
                used[i] = false;
                extended = true;
            }
        }
    }
    if (!extended) {
        if (current_chain.size() > best_chain.size()) {
            best_chain = current_chain;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    words.resize(n);
    used.resize(n, false);
    for (int i = 0; i < n; i++)
        cin >> words[i];
    backtrack();
    cout << best_chain.size() << endl;
    for (int i = 0; i < best_chain.size(); i++)
        cout << best_chain[i] << endl;
}
