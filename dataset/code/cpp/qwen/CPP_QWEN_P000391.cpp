#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> names(n);
    vector<double> gpas(n);
    for (int i = 0; i < n; i++) cin >> names[i] >> gpas[i];
    double min_gpa;
    cin >> min_gpa;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (gpas[i] >= min_gpa) { cout << names[i] << " " << gpas[i] << endl; found = true; }
    }
    if (!found) cout << "No Students Found" << endl;
    return 0;
}
