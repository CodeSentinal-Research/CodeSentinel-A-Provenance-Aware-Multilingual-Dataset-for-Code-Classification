#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; int current_date; cin >> n >> current_date;
    vector<int> expiry(n);
    for(int i=0; i<n; i++) cin >> expiry[i];
    for(int i=0; i<n; i++) if(expiry[i] < current_date) cout << i+1 << " ";
    cout << endl;
    return 0;
}
