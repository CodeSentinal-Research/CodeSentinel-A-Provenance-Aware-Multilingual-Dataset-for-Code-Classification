#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> diff(n);
    for (int i = 0; i < n; ++i) cin >> diff[i];
    
    vector<long long> original(n);
    original[0] = diff[0];
    for (int i = 1; i < n; ++i) {
        original[i] = original[i-1] + diff[i];
    }
    
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << original[i];
    }
    cout << endl;
    return 0;
}
