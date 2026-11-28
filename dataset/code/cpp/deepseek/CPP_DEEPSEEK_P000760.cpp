#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateIncreasing(int N) {
    vector<int> nums(N);
    for(int i = 0; i < N; i++) {
        nums[i] = i + 1;
    }

    sort(nums.begin(), nums.end());

    do {
        for(int i = 0; i < N; i++) {
            cout << nums[i];
        }
        cout << "\n";
    } while(next_permutation(nums.begin(), nums.end()));
}

int main() {
    int N;
    cin >> N;
    generateIncreasing(N);
    return 0;
}