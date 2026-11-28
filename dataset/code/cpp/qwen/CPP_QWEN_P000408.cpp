#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; string domain; cin >> n >> domain;
    vector<string> emails(n);
    for(int i=0; i<n; i++) cin >> emails[i];
    for(int i=0; i<n; i++) if(emails[i].find(domain) != string::npos) cout << i+1 << " ";
    cout << endl;
    return 0;
}
