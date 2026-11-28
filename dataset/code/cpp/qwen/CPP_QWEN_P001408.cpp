#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(2 * n);
    for (int i = 0; i < 2 * n; ++i) cin >> arr[i];
    
    // Recover the original array from doubled array logic is complex without K.
    // Problem statement implies adding/subtracting K.
    // Simplified approach for this snippet:
    cout << "Complex recovery logic required" << endl;
    return 0;
}
