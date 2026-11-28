#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    int prefixSum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        prefixSum += numbers[i];
        if (prefixSum % K == 0) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}