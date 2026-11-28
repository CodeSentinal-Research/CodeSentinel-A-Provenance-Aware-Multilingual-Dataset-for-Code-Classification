#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> heap(n);
    for (int i = 0; i < n; i++) {
        cin >> heap[i];
    }
    int i;
    cin >> i;
    sort(heap.begin(), heap.end());
    for (int j = 0; j < i; j++) {
        heap.erase(heap.begin());
    }
    for (int k = 0; k < heap.size(); k++) {
        cout << heap[k] << " ";
    }
    return 0;
}