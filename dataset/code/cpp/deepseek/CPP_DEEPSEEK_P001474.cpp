#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void findQuadruplets(vector<int>& arr, int target, vector<vector<int>>& result, vector<int>& current, int start) {
    int n = arr.size();
    if (current.size() == 4 && target == accumulate(current.begin(), current.end(), 0)) {
        result.push_back(current);
        return;
    }
    for (int i = start; i < n; i++) {
        if (i > start && arr[i] == arr[i - 1]) continue; 
        current.push_back(arr[i]);
        findQuadruplets(arr, target, result, current, i + 1);
        current.pop_back();
    }
}

int main() {
    int n, target;
    vector<int> arr;
    vector<vector<int>> result;

    cin >> n >> target;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end()); 
    vector<int> current;
    findQuadruplets(arr, target, result, current, 0);

    for (auto& quadruplet : result) {
        for (int& num : quadruplet) {
            cout << num << ' ';
        }
        cout << '\n';
    }

    return 0;
}