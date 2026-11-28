#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<int> arr1(n1), arr2(n2), arr3(n3);

    for (int i = 0; i < n1; ++i)
        cin >> arr1[i];
    for (int i = 0; i < n2; ++i)
        cin >> arr2[i];
    for (int i = 0; i < n3; ++i)
        cin >> arr3[i];

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    sort(arr3.begin(), arr3.end());

    set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(),
                      arr2.begin());

    cout << "Common Elements are: ";
    for (auto i = arr2.begin(); i != arr2.end(); ++i)
        cout << *i << " ";
    return 0;
}