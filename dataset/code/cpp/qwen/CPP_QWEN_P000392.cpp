#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> files(n);
    for (int i = 0; i < n; i++) cin >> files[i];
    string ext;
    cin >> ext;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (files[i].size() >= ext.size() && files[i].substr(files[i].size() - ext.size()) == ext) {
            cout << files[i] << endl; found = true;
        }
    }
    if (!found) cout << "No Files Found" << endl;
    return 0;
}
