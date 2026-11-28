#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    string result = "";
    for (int i = 0; i < n; ++i) {
        int remainingChars = n - i - 1;
        int minNeeded = remainingChars; // 'a' for rest
        int maxNeeded = remainingChars * 26; // 'z' for rest
        
        for (char c = 'a'; c <= 'z'; ++c) {
            int val = c - 'a' + 1;
            if (k - val >= minNeeded && k - val <= maxNeeded) {
                result += c;
                k -= val;
                break;
            }
        }
    }
    
    cout << result << endl;
    return 0;
}
