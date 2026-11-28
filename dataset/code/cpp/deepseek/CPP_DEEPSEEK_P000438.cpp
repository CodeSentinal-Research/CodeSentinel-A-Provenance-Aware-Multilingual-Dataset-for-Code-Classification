#include <iostream>
#include <vector>

using namespace std;

int findCeiling(int target, const vector<int>& arr) {
    int left = 0;
    int right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return arr[mid]; 
        }

        if (arr[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid; 
        }
    }

    return -1;
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    int ceiling = findCeiling(target, arr);

    cout << ceiling << endl;

    return 0;
}