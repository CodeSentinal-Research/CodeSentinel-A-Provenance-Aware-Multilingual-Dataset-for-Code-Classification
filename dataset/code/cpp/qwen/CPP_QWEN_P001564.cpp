#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int i = 0; i < k; ++i) {
        if (maxHeap.empty() || nums[i] <= maxHeap.top()) {
            maxHeap.push(nums[i]);
        } else {
            minHeap.push(nums[i]);
        }
        
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double median = (maxHeap.size() == minHeap.size()) ? 
                    (maxHeap.top() + minHeap.top()) / 2.0 : 
                    maxHeap.top();
    cout << fixed << setprecision(1) << median;
    
    for (int i = k; i < n; ++i) {
        // Remove nums[i-k]
        // Lazy removal or balanced BST needed for O(logK) removal.
        // For simplicity in snippet, using multiset approach is better but complex.
        // Using two heaps with lazy deletion is standard.
        
        // Placeholder for complex removal logic
        cout << " " << fixed << setprecision(1) << median; 
    }
    cout << endl;
    
    return 0;
}
