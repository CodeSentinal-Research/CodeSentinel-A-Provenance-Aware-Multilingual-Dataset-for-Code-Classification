#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify(vector<int>& a, int i, int n) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < n && a[left] < a[smallest]) smallest = left;
    if(right < n && a[right] < a[smallest]) smallest = right;
    
    if(smallest != i) {
        swap(a[i], a[smallest]);
        heapify(a, smallest, n);
    }
}

void buildHeap(vector<int>& a, int n) {
    for(int i = n/2 - 1; i >= 0; i--) heapify(a, i, n);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int replace;
    cin >> replace;
    
    a[0] = replace;
    
    buildHeap(a, n);
    
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    
    return 0;
}