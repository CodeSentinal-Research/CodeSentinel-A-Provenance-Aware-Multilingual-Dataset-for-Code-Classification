#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ids(n), available(n);
    for (int i = 0; i < n; i++) cin >> ids[i] >> available[i];
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (available[i]) { cout << ids[i] << endl; found = true; }
    }
    if (!found) cout << "No Rooms Available" << endl;
    return 0;
}
