#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int E, F;
    cin >> E >> F;

    int low = 1, high = F, mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (mid <= E) {
            if ((mid + 1) > E) {
                cout << mid << endl;
                return 0;
            } else {
                low = mid + 1;
            }
        } else {
            high = mid - 1;
        }
    }
    cout << mid << endl;
    return 0;
}
This solution uses a binary search approach to find the minimum number of attempts required to identify the highest safe floor. The idea is to keep dividing the total number of floors (F) by the number of eggs (E), rounding up the result to the nearest whole number. This gives us the maximum number of attempts we need to find the highest safe floor.

Please note that this solution assumes that the eggs will break when the floor we're checking is lower than the current guess. If we were to start with the floor of 1 and continue to the square root of F (the maximum safe floor), we would miss the highest safe floor.