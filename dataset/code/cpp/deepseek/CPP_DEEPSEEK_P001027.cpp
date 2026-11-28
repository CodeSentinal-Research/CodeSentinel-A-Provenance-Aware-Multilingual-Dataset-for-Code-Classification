#include <iostream>
#include <queue>
using namespace std;

void printLevelOrder(int arr[], int n) {
    if (n == 0) {
        return;
    }

    queue<int> q;

    q.push(arr[0]);

    int currentCount = 1;
    int nextCount = 0;

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();

        if (currentCount < n) {
            q.push(arr[currentCount]);
            currentCount++;
        }

        if (currentCount == n) {
            currentCount = 0;
            nextCount = currentCount + 1;
        }

        if (nextCount < n) {
            q.push(arr[nextCount]);
            nextCount++;
        }
    }
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printLevelOrder(arr, n);

    return 0;
}