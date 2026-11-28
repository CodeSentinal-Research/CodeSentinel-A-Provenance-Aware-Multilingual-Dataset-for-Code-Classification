#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rearrange(vector<int>& arr) {
    vector<int> pos, neg;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] < 0) {
            neg.push_back(arr[i]);
        } else {
            pos.push_back(arr[i]);
        }
    }
    arr.clear();
    while(!neg.empty() && !pos.empty()) {
        arr.push_back(neg.back());
        neg.pop_back();
        arr.push_back(pos.back());
        pos.pop_back();
    }
    while(!neg.empty()) {
        arr.push_back(neg.back());
        neg.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    rearrange(arr);
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}