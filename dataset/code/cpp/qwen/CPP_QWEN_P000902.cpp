#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, Q;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) cin >> nums[i];
    
    cin >> Q;
    while (Q--) {
        int L, R, X;
        cin >> L >> R >> X;
        int count = 0;
        for (int i = L; i <= R; ++i) {
            if (nums[i] % X == 0) count++;
        }
        cout << count << endl;
    }
    return 0;
}
