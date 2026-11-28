#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> arr(N);
    for (int& num : arr) {
        cin >> num;
    }
    
    sort(arr.begin(), arr.end());
    
    for (int& num : arr) {
        num *= num;
    }
    
    sort(arr.begin(), arr.end());
    
    for (int num : arr) {
        cout << num << " ";
    }
    
    return 0;
}