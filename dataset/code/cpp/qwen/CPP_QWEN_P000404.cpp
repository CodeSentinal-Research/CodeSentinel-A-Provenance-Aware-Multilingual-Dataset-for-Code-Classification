#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; string spec; cin >> n >> spec;
    vector<string> specs(n);
    for(int i=0; i<n; i++) cin >> specs[i];
    for(int i=0; i<n; i++) if(specs[i] == spec) cout << i+1 << " ";
    cout << endl;
    return 0;
}
