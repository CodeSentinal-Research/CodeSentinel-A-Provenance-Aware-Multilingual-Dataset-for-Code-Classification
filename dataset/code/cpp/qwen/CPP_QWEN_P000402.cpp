#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; string dest; cin >> n >> dest;
    vector<string> destinations(n);
    for(int i=0; i<n; i++) cin >> destinations[i];
    for(int i=0; i<n; i++) if(destinations[i] == dest) cout << i+1 << " ";
    cout << endl;
    return 0;
}
