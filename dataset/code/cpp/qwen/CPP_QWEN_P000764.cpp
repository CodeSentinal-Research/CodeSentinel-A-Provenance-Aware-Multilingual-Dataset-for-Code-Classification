#include <iostream>
#include <string>
using namespace std;

long long getSize(const string& s, int idx, long long currentSize) {
    if (idx == s.length()) return currentSize;
    if (isdigit(s[idx])) {
        return getSize(s, idx + 1, currentSize * (s[idx] - '0'));
    } else {
        return getSize(s, idx + 1, currentSize + 1);
    }
}

char solve(const string& s, int idx, long long K, long long currentSize) {
    if (idx == -1) return ' ';
    if (isdigit(s[idx])) {
        long long prevSize = currentSize / (s[idx] - '0');
        long long newK = K % prevSize;
        return solve(s, idx - 1, newK, prevSize);
    } else {
        long long prevSize = currentSize - 1;
        if (K == prevSize) return s[idx];
        return solve(s, idx - 1, K, prevSize);
    }
}

int main() {
    string s;
    long long K;
    cin >> s >> K;
    long long totalSize = getSize(s, 0, 0);
    K--; // Convert to 0-indexed
    cout << solve(s, s.length() - 1, K, totalSize) << endl;
    return 0;
}
