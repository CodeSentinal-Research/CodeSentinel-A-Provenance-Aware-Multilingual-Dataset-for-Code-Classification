#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string order, s;
    cin >> order >> s;
    unordered_map<char, int> count;
    for (char c : s) count[c]++;
    string res = "";
    for (char c : order) {
        while (count[c] > 0) {
            res += c;
            count[c]--;
        }
    }
    for (auto& p : count) {
        while (p.second > 0) {
            res += p.first;
            p.second--;
        }
    }
    cout << res << endl;
    return 0;
}
