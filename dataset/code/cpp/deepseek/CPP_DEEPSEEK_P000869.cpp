Here is a simple solution for the problem using binary search and recursive:

#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return dividend > 0 ? INT_MAX : INT_MIN;
        }
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long long dvd = dividend;
        long long dvs = divisor;
        int sign = (dvd > 0) ^ (dvs > 0) ? -1 : 1;
        dvd = abs(dvd);
        dvs = abs(dvs);
        int res = div(dvd, dvs);
        return res * sign;
    }

private:
    int div(long long dvd, long long dvs) {
        if (dvd < dvs) {
            return 0;
        }
        long long sum = dvs;
        int count = 1;
        while (dvd > sum + sum) {
            sum += sum;
            count += count;
        }
        return count + div(dvd - sum, dvs);
    }
};

int main() {
    Solution solution;
    cout << solution.divide(10, 3) << endl;  
    cout << solution.divide(7, -2) << endl;  
    cout << solution.divide(-10, -2) << endl;  
}

This solution uses the mathematical property that the quotient of the division of two integers is the same as the quotient of the division of the sum of the two integers and the divisor. It uses a binary search to find the maximum sum that can be made up to the dividend. The divisor is subtracted from this sum and the process is repeated until the dividend is less than the sum. The count of the sum and the divisor is added to the result. This process continues until the dividend is less than the sum.