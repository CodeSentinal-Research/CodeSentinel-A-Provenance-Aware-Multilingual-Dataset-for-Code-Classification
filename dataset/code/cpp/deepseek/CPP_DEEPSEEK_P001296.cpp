Here is the C++ code for the given problem:

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> plantingTimes(n), growingTimes(n);
    for (int &time : plantingTimes) {
        cin >> time;
    }
    for (int &time : growingTimes) {
        cin >> time;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i) {
        pq.push(plantingTimes[i]);
    }

    while (!pq.empty()) {
        int currTime = pq.top();
        pq.pop();
        if (currTime - growingTimes[n - pq.size()] < 0) {
            cout << currTime + plantingTimes[n - pq.size()] << '\n';
            return 0;
        }
        pq.push(currTime - growingTimes[n - pq.size()]);
    }

    return 0;
}
This code first reads the number of plants and their planting and growing times. Then it constructs a priority queue with planting times in decreasing order. It then pops the top planting time and pushes the result of the remaining growing time into the queue. If the remaining growing time is negative, it means the plant cannot grow, so it skips to the next plant. If the remaining growing time is positive, it means the plant can grow, so it adds the remaining growing time to the top of the queue. This continues until all plants are full bloom.