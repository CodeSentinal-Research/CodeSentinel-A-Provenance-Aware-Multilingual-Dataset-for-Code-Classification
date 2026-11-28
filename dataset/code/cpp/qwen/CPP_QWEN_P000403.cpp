#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; string station; cin >> n >> station;
    vector<string> stations(n);
    for(int i=0; i<n; i++) cin >> stations[i];
    for(int i=0; i<n; i++) if(stations[i] == station) cout << i+1 << " ";
    cout << endl;
    return 0;
}
