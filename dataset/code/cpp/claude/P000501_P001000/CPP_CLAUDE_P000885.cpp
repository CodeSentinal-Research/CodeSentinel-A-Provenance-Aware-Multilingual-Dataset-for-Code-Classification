#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    bool isArmstrong(int n) {
        int temp = n, digits = 0, sum = 0;
        while (temp > 0) { digits++; temp /= 10; }
        temp = n;
        while (temp > 0) {
            int d = temp % 10;
            sum += (int)pow(d, digits);
            temp /= 10;
        }
        return sum == n;
    }
};
int main() {
    int n; cin >> n;
    cout << (Solution().isArmstrong(n) ? "Armstrong" : "Not Armstrong") << "\n";
}
