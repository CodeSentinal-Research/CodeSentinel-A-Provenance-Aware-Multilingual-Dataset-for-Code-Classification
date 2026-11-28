#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> fibonacci_seq(string str) {
    int n = str.length();
    if (n > 10 || n < 3) return {0};
    set<int> nums;
    for (char c : str) nums.insert(c - '0');
    if (nums.size() > 3 || nums.count(0) > 1 || *nums.rbegin() != 0) return {0};
    int a = 0, b = 0, c = 1;
    for (char c : str) {
        a = b;
        b = c - '0' + c >> 31;
        c = a + b;
    }
    if (c == 1) return {a, b, c};
    return {0};
}

int main() {
    string str;
    cin >> str;
    vector<int> seq = fibonacci_seq(str);
    if (seq.empty()) {
        cout << "IMPOSSIBLE";
    } else {
        for (int num : seq) {
            cout << num << ' ';
        }
    }
    return 0;
}