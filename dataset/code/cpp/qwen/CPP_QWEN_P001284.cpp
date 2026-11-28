#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> top(n), bottom(n);
    for (int i = 0; i < n; ++i) cin >> top[i];
    for (int i = 0; i < n; ++i) cin >> bottom[i];
    
    int rotations = INT_MAX;
    
    // Try making all tops equal to top[0] or bottom[0]
    for (int target : {top[0], bottom[0]}) {
        int rotTop = 0, rotBottom = 0;
        bool possible = true;
        
        for (int i = 0; i < n; ++i) {
            if (top[i] != target && bottom[i] != target) {
                possible = false;
                break;
            }
            if (top[i] != target) rotTop++;
            if (bottom[i] != target) rotBottom++;
        }
        
        if (possible) {
            rotations = min(rotations, min(rotTop, rotBottom));
        }
    }
    
    cout << (rotations == INT_MAX ? -1 : rotations) << endl;
    return 0;
}
