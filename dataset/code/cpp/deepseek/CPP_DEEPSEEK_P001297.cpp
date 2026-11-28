#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr1(n);
    vector<int> arr2(n);

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    sort(arr2.begin(), arr2.end());

    int max1 = 0, max2 = 0, max3 = 0;

    for (int i = 0; i < n; i++) {
        if (arr1[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = arr1[i];
        } else if (arr1[i] > max2) {
            max3 = max2;
            max2 = arr1[i];
        } else if (arr1[i] > max3) {
            max3 = arr1[i];
        }
    }

    int result = max1 + max2 + max3;

    max1 = max2 = max3 = 0;

    for (int i = 0; i < n; i++) {
        if (arr2[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = arr2[i];
        } else if (arr2[i] > max2) {
            max3 = max2;
            max2 = arr2[i];
        } else if (arr2[i] > max3) {
            max3 = arr2[i];
        }
    }

    result = max(result, max1 + max2 + max3);

    cout << result;

    return 0;
}