Here's a simple C++ solution for the problem:

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool valid(vector<int>& pos, int m, int mid, int maxPos) {
    int count = 1, last = pos[0];
    for (int i = 1; i < pos.size(); i++) {
        if (pos[i] - last >= mid) {
            last = pos[i];
            count++;
            if (count == m) return true;
        }
    }
    return false;
}

int binarySearch(vector<int>& pos, int m, int maxPos) {
    int low = 0, high = maxPos;
    while (low < high) {
        int mid = (low + high) / 2;
        if (valid(pos, m, mid, maxPos)) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return high - 1;
}

int main() {
    int n, m, maxPos;
    cin >> n >> m >> maxPos;
    maxPos++;
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    sort(pos.begin(), pos.end());
    cout << binarySearch(pos, m, maxPos) << endl;
    return 0;
}

This code first reads the input and sorts the positions of the balls. Then it uses binary search to find the maximum minimum distance. The valid function checks if it's possible to place m balls into the baskets with a minimum distance of mid. If it's possible, it increases the search space to the right (i.e., `high = mid`) otherwise, it decreases the search space to the left (i.e., `low = mid + 1`). The binarySearch function returns the maximum minimum distance. The main function reads the input and calls the binarySearch function.