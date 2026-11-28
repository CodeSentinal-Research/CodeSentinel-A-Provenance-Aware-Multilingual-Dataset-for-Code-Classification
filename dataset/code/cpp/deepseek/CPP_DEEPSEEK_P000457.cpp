#include <iostream>
using namespace std;

int main() {
    int n, threshold;
    cin >> n >> threshold;
    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    int min_divisor = INT_MAX;
    for (int i = 1; i <= threshold; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += nums[j] / i;
        }
        if (sum <= threshold) {
            min_divisor = min(min_divisor, i);
        }
    }
    
    cout << min_divisor << endl;
    
    return 0;
}
This code first reads in the number of inputs and the threshold. Then it reads in the list of numbers. The main part of the code is a nested loop that tries all possible divisors from 1 to the threshold. For each divisor, it calculates the sum of the division results and checks if this sum is less than or equal to the threshold. If it is, it updates the minimum divisor if the current divisor is smaller. Finally, it outputs the smallest divisor that satisfies the condition.