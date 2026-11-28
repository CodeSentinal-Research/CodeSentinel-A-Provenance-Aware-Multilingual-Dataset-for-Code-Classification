#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ids(n), active(n);
    for (int i = 0; i < n; i++) cin >> ids[i] >> active[i];
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (active[i]) { cout << ids[i] << endl; found = true; }
    }
    if (!found) cout << "No Active Users" << endl;
    return 0;
}
