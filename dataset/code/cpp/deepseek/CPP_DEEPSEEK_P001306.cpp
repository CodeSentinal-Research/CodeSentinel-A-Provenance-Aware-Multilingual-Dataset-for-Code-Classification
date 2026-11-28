#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> sizes(N);
    for (int i = 0; i < N; i++) {
        cin >> sizes[i];
    }

    int total = 0;
    while (N > 1) {
        sort(sizes.begin(), sizes.end());
        int mergeSize = sizes[0] + sizes[1];
        total += mergeSize;
        sizes.erase(sizes.begin(), sizes.begin() + 2);
        N -= 2;
    }

    cout << total << endl;

    return 0;
}