Here is the C++ code for the problem:

#include <iostream>
#include <vector>
using namespace std;

int countWindowsWithAllPositiveNumbers(int N, int K, vector<int>& arr) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] > 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int result = countWindowsWithAllPositiveNumbers(N, K, arr);
    cout << result << endl;
    return 0;
}
This program reads the size of the array N and the window size K, then reads N integers into an array. It then counts the number of positive integers in the array, which is printed out.