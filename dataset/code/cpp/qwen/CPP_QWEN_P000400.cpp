#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> names(n);
    vector<int> sals(n);
    for (int i = 0; i < n; i++) cin >> names[i] >> sals[i];
    int min_s, max_s;
    cin >> min_s >> max_s;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (sals[i] >= min_s && sals[i] <= max_s) { cout << names[i] << " " << sals[i] << endl; found = true; }
    }
    if (!found) cout << "No Employees Found" << endl;
    return 0;
}
