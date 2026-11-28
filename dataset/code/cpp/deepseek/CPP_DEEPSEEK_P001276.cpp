#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxDistToClosest(vector<int>& seats) {
    int N = seats.size();
    vector<int> dist(N, -1);
    int i = 0, j = N - 1;
    while (i < N && seats[i] == 0) ++i; 
    int left = i;
    while (j > 0 && seats[j] == 0) --j; 
    int right = N - j;
    int maxDist = max(left, right);
    if (left - i >= 2) {
        int mid = (left - i - 1) / 2;
        maxDist = max(maxDist, mid);
    }
    if (right - j >= 2) {
        int mid = (right - j - 1) / 2;
        maxDist = max(maxDist, mid);
    }
    return maxDist;
}

int main() {
    int N;
    cin >> N;
    vector<int> seats(N);
    for (int i = 0; i < N; ++i) {
        cin >> seats[i];
    }
    cout << maxDistToClosest(seats);
    return 0;
}