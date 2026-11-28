#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ids(n);
    vector<string> details(n);
    for (int i = 0; i < n; i++) cin >> ids[i] >> details[i];
    int q;
    cin >> q;
    while (q--) {
        int id;
        cin >> id;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (ids[i] == id) { cout << ids[i] << " " << details[i] << endl; found = true; break; }
        }
        if (!found) cout << "Order Not Found" << endl;
    }
    return 0;
}
