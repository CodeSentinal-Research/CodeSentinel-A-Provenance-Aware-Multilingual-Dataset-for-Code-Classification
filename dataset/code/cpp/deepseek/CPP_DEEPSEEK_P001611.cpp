#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int res = N + 1;
    std::deque<int> d;
    for (int i = 0; i < N; i++) {
        while (!d.empty() && A[i] < A[d.back()]) {
            d.pop_back();
        }
        d.push_back(i);
   
        if (A[i] >= K) {
            res = std::min(res, i - d.front());
        }
    }

    if (res == N + 1) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << res << std::endl;
    }

    return 0;
}