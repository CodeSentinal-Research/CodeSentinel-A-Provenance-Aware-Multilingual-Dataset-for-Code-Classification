#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> majorityElement(int arr[], int n) {
    unordered_map<int, int> count;
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    vector<int> res;
    for (auto i : count) {
        if (i.second > n / 3) {
            res.push_back(i.first);
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> res = majorityElement(arr, n);
    for (int i : res) {
        cout << i << " ";
    }
    return 0;
}