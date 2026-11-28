#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    for (int i = 0; i < n; ++i) cin >> arr1[i];
    for (int i = 0; i < m; ++i) cin >> arr2[i];
    
    unordered_map<int, int> order;
    for (int i = 0; i < m; ++i) order[arr2[i]] = i;
    
    vector<int> inOrder, notInOrder;
    for (int x : arr1) {
        if (order.find(x) != order.end()) inOrder.push_back(x);
        else notInOrder.push_back(x);
    }
    
    sort(inOrder.begin(), inOrder.end(), [&](int a, int b) {
        return order[a] < order[b];
    });
    
    sort(notInOrder.begin(), notInOrder.end());
    
    inOrder.insert(inOrder.end(), notInOrder.begin(), notInOrder.end());
    
    for (int x : inOrder) cout << x << " ";
    cout << endl;
    
    return 0;
}
