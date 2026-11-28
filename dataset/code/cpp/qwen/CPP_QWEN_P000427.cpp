#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; int min_price; cin >> n >> min_price;
    vector<int> prices(n);
    for(int i=0; i<n; i++) cin >> prices[i];
    for(int i=0; i<n; i++) if(prices[i] >= min_price) cout << i+1 << " ";
    cout << endl;
    return 0;
}
