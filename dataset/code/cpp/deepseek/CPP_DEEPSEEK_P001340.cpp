#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int max_difference = arr[N - 1] - arr[0];
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int difference = arr[j] - arr[i];
            if(difference > max_difference) {
                max_difference = difference;
            }
        }
    }
    cout << max_difference;
    return 0;
}
This C++ code first reads the number of children and cookies, and then reads the number of cookies in each bag. The bags are sorted in ascending order and the maximum difference is calculated between the maximum and minimum cookies in the bags. This difference is printed as the minimum possible unfairness.