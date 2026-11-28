#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, threshold; cin >> n >> threshold;
    vector<int> stock(n);
    for(int i=0; i<n; i++) cin >> stock[i];
    for(int i=0; i<n; i++) if(stock[i] < threshold) cout << i+1 << " ";
    cout << endl;
    return 0;
}
