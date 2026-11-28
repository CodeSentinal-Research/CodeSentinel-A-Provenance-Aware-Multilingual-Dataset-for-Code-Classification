#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> flights(n), dests(n);
    for (int i = 0; i < n; i++) cin >> flights[i] >> dests[i];
    int q;
    cin >> q;
    while (q--) {
        string flight;
        cin >> flight;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (flights[i] == flight) { cout << flights[i] << " " << dests[i] << endl; found = true; break; }
        }
        if (!found) cout << "Flight Not Found" << endl;
    }
    return 0;
}
