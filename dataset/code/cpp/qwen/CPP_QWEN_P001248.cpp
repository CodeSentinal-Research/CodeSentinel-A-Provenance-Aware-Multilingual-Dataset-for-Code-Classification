#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, limit;
    cin >> n >> limit;
    vector<int> weights(n);
    for (int i = 0; i < n; ++i) cin >> weights[i];
    
    sort(weights.begin(), weights.end());
    
    int boats = 0;
    int left = 0, right = n - 1;
    
    while (left <= right) {
        if (weights[left] + weights[right] <= limit) {
            left++;
        }
        right--;
        boats++;
    }
    
    cout << boats << endl;
    return 0;
}
