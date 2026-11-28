#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int maxLength(vector<string>& arr, int index, string current) {
    // Check if current has unique chars
    vector<bool> seen(26, false);
    for (char c : current) {
        if (seen[c-'a']) return 0;
        seen[c-'a'] = true;
    }
    
    if (index == arr.size()) return current.length();
    
    int exclude = maxLength(arr, index + 1, current);
    
    // Include if possible
    string next = current + arr[index];
    vector<bool> seenNext(26, false);
    bool valid = true;
    for (char c : next) {
        if (seenNext[c-'a']) { valid = false; break; }
        seenNext[c-'a'] = true;
    }
    
    int include = 0;
    if (valid) include = maxLength(arr, index + 1, next);
    
    return max(exclude, include);
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    cout << maxLength(arr, 0, "") << endl;
    return 0;
}
