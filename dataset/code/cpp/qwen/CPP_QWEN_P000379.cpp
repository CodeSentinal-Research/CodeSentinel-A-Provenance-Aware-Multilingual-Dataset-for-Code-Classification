#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> trains(n), dests(n);
    for (int i = 0; i < n; i++) cin >> trains[i] >> dests[i];
    int q;
    cin >> q;
    while (q--) {
        string train;
        cin >> train;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (trains[i] == train) { cout << trains[i] << " " << dests[i] << endl; found = true; break; }
        }
        if (!found) cout << "Train Not Found" << endl;
    }
    return 0;
}
