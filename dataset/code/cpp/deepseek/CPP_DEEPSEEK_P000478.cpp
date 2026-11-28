#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    
    vector<int> stalls(N);
    for (int i = 0; i < N; i++) {
        cin >> stalls[i];
    }
    
    sort(stalls.begin(), stalls.end());
    
    int low = 1;
    int high = stalls[N - 1] - stalls[0];
    
    while (low < high) {
        int mid = (low + high) / 2;
        
        if (CanPlaceCows(stalls, N, C, mid)) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    cout << high - 1;
    
    return 0;
}

In this code, the binary search is performed to find the largest minimum distance between cows. The binary search is done on the range of possible minimum distances (1 to the difference between the last and the first stall). For each mid value, a check is done if it is possible to place cows of distance mid at least once. If it is possible, the binary search is narrowed down to the right half, otherwise, the search is narrowed down to the left half. The largest possible minimum distance is then printed out.