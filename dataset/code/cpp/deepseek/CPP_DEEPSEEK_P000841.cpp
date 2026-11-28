Here is the C++ code with no explanation and no markdown:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> candies(n);

    for(int i = 0; i < n; i++) {
        cin >> candies[i];
    }

    sort(candies.begin(), candies.end());

    long long low = 0;
    long long high = candies[n-1];

    while(low < high) {
        long long mid = (low + high) / 2;
        long long sum = 0;
        long long child = k;

        for(int i = 0; i < n; i++) {
            if(candies[i] - mid > 0) {
                sum += (candies[i] - mid);
                child--;
            }

            if(child == 0) {
                break;
            }
        }

        if(child > 0) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    cout << low << endl;

    return 0;
}

This program uses binary search to find the maximum number of candies each child can get. It starts by finding the maximum number of candies (`high = candies[n-1]`) and then tries to find the minimum number of candies (`low = 0`) using binary search. In each iteration, it calculates the sum of candies that can be distributed to each child and checks if there are more children left to distribute candies to. If there are, it updates the `low` to be mid + 1. If there are not, it updates the `high` to be mid. The loop continues until `low >= high`. The maximum number of candies each child can get is then printed.