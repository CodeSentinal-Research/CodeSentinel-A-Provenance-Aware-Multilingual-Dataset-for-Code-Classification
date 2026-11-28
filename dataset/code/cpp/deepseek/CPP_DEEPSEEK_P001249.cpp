#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        pq.push(a);
    }
    int totalCost = 0;
    while(pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        int sum = first + second;
        totalCost += sum;
        pq.push(sum);
    }
    cout << totalCost;
    return 0;
}