#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(long long n) {
        if (n < 0) return false;
        long long original = n, rev = 0;
        while (n > 0) { rev = rev*10 + n%10; n /= 10; }
        return original == rev;
    }
};
int main() {
    long long n; cin >> n;
    cout << (Solution().isPalindrome(n) ? "Yes" : "No") << "\n";
}
