Here is the C++ code for the given problem:

#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long start = 0;
    long long end = n;
    while (start < end) {
        long long mid = (start + end + 1) / 2;
        if (mid * mid > n) {
            end = mid - 1;
        } else {
            start = mid;
        }
    }
    cout << start;
    return 0;
}

This code works by using binary search to find the square root of the given number. It initializes the start and end of the range to be searched. Then it enters a loop where it calculates the midpoint of the current range and checks if the midpoint squared is greater than the target. If it is, then the range to the left of the midpoint is discarded and the range to the right of the midpoint is considered. If not, then the range to the right of the midpoint is considered. This process continues until the range size becomes 1 (i.e., start == end). The final value of start is the integer square root of n.