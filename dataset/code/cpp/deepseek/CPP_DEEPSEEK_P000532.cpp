Here is the code for the problem:

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int time_needed(int n, vector<int> &tickets, int k) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++) {
        q.push(tickets[i]);
    }
    int time = 0;
    while (!q.empty()) {
        if (q.top() == tickets[k]) {
            q.pop();
            if (q.empty()) {
                break;
            }
            q.pop();
            k = (k + 1) % n;
            time++;
        } else {
            q.push(q.top() - 1);
            k = (k + 1) % n;
            time++;
        }
    }
    return time;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> tickets(n);
    for (int i = 0; i < n; i++) {
        cin >> tickets[i];
    }
    cout << time_needed(n, tickets, k);
    return 0;
}

This program reads the number of people and the index of the person who needs to buy the tickets from the input, then reads the number of tickets each person needs. The program then uses the `time_needed` function to calculate and print the number of seconds needed to buy all tickets.