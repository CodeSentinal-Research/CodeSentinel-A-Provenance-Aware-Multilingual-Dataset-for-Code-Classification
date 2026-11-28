#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ids(n);
    vector<string> status(n);
    for (int i = 0; i < n; i++) cin >> ids[i] >> status[i];
    string q;
    cin >> q;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (status[i] == q) { cout << ids[i] << " " << status[i] << endl; found = true; }
    }
    if (!found) cout << "No Orders Found" << endl;
    return 0;
}
