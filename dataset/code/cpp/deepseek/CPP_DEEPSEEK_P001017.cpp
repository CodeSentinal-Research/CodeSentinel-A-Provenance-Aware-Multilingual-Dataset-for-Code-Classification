Here is the C++ solution for the given problem.

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long sum = 0;

    for(int i = 0; i < n; i++) {
        long long rope;
        cin >> rope;
        pq.push(rope);
        sum += rope;
    }

    long long minCost = 0;
    while(pq.size() > 1) {
        long long rope1 = pq.top(); pq.pop();
        long long rope2 = pq.top(); pq.pop();
        long long cost = rope1 + rope2;
        minCost += cost;
        pq.push(cost);
    }

    cout << minCost;
    return 0;
}

This code first takes the number of ropes as input. Then it takes the lengths of all the ropes as input. The lengths are pushed into a priority queue, which is a specialized data structure that allows us to quickly get the smallest element in the queue. The priority queue is used to ensure that the smallest rope is always at the top of the queue. 

In a while loop, the smallest two ropes are taken from the queue, their sum is calculated as the cost of connecting them, and this cost is added to the minimum cost. The second smallest rope is then pushed into the queue. The loop continues until only one rope is left in the queue. 

Finally, the minimum cost is printed.