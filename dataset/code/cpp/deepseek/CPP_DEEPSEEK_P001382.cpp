#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> arr1(N);
    for (int& num : arr1) {
        cin >> num;
    }

    vector<int> arr2(M);
    for (int& num : arr2) {
        cin >> num;
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    vector<int> intersection;
    set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(intersection));

    for (int num : intersection) {
        cout << num << " ";
    }

    return 0;
}