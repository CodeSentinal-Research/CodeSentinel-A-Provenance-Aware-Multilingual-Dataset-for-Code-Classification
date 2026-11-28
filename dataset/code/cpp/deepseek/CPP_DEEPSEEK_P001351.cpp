#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;
    int k;
    cin >> str >> k;
    sort(str.begin(), str.end());
    vector<string> result;
    do {
        result.push_back(str);
    } while (prev_permutation(str.begin(), str.end()));
    for (string s : result) {
        if (count(s.begin(), s.end(), 'a') == k && count(s.begin(), s.end(), 'b') == k && count(s.begin(), s.end(), 'c') == k && count(s.begin(), s.end(), 'd') == k && count(s.begin(), s.end(), 'e') == k) {
            cout << s << endl;
        }
    }
    return 0;
}