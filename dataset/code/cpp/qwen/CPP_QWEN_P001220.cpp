#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> catalan(n + 1, 0);
    catalan[0] = 1;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            catalan[i] += catalan[j] * catalan[i - 1 - j];
        }
    }
    
    cout << catalan[n] << endl;
    return 0;
}
