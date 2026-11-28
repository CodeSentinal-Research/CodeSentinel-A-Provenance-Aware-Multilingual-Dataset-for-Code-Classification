#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool canPartition(string s, int k, int start, vector<int>& counts) {
    if (start == s.length()) {
        for (int c : counts) {
            if (c % 2 != 0 && c != 0) return false; // Palindrome condition: at most one odd count
        }
        // Actually, we need K palindromes.
        // Each palindrome can have at most one odd char.
        // So total odd chars <= K.
        int oddCount = 0;
        for (int c : counts) {
            if (c % 2 != 0) oddCount++;
        }
        return oddCount <= k;
    }
    
    counts[s[start]-'a']++;
    if (canPartition(s, k, start + 1, counts)) return true;
    counts[s[start]-'a']--;
    
    return false;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    vector<int> counts(26, 0);
    cout << (canPartition(s, k, 0, counts) ? "YES" : "NO") << endl;
    return 0;
}
