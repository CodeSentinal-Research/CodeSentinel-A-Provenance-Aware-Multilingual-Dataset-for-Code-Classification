#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K, D;
    cin >> N >> K >> D;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    int count = 0;
    for (int i = 0; i <= N - K; i++) {
        int sum = 0;
        for (int j = i; j < i + K; j++) {
            sum += nums[j];
        }
        if (sum % D == 0) {
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}