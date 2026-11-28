#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> list1(n), list2(m);
    for (int i = 0; i < n; ++i) cin >> list1[i];
    for (int i = 0; i < m; ++i) cin >> list2[i];
    
    unordered_map<string, int> freq1, freq2;
    for (const string& s : list1) freq1[s]++;
    for (const string& s : list2) freq2[s]++;
    
    int count = 0;
    for (auto& p : freq1) {
        if (p.second == 1 && freq2[p.first] == 1) {
            count++;
        }
    }
    
    cout << count << endl;
    return 0;
}
