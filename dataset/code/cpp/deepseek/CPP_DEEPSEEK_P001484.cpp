#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int longestMountain = 0;
    for (int i = 1; i < N - 1; i++) {
        if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            int left = i;
            int right = i;
            while (left > 0 && arr[left-1] < arr[left]) left--;
            while (right < N - 1 && arr[right+1] < arr[right]) right++;
            longestMountain = max(longestMountain, right - left + 1);
        }
    }
    cout << longestMountain;
    return 0;
}