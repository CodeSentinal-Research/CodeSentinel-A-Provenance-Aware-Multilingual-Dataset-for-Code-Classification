#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    
    unordered_set<int> set1;
    vector<int> arr1(M);
    
    for (int i = 0; i < M; i++) {
        cin >> arr1[i];
        set1.insert(arr1[i]);
    }
    
    vector<int> arr2(N);
    
    for (int i = 0; i < N; i++) {
        cin >> arr2[i];
        set1.insert(arr2[i]);
    }
    
    for (int num : arr1) {
        if (set1.count(num)) {
            cout << num << " ";
            set1.erase(num);
        }
    }
    
    return 0;
}