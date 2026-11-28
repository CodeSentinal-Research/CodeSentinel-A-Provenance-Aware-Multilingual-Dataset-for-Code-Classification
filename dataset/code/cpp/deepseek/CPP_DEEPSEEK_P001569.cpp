#include <iostream>
#include <unordered_set>
#include <deque>
using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> dq;
    unordered_set<int> s;
    long long sum = 0, maxSum = 0;

    while(n--) {
        int num;
        cin >> num;

        if(s.find(num) == s.end()) {
            dq.push_back(num);
            sum += num;
            s.insert(num);
        } else {
            while(dq.front() != num) {
                sum -= dq.front();
                dq.pop_front();
            }
            dq.pop_front();
        }

        maxSum = max(maxSum, sum);
    }

    cout << maxSum;

    return 0;
}