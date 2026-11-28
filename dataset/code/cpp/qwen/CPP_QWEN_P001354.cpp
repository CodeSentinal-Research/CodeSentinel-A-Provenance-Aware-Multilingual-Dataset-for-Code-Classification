#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isFibonacci(vector<long long>& seq) {
    if (seq.size() < 3) return false;
    for (int i = 2; i < seq.size(); ++i) {
        if (seq[i] != seq[i-1] + seq[i-2]) return false;
    }
    return true;
}

bool splitFibonacci(string s, int start, vector<long long>& current) {
    if (start == s.length()) {
        return current.size() >= 3 && isFibonacci(current);
    }
    
    long long num = 0;
    for (int i = start; i < s.length(); ++i) {
        if (i > start && s[start] == '0') break;
        num = num * 10 + (s[i] - '0');
        if (num > INT_MAX) break;
        
        if (current.size() < 2 || num == current.back() + current[current.size()-2]) {
            current.push_back(num);
            if (splitFibonacci(s, i + 1, current)) return true;
            current.pop_back();
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    vector<long long> current;
    if (splitFibonacci(s, 0, current)) {
        for (size_t i = 0; i < current.size(); ++i) {
            if (i > 0) cout << " ";
            cout << current[i];
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
