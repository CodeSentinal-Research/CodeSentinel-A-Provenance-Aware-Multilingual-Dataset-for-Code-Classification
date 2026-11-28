#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string pattern;
    cin >> pattern;
    int n = pattern.length() + 1;
    
    vector<int> result(n);
    int low = 1, high = n;
    
    for (int i = 0; i < n - 1; ++i) {
        if (pattern[i] == 'I') {
            result[i] = low++;
        } else {
            result[i] = high--;
        }
    }
    result[n - 1] = low;
    
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;
    return 0;
}
