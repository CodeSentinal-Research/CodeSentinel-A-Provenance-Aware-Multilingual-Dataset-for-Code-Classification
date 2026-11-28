#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> arr1(a);
    for(int i = 0; i < a; i++) {
        cin >> arr1[i];
    }

    vector<int> arr2(b);
    for(int i = 0; i < b; i++) {
        cin >> arr2[i];
    }

    vector<int> arr3(c);
    for(int i = 0; i < c; i++) {
        cin >> arr3[i];
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    sort(arr3.begin(), arr3.end());

    vector<int> common;

    set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(common));
    sort(common.begin(), common.end());

    set_intersection(common.begin(), common.end(), arr3.begin(), arr3.end(), back_inserter(common));
    sort(common.begin(), common.end());

    print_vector(common);

    return 0;
}
This code first takes three integers `a`, `b`, and `c` which represent the sizes of the three arrays. Then it takes `a` integers for the first array, `b` for the second array, and `c` for the third array. 

The arrays are sorted in increasing order. The program then finds the common elements in the three sorted arrays and prints them in sorted order.