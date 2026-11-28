#include <iostream>
#include <unordered_set>
#include <deque>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    deque<int> dq;
    unordered_set<int> uset;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        dq.push_back(num);

        if (dq.size() > K) {
            uset.erase(dq.front());
            dq.pop_front();
        }

        if (i >= K - 1) {
            cout << uset.size() << " ";
        }
    }

    cout << endl;

    return 0;
}