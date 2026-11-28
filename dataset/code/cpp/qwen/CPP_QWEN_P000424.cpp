#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
int main() {
    int n; cin >> n;
    vector<string> emails(n);
    map<string, int> count;
    for(int i=0; i<n; i++) { cin >> emails[i]; count[emails[i]]++; }
    for(int i=0; i<n; i++) if(count[emails[i]] > 1) cout << i+1 << " ";
    cout << endl;
    return 0;
}
