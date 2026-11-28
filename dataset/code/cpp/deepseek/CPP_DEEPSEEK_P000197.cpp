#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    deque<int> q;
    int sum = 0;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        sum += num;
        q.push_back(num);

        if (i >= K) {
            sum -= q.front();
            q.pop_front();
        }
    }

    cout << sum << endl;

    return 0;
}