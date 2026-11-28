Here is the C++ code for the problem:

#include <iostream>

using namespace std;

int findSquareRoot(long long n) {
    long long start = 0;
    long long end = n;
    while (start < end) {
        long long mid = start + (end - start) / 2;
        if (mid * mid == n)
            return mid;
        if (mid * mid < n)
            start = mid + 1;
        else
            end = mid;
    }
    return start - 1;
}

int main() {
    long long n;
    cin >> n;
    if (n < 0) {
        cout << "Invalid input";
        return 0;
    }
    cout << findSquareRoot(n);
    return 0;
}
This program works by using a binary search to find the integer square root of a given number. The `findSquareRoot` function implements this search. The `main` function reads a non-negative integer `n`, checks if `n` is negative, and if so, returns an error message. If `n` is not negative, it calls `findSquareRoot` to find the square root and prints the result.