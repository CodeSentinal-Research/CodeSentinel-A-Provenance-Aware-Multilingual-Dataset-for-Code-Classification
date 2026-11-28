#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; string artist; cin >> n >> artist;
    vector<string> artists(n);
    for(int i=0; i<n; i++) cin >> artists[i];
    for(int i=0; i<n; i++) if(artists[i] == artist) cout << i+1 << " ";
    cout << endl;
    return 0;
}
