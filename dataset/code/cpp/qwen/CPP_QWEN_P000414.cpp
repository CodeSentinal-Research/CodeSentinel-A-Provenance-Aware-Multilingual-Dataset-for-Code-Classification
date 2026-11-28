#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; int budget; cin >> n >> budget;
    vector<int> prices(n); vector<bool> avail(n);
    for(int i=0; i<n; i++) { cin >> prices[i] >> avail[i]; }
    for(int i=0; i<n; i++) if(avail[i] && prices[i] <= budget) cout << i+1 << " ";
    cout << endl;
    return 0;
}
