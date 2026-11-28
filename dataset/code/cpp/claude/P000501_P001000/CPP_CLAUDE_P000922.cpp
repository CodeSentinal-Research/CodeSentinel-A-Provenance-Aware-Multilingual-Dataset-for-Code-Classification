#include <iostream>
using namespace std;
class Solution {
public:
    int sumOfDigits(long long n) {
        if (n < 0) n = -n;
        int s = 0;
        while (n > 0) { s += n%10; n /= 10; }
        return s;
    }
};
int main() {
    long long n; cin >> n;
    cout << Solution().sumOfDigits(n) << "\n";
}
