#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int n; string name; cin >> n >> name;
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    vector<string> contacts(n);
    for(int i=0; i<n; i++) { cin >> contacts[i]; transform(contacts[i].begin(), contacts[i].end(), contacts[i].begin(), ::tolower); }
    for(int i=0; i<n; i++) if(contacts[i] == name) cout << i+1 << " ";
    cout << endl;
    return 0;
}
