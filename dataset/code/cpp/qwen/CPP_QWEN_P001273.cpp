#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> barcodes(n);
    for (int i = 0; i < n; ++i) cin >> barcodes[i];
    
    unordered_map<int, int> freq;
    for (int b : barcodes) freq[b]++;
    
    priority_queue<pair<int, int>> pq;
    for (auto& p : freq) {
        pq.push({p.second, p.first});
    }
    
    vector<int> result;
    pair<int, int> prev = {-1, -1};
    
    while (!pq.empty()) {
        auto [count, val] = pq.top(); pq.pop();
        result.push_back(val);
        count--;
        
        if (prev.first > 0) {
            pq.push(prev);
        }
        
        prev = {count, val};
    }
    
    for (int r : result) {
        cout << r << " ";
    }
    cout << endl;
    
    return 0;
}
