#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    vector<int> arr1(M);
    vector<int> arr2(N);

    for (int i = 0; i < M; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> arr2[i];
    }

    vector<int> union_arr(M + N);

    merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), union_arr.begin());

    for (int i = 0; i < union_arr.size(); i++) {
        cout << union_arr[i] << " ";
    }

    return 0;
}