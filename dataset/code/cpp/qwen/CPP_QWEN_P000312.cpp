#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    string v1, v2;
    cin >> v1 >> v2;
    vector<int> rev1, rev2;
    stringstream ss1(v1), ss2(v2);
    string token;
    while (getline(ss1, token, '.')) rev1.push_back(stoi(token));
    while (getline(ss2, token, '.')) rev2.push_back(stoi(token));
    int i = 0;
    while (i < max(rev1.size(), rev2.size())) {
        int v1 = i < rev1.size() ? rev1[i] : 0;
        int v2 = i < rev2.size() ? rev2[i] : 0;
        if (v1 < v2) { cout << -1 << endl; return 0; }
        if (v1 > v2) { cout << 1 << endl; return 0; }
        i++;
    }
    cout << 0 << endl;
    return 0;
}
