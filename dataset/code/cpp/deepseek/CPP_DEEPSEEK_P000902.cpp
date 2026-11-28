#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, Q, X;
    cin >> N >> X;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        int count = 0;
        for (int j = L; j <= R; j++) {
            if (nums[j] % X == 0) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}